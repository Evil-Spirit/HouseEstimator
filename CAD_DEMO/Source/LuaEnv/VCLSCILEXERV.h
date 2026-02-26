// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef VCLSCILEXERVH
#define VCLSCILEXERVH
const COLORREF black = RGB(0,0,0);
const COLORREF white = RGB(0xff,0xff,0xff);

const IDM_EDIT_UNDO     =1;
const IDM_EDIT_REDO     =2;
const IDM_EDIT_CUT      =3;
const IDM_EDIT_COPY     =4;
const IDM_EDIT_PASTE    =5;
const IDM_EDIT_DELETE   =6;
const IDM_EDIT_SELECTALL=7;

const IDM_SEARCH_FIND = 11;
const IDM_SEARCH_FINDNEXT = 12;
const IDM_SEARCH_REPLACE = 13;
//---------------------------------------------------------------------------
class TSciLexer;
struct SCNotification;
typedef void  ( *TSciNotifyEvent)(TSciLexer* Sender,SCNotification *notification);

class  TSciLexer : public TWinControl {
protected:
    void  WndProc(Messages::TMessage &Message);
    virtual void  CreateParams(Controls::TCreateParams &Params);
    virtual void  CreateWnd(void);
    TSciNotifyEvent FOnNotify;
    void InitialiseEditor();
	void SetAStyle(int style, COLORREF fore, COLORREF back=white, int size=-1, const char *face=0);
	void Notify(SCNotification *notification);
    void SetText(const AnsiString& Text);
    AnsiString GetText();
public:
    // __property AnsiString Text {read=GetText, write=SetText}; // [manual migration needed]
    // __property TSciNotifyEvent OnNotify {read=FOnNotify, write=FOnNotify}; // [manual migration needed]
	 virtual TSciLexer(Classes::TComponent* AOwner);
	LRESULT SendEditor(UINT Msg, WPARAM wParam=0, LPARAM lParam=0);
    void Command(int id);
    __property OnKeyDown;
    __property OnKeyUp;
};
#endif
