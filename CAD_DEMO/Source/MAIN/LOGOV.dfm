object Logo: TLogo
  Left = 239
  Top = 240
  AutoSize = True
  BorderStyle = bsNone
  Caption = 'Logo'
  ClientHeight = 314
  ClientWidth = 500
  Color = clBtnFace
  TransparentColorValue = clBtnFace
  Constraints.MinHeight = 200
  Constraints.MinWidth = 350
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 500
    Height = 314
    AutoSize = True
    Center = True
    IncrementalDisplay = True
    Stretch = True
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 3000
    OnTimer = Timer1Timer
    Left = 8
    Top = 8
  end
end
