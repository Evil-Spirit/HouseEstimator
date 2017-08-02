object StringListEditor: TStringListEditor
  Left = 394
  Top = 132
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'String List Editor'
  ClientHeight = 338
  ClientWidth = 482
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object MainPanel: TPanel
    Left = 8
    Top = 8
    Width = 465
    Height = 281
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object MainMemo: TMemo
      Left = 8
      Top = 8
      Width = 449
      Height = 265
      ScrollBars = ssBoth
      TabOrder = 0
    end
  end
  object OK: TButton
    Left = 296
    Top = 304
    Width = 81
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = OKClick
  end
  object Cancel: TButton
    Left = 384
    Top = 304
    Width = 89
    Height = 25
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = CancelClick
  end
end
