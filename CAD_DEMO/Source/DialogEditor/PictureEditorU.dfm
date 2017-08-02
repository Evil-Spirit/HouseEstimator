object PictureEditorF: TPictureEditorF
  Left = 297
  Top = 115
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Picture Editor'
  ClientHeight = 296
  ClientWidth = 344
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object MainPanel: TPanel
    Left = 8
    Top = 8
    Width = 249
    Height = 281
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object WorkPanel: TPanel
      Left = 8
      Top = 8
      Width = 233
      Height = 233
      BevelInner = bvRaised
      BevelOuter = bvLowered
      Caption = '(None)'
      Color = clCaptionText
      TabOrder = 0
      object Image: TImage
        Left = 2
        Top = 2
        Width = 229
        Height = 229
        Align = alClient
      end
    end
    object Load: TButton
      Left = 8
      Top = 248
      Width = 75
      Height = 25
      Caption = 'Load'
      TabOrder = 1
      OnClick = LoadClick
    end
    object Save: TButton
      Left = 88
      Top = 248
      Width = 75
      Height = 25
      Caption = 'Save'
      TabOrder = 2
      OnClick = SaveClick
    end
    object Clear: TButton
      Left = 168
      Top = 248
      Width = 75
      Height = 25
      Caption = 'Clear'
      TabOrder = 3
      OnClick = ClearClick
    end
  end
  object OK: TButton
    Left = 264
    Top = 8
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = OKClick
  end
  object Cancel: TButton
    Left = 264
    Top = 40
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = CancelClick
  end
  object OpenPictureDialog: TOpenPictureDialog
    Left = 272
    Top = 264
  end
  object SavePictureDialog: TSavePictureDialog
    Left = 304
    Top = 264
  end
end
