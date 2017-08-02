#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "FileMapper.h"

#include "LuaModuleV.h"
#include "LuaEnvV.h"
#include "LuaStationV.h"
#include "LuaEditorV.h"
#include "QuckList.h"
#include "MDILuaEditorV.h"

#pragma package(smart_init)
//////////////////////////////////////////////////////////////////////////
//New Filemaping object on TMemoryStream
//////////////////////////////////////////////////////////////////////////

__fastcall TFileMapStream::TFileMapStream(AnsiString fmName)
    :TMemoryStream()
{   
    SECURITY_ATTRIBUTES lpSecAttrFile;
    SECURITY_ATTRIBUTES lpSecAttrEvent;

    lpSecAttrFile.nLength=sizeof(SECURITY_ATTRIBUTES);
    lpSecAttrFile.lpSecurityDescriptor=NULL;
    lpSecAttrFile.bInheritHandle=true;

    lpSecAttrEvent.nLength=sizeof(SECURITY_ATTRIBUTES);
    lpSecAttrEvent.lpSecurityDescriptor=NULL;
    lpSecAttrEvent.bInheritHandle=true;

    hReady=CreateEvent(
        &lpSecAttrEvent,	// pointer to security attributes
        true,	// flag for manual-reset event
        false,	// flag for initial state
        AnsiString(fmName+".event").c_str()	// pointer to event-object name
    );
    if (GetLastError()==ERROR_ALREADY_EXISTS)
        hReady=OpenEvent(EVENT_ALL_ACCESS | SYNCHRONIZE	,true,AnsiString(fmName+".event").c_str());
    if (!hReady) DisplayMessage(GetLastError());

    hFileMap = CreateFile(
        AnsiString(fmName+".map").c_str(),	            // pointer to name of the file
        GENERIC_WRITE | GENERIC_READ,	// access (read-write) mode
        FILE_SHARE_READ | FILE_SHARE_WRITE,// | FILE_SHARE_DELETE	,// share mode
        &lpSecAttrFile,	                    // pointer to security attributes
        OPEN_ALWAYS,	            // how to create
        0,//FILE_ATTRIBUTE_TEMPORARY | FILE_FLAG_SEQUENTIAL_SCAN | FILE_FLAG_DELETE_ON_CLOSE,	// file attributes
        NULL 	                    // handle to file with attributes to copy
    );
    if (!hFileMap) DisplayMessage(GetLastError());

    int FileSize=GetFileSize(hFileMap,NULL);
    GetSystemInfo(&SystemInfo);
    if (!FileSize) FileSize=SystemInfo.dwAllocationGranularity;

    fMap=CreateFileMapping(
        hFileMap,	                // handle to file to map
        NULL,	                    // optional security attributes
        PAGE_READWRITE,	            // protection for mapping object
        0,	                        // high-order 32 bits of object size
        FileSize,	                        // low-order 32 bits of object size
        fmName.c_str() 	                    // name of file-mapping object
    );
    if (!fMap) DisplayMessage(GetLastError());

    FName = fmName;

    pMapMemory=(void*)MapViewOfFile(
        fMap,	                    // file-mapping object to map into address space
        FILE_MAP_ALL_ACCESS,        // access mode
        0,	                        // high-order 32 bits of file offset
        0,	                        // low-order 32 bits of file offset
        FileSize 	                        // number of bytes to map
    );

    if (!pMapMemory) DisplayMessage(GetLastError());
    SetPointer(pMapMemory,FileSize-1);
}

bool TFileMapStream::ReadEvent()
{
    bool RetState;
    int State = WaitForSingleObject(
        hReady,	// handle of object to wait for
        1 	    // time-out interval in milliseconds
    );
    if (State==WAIT_FAILED) DisplayMessage(GetLastError());
    if (State==WAIT_TIMEOUT) RetState = true;
    if (State==WAIT_OBJECT_0) RetState = false;
    return RetState;
}

void TFileMapStream::WriteEvent(bool State)
{
    bool RetState;
    if (!State) RetState=SetEvent(hReady);
    else RetState=PulseEvent(hReady);
    if (!RetState) DisplayMessage(GetLastError());
}

void __fastcall TFileMapStream::Open()
{
    int FileSize=GetFileSize(hFileMap,NULL);
    if (!FileSize) FileSize=SystemInfo.dwAllocationGranularity;

    if (fMap) return;
    fMap=CreateFileMapping(
        hFileMap,	                // handle to file to map
        NULL,	                    // optional security attributes
        PAGE_READWRITE,	            // protection for mapping object
        0,	                        // high-order 32 bits of object size
        FileSize,	                        // low-order 32 bits of object size
        FName.c_str() 	                    // name of file-mapping object
    );
    if (!fMap) DisplayMessage(GetLastError());
    pMapMemory=(void*)MapViewOfFile(
        fMap,	                    // file-mapping object to map into address space
        FILE_MAP_ALL_ACCESS,        // access mode
        0,	                        // high-order 32 bits of file offset
        0,	                        // low-order 32 bits of file offset
        FileSize 	                        // number of bytes to map
    );

    if (!pMapMemory) DisplayMessage(GetLastError());
    SetPointer(pMapMemory,FileSize-1);
}

void __fastcall TFileMapStream::Close()
{
    if (!fMap) return;
    FlushViewOfFile(pMapMemory,Size);
    UnmapViewOfFile(pMapMemory);
    pMapMemory=NULL;
    CloseHandle(fMap);
    fMap=NULL;
}

int __fastcall TFileMapStream::Write(const void *Buffer, int Count)
{
    int NewSize=Position+Count;
    if (Size<NewSize) Size=NewSize;
    void *CurPos=(void*)((int)pMapMemory+Position);
    memcpy(CurPos, Buffer, Count);
    Position=NewSize;
    return Count;
}

int __fastcall TFileMapStream::Read(void *Buffer, int Count)
{
    int NewSize=Position+Count;
    if (Size<NewSize) Size=NewSize;
    const void *CurPos=(void*)((int)pMapMemory+Position);
    memcpy(Buffer, CurPos, Count);
    Position=NewSize;
    return Count;
}

void __fastcall TFileMapStream::SetSize(int NewSize)
{
    int PageRequest=(NewSize/SystemInfo.dwAllocationGranularity);
    int CurPage=(Size/SystemInfo.dwAllocationGranularity);

    if (PageRequest<=CurPage)
    {
        SetPointer(pMapMemory,NewSize);
        if (Position > NewSize) Position=Seek(0, soFromEnd);
        return;
    }
    else
    {
        FlushViewOfFile(pMapMemory,Size);
        UnmapViewOfFile(pMapMemory);
        CloseHandle(fMap);
        SendMessage(DebugHnd,WM_USER,MSG_FMSTATE,0);
        fMap=CreateFileMapping(
            hFileMap,	                // handle to file to map
            NULL,	                    // optional security attributes
            PAGE_READWRITE,	            // protection for mapping object
            0,	                        // high-order 32 bits of object size
            (PageRequest+1)*(SystemInfo.dwAllocationGranularity),	// low-order 32 bits of object size
            FName.c_str() 	                    // name of file-mapping object
        );
        if (!fMap) DisplayMessage(GetLastError());
        
        pMapMemory=(void*)MapViewOfFile(
            fMap,	                    // file-mapping object to map into address space
            FILE_MAP_ALL_ACCESS,        // access mode
            0,	                        // high-order 32 bits of file offset
            0,	                        // low-order 32 bits of file offset
            (PageRequest+1)*(SystemInfo.dwAllocationGranularity) 	// number of bytes to map
        );
        if (!pMapMemory) DisplayMessage(GetLastError());
        SendMessage(DebugHnd,WM_USER,MSG_FMSTATE,1);
        SetPointer(pMapMemory,NewSize);
    }
}

__fastcall TFileMapStream::~TFileMapStream()
{
    if (fMap)
    {
        UnmapViewOfFile(pMapMemory);
        if (!CloseHandle(fMap)) DisplayMessage(GetLastError());
    }
    if (hFileMap)
        if (!CloseHandle(hFileMap)) DisplayMessage(GetLastError());
    if (hReady)
        if (!CloseHandle(hReady)) DisplayMessage(GetLastError());

}

