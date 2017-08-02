unit StringListEditorU;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls;

type
  TStringListEditorF = class(TForm)
    OK: TButton;
    Cancel: TButton;
    MainPanel: TPanel;
    MainMemo: TMemo;
    procedure OKClick(Sender: TObject);
    procedure CancelClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  StringListEditorF: TStringListEditorF;

implementation

{$R *.dfm}

procedure TStringListEditorF.OKClick(Sender: TObject);
begin
  Close;
end;

procedure TStringListEditorF.CancelClick(Sender: TObject);
begin
  Close;
end;

end.
