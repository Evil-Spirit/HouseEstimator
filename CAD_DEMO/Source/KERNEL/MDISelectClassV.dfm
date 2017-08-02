object MDISelectClass: TMDISelectClass
  Left = 330
  Top = 287
  BorderStyle = bsDialog
  Caption = 'MDISelectClass'
  ClientHeight = 237
  ClientWidth = 264
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 184
    Top = 8
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 184
    Top = 40
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = Button2Click
  end
  object ListBox1: TListBox
    Left = 8
    Top = 8
    Width = 169
    Height = 225
    ItemHeight = 13
    TabOrder = 2
  end
end
