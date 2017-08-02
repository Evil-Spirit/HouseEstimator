object StringListEditorF: TStringListEditorF
  Left = 375
  Top = 306
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'String List Editor'
  ClientHeight = 334
  ClientWidth = 476
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object OK: TButton
    Left = 312
    Top = 304
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = OKClick
  end
  object Cancel: TButton
    Left = 392
    Top = 304
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = CancelClick
  end
  object MainPanel: TPanel
    Left = 8
    Top = 8
    Width = 465
    Height = 289
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 2
    object MainMemo: TMemo
      Left = 8
      Top = 8
      Width = 449
      Height = 273
      ScrollBars = ssBoth
      TabOrder = 0
    end
  end
end
