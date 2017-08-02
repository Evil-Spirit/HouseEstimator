unit StringListEditorU;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls, PropDataU;

type
  TStringListEditorF = class(TForm)
    OK        : TButton;
    Cancel    : TButton;
    MainPanel : TPanel;
    MainMemo  : TMemo;
    procedure OKClick(Sender: TObject);
    procedure CancelClick(Sender: TObject);
    procedure FormShow(Sender: TObject);

  private
    function SetLuaCode(Editor: TMemo) : string;

  public
    Prop       : TProp;
    ThisObject : TObject;
  end;

var
  StringListEditorF: TStringListEditorF;

implementation

{$R *.dfm}

{----------------------------------------------------------------------------}
procedure TStringListEditorF.OKClick(Sender: TObject);
var
  i            : Integer;
begin
  Prop.Data := SetLuaCode(MainMemo);
  TMemo(ThisObject).Lines.Clear;
  if ThisObject.ClassName = 'TMemo' then
    for i := 0 to MainMemo.Lines.Count - 1 do
      TMemo(ThisObject).Lines.Add ( MainMemo.Lines[i] );
  if ThisObject.ClassName = 'TRadioGroup' then
    for i := 0 to MainMemo.Lines.Count - 1 do
      TRadioGroup(ThisObject).Items.Add ( MainMemo.Lines[i] );
  if ThisObject.ClassName = 'TComboBox' then
    for i := 0 to MainMemo.Lines.Count - 1 do
      TComboBox(ThisObject).Items.Add ( MainMemo.Lines[i] );
  if ThisObject.ClassName = 'TListBox' then
    for i := 0 to MainMemo.Lines.Count - 1 do
      TListBox(ThisObject).Items.Add ( MainMemo.Lines[i] );
  Close;
end;

{----------------------------------------------------------------------------}
procedure TStringListEditorF.CancelClick(Sender: TObject);
begin
  Close;
end;

{----------------------------------------------------------------------------}
procedure TStringListEditorF.FormShow(Sender: TObject);
var
  i, j, k   : Integer;
  Text      : String;
begin
  k := 0;
  if Prop.Data <> '' then
    begin
      for i := 0 to Length(Prop.Data) - 2 do
        if ( Prop.Data[i] = '/' ) and ( Prop.Data[i + 1] = 'n' ) then
          begin
            Text := '';
            MainMemo.Lines.Clear;
            for j := k to i - 1 do
              Text[j - k] := Prop.Data[j];
            MainMemo.Lines.Add(Text);
            k := i + 2;
          end;
    end;
end;

{----------------------------------------------------------------------------}
function TStringListEditorF.SetLuaCode(Editor: TMemo) : string;
var
  i            : Integer;
//  FunctionName : string;
begin
  Result := '';
//  FunctionName := TControl(ThisObject).Name + 'Code';
//  Result := 'function ' + FunctionName + ' ( ' + TControl(ThisObject).Name + ' )/n';
  for i := 0 to Editor.Lines.Count - 1 do
    Result := Result + TControl(ThisObject).Name + '.Items:Add ( "' + Editor.Lines[i] + '" );/n';
//  Result := Result + 'end;/n';
end;

end.
{----------------------------------------------------------------------------}
