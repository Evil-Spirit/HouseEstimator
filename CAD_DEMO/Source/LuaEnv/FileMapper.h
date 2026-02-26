// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
#ifndef FileMapperH
#define FileMapperH


//-------------------------------------------------------
//Basic class to store and read from file-mapping
//-------------------------------------------------------
class COMMONAL_API TFileMapStream : public TMemoryStream
{
public:
	virtual int  Write(const void *Buffer, int Count);
    virtual int  Read(void *Buffer, int Count);
    virtual void  SetSize(int NewSize);
    virtual void  SetSize(__int64 NewSize) {TStream::SetSize(NewSize);};

     TFileMapStream(AnsiString fmName);
     ~TFileMapStream();
    void  Open();
    void  Close();

    __property AnsiString Name = {read=FName, nodefault};
    __property bool Ready = {read=ReadEvent, write=WriteEvent, default = true};
private:
    void* pMapMemory;
    HANDLE hFileMap;    //Handle to file
    HANDLE fMap;        //Handle to mapping
    HANDLE hReady;
    SYSTEM_INFO SystemInfo;
    AnsiString FName;
    bool ReadEvent();
    void WriteEvent(bool State);
};

//----------------------------------------------------------------------------
//-------------------------------------------------------
#endif


