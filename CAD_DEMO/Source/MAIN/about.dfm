object AboutBox: TAboutBox
  Left = 442
  Top = 164
  ActiveControl = OKButton
  BorderStyle = bsDialog
  Caption = 'About ...'
  ClientHeight = 138
  ClientWidth = 298
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clBlack
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 281
    Height = 81
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Color = clWhite
    TabOrder = 0
    object ProductName: TLabel
      Left = 64
      Top = 16
      Width = 163
      Height = 20
      Caption = '3D House Estimator'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      IsControl = True
    end
    object Version: TLabel
      Left = 64
      Top = 40
      Width = 102
      Height = 13
      Caption = 'Demo Edition ver. 1.0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      IsControl = True
    end
    object Label3: TLabel
      Left = 160
      Top = 64
      Width = 116
      Height = 13
      Caption = 'www.sibcomponent.com'
    end
  end
  object OKButton: TButton
    Left = 224
    Top = 106
    Width = 65
    Height = 23
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 1
    IsControl = True
  end
end
