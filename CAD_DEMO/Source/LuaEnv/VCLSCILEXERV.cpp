//---------------------------------------------------------------------------

 
#include <vcl.h>
#pragma hdrstop

#include "VCLSCILEXERV.h"
#include "Scintilla.h"
#include "SciLexer.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
HINSTANCE hlexer = 0;
void RegisterVCLSCILEXER()
{
    //загрузка библиотеки Lexer
    if (hlexer==0)
    	hlexer = ::LoadLibrary("SciLexer.DLL");
}

void UnRegisterVCLSCILEXER()
{
    if (hlexer!=0)
        FreeLibrary(hlexer);
}

#pragma startup RegisterVCLSCILEXER
#pragma exit UnRegisterVCLSCILEXER

const char luaKeyWords[] = "and break do else elseif end false for function if "
    "in local nil not or repeat return then true until while";

const char luaBaseF345[] = "_G getfenv getmetatable ipairs loadlib next pairs pcall "
"rawegal rawget rawset require setfenv setmetatable xpcall "
"string table math coroutine io os debug";

const char luaMathStrF345[] = "string.byte string.char string.dump string.find string.len "
"string.lower string.rep string.sub string.upper string.format string.gfind string.gsub "
"table.concat table.foreach table.foreachi table.getn table.sort table.insert table.remove table.setn "
"math.abs math.acos math.asin math.atan math.atan2 math.ceil math.cos math.deg math.exp "
"math.floor math.frexp math.ldexp math.log math.log10 math.max math.min math.mod "
"math.pi math.pow math.rad math.random math.randomseed math.sin math.sqrt math.tan";

const char luaIOOSF345[] = "coroutine.create coroutine.resume coroutine.status "
"coroutine.wrap coroutine.yield "
"io.close io.flush io.input io.lines io.open io.output io.read io.tmpfile io.type io.write "
"io.stdin io.stdout io.stderr "
"os.clock os.date os.difftime os.execute os.exit os.getenv os.remove os.rename "
"os.setlocale os.time os.tmpname";

void TSciLexer::SetAStyle(int style, COLORREF fore, COLORREF back, int size, const char *face) {
	SendEditor(SCI_STYLESETFORE, style, fore);
	SendEditor(SCI_STYLESETBACK, style, back);
	if (size >= 1)
		SendEditor(SCI_STYLESETSIZE, style, size);
	if (face)
		SendEditor(SCI_STYLESETFONT, style, reinterpret_cast<LPARAM>(face));
}

void TSciLexer::InitialiseEditor()
{
    SendEditor(SCI_SETLEXERLANGUAGE,NULL,reinterpret_cast<LPARAM>("lua"));
	SendEditor(SCI_SETLEXER, SCLEX_LUA);
    SendEditor(SCI_SETSTYLEBITS,5,0);
    // set up basic features (iguides on, tab=3, tabs-to-spaces, EOL=CRLF)
    SendEditor(SCI_SETINDENTATIONGUIDES,1,0);
    SendEditor(SCI_SETTABWIDTH,4,0);
    SendEditor(SCI_SETUSETABS,0,0);
    //set up margin and markers
    SendEditor(SCI_SETSTYLEBITS,6);
    SendEditor(SCI_SETMARGINMASKN,1,-13);
    SendEditor(SCI_SETMARGINMASKN,2,12);
    SendEditor(SCI_SETMARGINWIDTHN,1,12);
    SendEditor(SCI_SETMARGINWIDTHN,2,8);
    SendEditor(SCI_SETMARGINSENSITIVEN,1,1);
        //For breakpoint
    SendEditor(SCI_MARKERDEFINE,1,SC_MARK_CIRCLE);
    SendEditor(SCI_MARKERDEFINE,2,SC_MARK_BACKGROUND);
    SendEditor(SCI_MARKERSETBACK,1, clRed);
    SendEditor(SCI_MARKERSETBACK,2, clRed);
        //For current position
    SendEditor(SCI_MARKERDEFINE,4,SC_MARK_SHORTARROW);
    SendEditor(SCI_MARKERDEFINE,8,SC_MARK_BACKGROUND);
    SendEditor(SCI_MARKERSETBACK,4, clGreen);
    SendEditor(SCI_MARKERSETBACK,8,  0x00DDDDDD);
    SendEditor(SCI_MARKERSETFORE,8, clRed);

    //end of margin and markers block
    //AnsiString WordChars="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    //SendEditor(SCI_SETWORDCHARS,0,(long)WordChars.c_str());

    SendEditor(SCI_SETEOLMODE,SC_EOL_CRLF,0);

	SendEditor(SCI_SETKEYWORDS, 0,
		reinterpret_cast<LPARAM>(luaKeyWords));
	SendEditor(SCI_SETKEYWORDS, 1,
		reinterpret_cast<LPARAM>(luaBaseF345));
	SendEditor(SCI_SETKEYWORDS, 2,
		reinterpret_cast<LPARAM>(luaMathStrF345));
	SendEditor(SCI_SETKEYWORDS, 3,
		reinterpret_cast<LPARAM>(luaIOOSF345));

    // Set up the global default style. These attributes are used wherever no explicit choices are made.
	SetAStyle(STYLE_DEFAULT, black, white, 11, "Verdana");
	SendEditor(SCI_STYLECLEARALL);	// Copies global style to all others

    SendEditor(SCI_SETHOTSPOTACTIVEFORE,1,clBlue);
    SendEditor(SCI_SETHOTSPOTACTIVEBACK,1,clWhite);
    SendEditor(SCI_SETHOTSPOTACTIVEUNDERLINE,1);

	const COLORREF red = RGB(0xFF, 0, 0);
	const COLORREF darkGreen = RGB(0, 0x80, 0);
	const COLORREF darkBlue = RGB(0, 0, 0x80);
	const COLORREF Blue = RGB(0, 0, 0xFF);

	// Hypertext default is used for all the document's text
	SetAStyle(SCE_LUA_DEFAULT, black, white, 10, "Courier New");
	SetAStyle(SCE_LUA_COMMENT, darkBlue, white, 10, "Courier New");
	SetAStyle(SCE_LUA_COMMENTLINE, darkBlue, white, 10, "Courier New");
    SendEditor(SCI_STYLESETITALIC, SCE_LUA_COMMENTLINE, 1);
	SetAStyle(SCE_LUA_COMMENTDOC, black, white, 10, "Courier New");
	SetAStyle(SCE_LUA_NUMBER, darkGreen, white, 10, "Courier New");
	SetAStyle(SCE_LUA_WORD, black, white, 10, "Courier New");
    SendEditor(SCI_STYLESETBOLD, SCE_LUA_WORD, 1);
	SetAStyle(SCE_LUA_STRING, darkGreen, white, 10, "Courier New");
	SetAStyle(SCE_LUA_CHARACTER, darkGreen, white, 10, "Courier New");
	SetAStyle(SCE_LUA_LITERALSTRING, darkGreen, white, 10, "Courier New");
	SetAStyle(SCE_LUA_PREPROCESSOR, darkGreen, white, 10, "Courier New");
	SetAStyle(SCE_LUA_OPERATOR, Blue, white, 10, "Courier New");
//    SendEditor(SCI_STYLESETBOLD, SCE_LUA_OPERATOR, 1);
	SetAStyle(SCE_LUA_IDENTIFIER, black, white, 10, "Courier New");
	SetAStyle(SCE_LUA_STRINGEOL, darkGreen, white, 10, "Courier New");
	SetAStyle(SCE_LUA_WORD2, red, white, 10, "Courier New");
	SetAStyle(SCE_LUA_WORD3, Blue, white, 10, "Courier New");
	SetAStyle(SCE_LUA_WORD4, Blue, white, 10, "Courier New");
	SetAStyle(SCE_LUA_WORD5, Blue, white, 10, "Courier New");
	SetAStyle(SCE_LUA_WORD6, Blue, white, 10, "Courier New");
	SetAStyle(SCE_LUA_WORD7, Blue, white, 10, "Courier New");
	SetAStyle(SCE_LUA_WORD8, Blue, white, 10, "Courier New");
	SetAStyle(SCI_BRACEHIGHLIGHT, red, white, 10, "Courier New");
	SetAStyle(SCI_BRACEMATCH, red, white, 10, "Courier New");
}

void __fastcall TSciLexer::CreateParams(Controls::TCreateParams &Params)
{
    TWinControl::CreateParams(Params);
    CreateSubClass(Params, "Scintilla");
    Params.Style = Params.Style | WS_TABSTOP|WS_CHILD| WS_VISIBLE|WS_VSCROLL | WS_HSCROLL;
}

void __fastcall TSciLexer::CreateWnd(void)
{
    TWinControl::CreateWnd();
    InitialiseEditor();
    ::SetFocus(Handle);
    SendEditor(SCI_SETUNDOCOLLECTION, 1);
}

LRESULT TSciLexer::SendEditor(UINT Msg, WPARAM wParam, LPARAM lParam)
{
    return ::SendMessage(Handle, Msg, wParam, lParam);
}

__fastcall TSciLexer::TSciLexer(Classes::TComponent* AOwner)
    :TWinControl(AOwner)
{
}


//---------------------------------------------------------------------------
void TSciLexer::Notify(SCNotification *notification)
{

        if (notification->nmhdr.code == SCN_CHARADDED)
        {
            if (notification->ch == '@')
            {
                notification->ch = '_';
            }
            else if (notification->ch == '\r' || notification->ch == '\n')
            {
                char linebuf[1000];
                int curLine = SendEditor(SCI_LINEFROMPOSITION,SendEditor(SCI_GETCURRENTPOS));
                int lineLength = SendEditor(SCI_LINELENGTH, curLine);
                if (curLine > 0 && lineLength <= 2)
                {
                    int prevLineLength = SendEditor(SCI_LINELENGTH, curLine - 1);
                    if (prevLineLength < sizeof(linebuf))
                    {
                        WORD buflen = sizeof(linebuf);
                        memcpy(linebuf, &buflen, sizeof(buflen));
                        SendEditor(SCI_GETLINE, curLine - 1,reinterpret_cast<LPARAM>(linebuf));
                        linebuf[prevLineLength] = '\0';
                        for (int pos = 0; linebuf[pos]!='\0'; pos++)
                        {
                            if (linebuf[pos] != ' ' && linebuf[pos] != '\t')
                                linebuf[pos] = '\0';
                        }
                        SendEditor(SCI_REPLACESEL, 0, reinterpret_cast<LPARAM>(static_cast<char *>(linebuf)));
                    }
                }
            }
        }
    if (OnNotify)
        OnNotify(this,notification);
}

void _fastcall TSciLexer::WndProc(Messages::TMessage &Message)
{
    switch(Message.Msg)
    {
        case WM_NOTIFY:
        case CN_NOTIFY:
        {
            LPNMHDR lpnmhdr = (LPNMHDR) Message.LParam;
            if(lpnmhdr->hwndFrom==Handle)
            {
                Notify(reinterpret_cast<SCNotification *>(Message.LParam));
            }
            else
                TWinControl::WndProc(Message);
        }break;
        case CN_KEYDOWN:
        {
            if (    Message.WParam == VK_TAB ||
                    Message.WParam == VK_DELETE ||
                    Message.WParam == VK_UP ||
                    Message.WParam == VK_DOWN ||
                    Message.WParam == VK_LEFT ||
                    Message.WParam == VK_RIGHT
                    )
            {
//                SendEditor(WM_KEYDOWN,Message.WParam,Message.LParam);
            }
            else
                TWinControl::WndProc(Message);
        }break;
        default:
            TWinControl::WndProc(Message);
    };
}

void TSciLexer::SetText(const AnsiString& Text)
{
    SendEditor(SCI_CLEARALL);
    SendEditor(SCI_ADDTEXT,Text.Length(),reinterpret_cast<LPARAM>(Text.c_str()));
    SendEditor(SCI_EMPTYUNDOBUFFER);
    //For read-only mode
    if (AnsiString(GetCommandLine()).UpperCase().Pos("DEBUG")!=0)
        SendEditor(SCI_SETREADONLY,1);
}

AnsiString TSciLexer::GetText()
{
    int length;
    length = SendEditor(SCI_GETLENGTH);
    char* buf = new char[length+1];
    SendEditor(SCI_GETTEXT,length+1,reinterpret_cast<LPARAM>(buf));
    AnsiString RET = AnsiString(buf);
    delete buf;
    return(RET);
}

void TSciLexer::Command(int id)
{
	switch (id)
    {
    	case IDM_EDIT_UNDO:
	    	SendEditor(SCI_UNDO);
            break;
	    case IDM_EDIT_REDO:
		    SendEditor(SCI_REDO);
	    	break;
    	case IDM_EDIT_CUT:
	    	SendEditor(SCI_CUT);
		    break;
    	case IDM_EDIT_COPY:
	    	SendEditor(SCI_COPY);
		    break;
    	case IDM_EDIT_PASTE:
	    	SendEditor(SCI_PASTE);
		    break;
    	case IDM_EDIT_DELETE:
	    	SendEditor(SCI_CLEAR);
		    break;
    	case IDM_EDIT_SELECTALL:
	    	SendEditor(SCI_SELECTALL);
		    break;
	};
}
