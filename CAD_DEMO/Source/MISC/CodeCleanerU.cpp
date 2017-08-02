//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <conio.h>
#include <stdio.h>
#include <dir.h>

//---------------------------------------------------------------------------

#pragma argsused

int ClearRecursive(const AnsiString& Dir,int Depth)
{
    int Total = 0;
    AnsiString Str = AnsiString::StringOfChar(' ',Depth*2);
    Str = Str + AnsiString("Start Directory - ") + Dir;
    puts(Str.c_str());
    TSearchRec F;
    if (FindFirst(Dir+AnsiString("\\*.*"), faReadOnly | faHidden | faAnyFile, F)==0)
    {
        do
        {
            if ( F.Attr & faDirectory )
            {
                if ( F.Name != ".." && F.Name != ".")
                    Total += ClearRecursive(Dir+AnsiString("\\")+F.Name,Depth+1);
            }                    
            else if ( ExtractFileExt(F.Name).Pos("~") == 2 )
            {
                Str = AnsiString::StringOfChar(' ',(Depth+1)*2);
                Str = Str + F.Name + AnsiString(" - Deleted!");
                puts(Str.c_str());
                DeleteFile(Dir + AnsiString("\\") + F.Name);
                Total++;
            }
        }
        while (FindNext(F) == 0);
        FindClose(F);
    }
    return Total;
}

int main(int argc, char* argv[])
{
    int Total = ClearRecursive(GetCurrentDir(),0);
    puts( (IntToStr(Total)+AnsiString(" files deleted! Press Any Key.")).c_str());
    getch();
    return 0;
}
//---------------------------------------------------------------------------
 