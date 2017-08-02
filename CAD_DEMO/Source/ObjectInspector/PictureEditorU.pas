unit PictureEditorU;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtDlgs, ExtCtrls, StdCtrls;

type
  TPictureEditorF = class(TForm)
    MainPanel: TPanel;
    OK: TButton;
    Cancel: TButton;
    WorkPanel: TPanel;
    Load: TButton;
    Save: TButton;
    Clear: TButton;
    Image: TImage;
    OpenPictureDialog: TOpenPictureDialog;
    SavePictureDialog: TSavePictureDialog;
    procedure OKClick(Sender: TObject);
    procedure CancelClick(Sender: TObject);
    procedure LoadClick(Sender: TObject);
    procedure SaveClick(Sender: TObject);
    procedure ClearClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  PictureEditorF: TPictureEditorF;

implementation

{$R *.dfm}

procedure TPictureEditorF.OKClick(Sender: TObject);
begin
  Close;
end;

procedure TPictureEditorF.CancelClick(Sender: TObject);
begin
  Close;
end;

procedure TPictureEditorF.LoadClick(Sender: TObject);
begin
  OpenPictureDialog.Execute;
  if Length ( OpenPictureDialog.FileName ) > 0 then
    begin
      Image.Picture.LoadFromFile ( OpenPictureDialog.FileName );
      Save.Enabled := True;
      Clear.Enabled := True;
    end;
  Image.Visible := True;
end;

procedure TPictureEditorF.SaveClick(Sender: TObject);
begin
  SavePictureDialog.Execute;
  if Length ( SavePictureDialog.FileName ) > 0 then
    Image.Picture.SaveToFile ( SavePictureDialog.FileName );
end;

procedure TPictureEditorF.ClearClick(Sender: TObject);
begin
  Image.Visible := False;
  Save.Enabled := False;
  Clear.Enabled := False;
end;

procedure TPictureEditorF.FormCreate(Sender: TObject);
begin
  SavePictureDialog.FilterIndex := 2;
end;

end.
