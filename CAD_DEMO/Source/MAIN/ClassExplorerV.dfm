object ClassExplorer: TClassExplorer
  Left = 192
  Top = 107
  Width = 696
  Height = 480
  Caption = 'ClassExplorer'
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
  object TreeView1: TTreeView
    Left = 32
    Top = 16
    Width = 633
    Height = 385
    Indent = 19
    TabOrder = 0
  end
  object bClose: TButton
    Left = 288
    Top = 416
    Width = 75
    Height = 25
    Caption = 'Close'
    TabOrder = 1
    OnClick = bCloseClick
  end
end
