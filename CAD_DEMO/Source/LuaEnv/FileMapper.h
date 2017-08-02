#ifndef FileMapperH
#define FileMapperH


//-------------------------------------------------------
//Basic class to store and read from file-mapping
//-------------------------------------------------------
class COMMONAL_API TFileMapStream : public TMemoryStream
{
public:
	virtual int __fastcall Write(const void *Buffer, int Count);
    virtual int __fastcall Read(void *Buffer, int Count);
    virtual void __fastcall SetSize(int NewSize);
    virtual void __fastcall SetSize(__int64 NewSize) {TStream::SetSize(NewSize);};

    __fastcall TFileMapStream(AnsiString fmName);
    __fastcall ~TFileMapStream();
    void __fastcall Open();
    void __fastcall Close();

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


