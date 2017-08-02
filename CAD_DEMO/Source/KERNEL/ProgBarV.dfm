object ProgBar: TProgBar
  Left = 430
  Top = 650
  BorderStyle = bsDialog
  Caption = 'ProgBar'
  ClientHeight = 84
  ClientWidth = 378
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnHide = FormHide
  PixelsPerInch = 96
  TextHeight = 13
  object Main: TLabel
    Left = 8
    Top = 37
    Width = 23
    Height = 13
    Caption = 'Main'
  end
  object Detail: TLabel
    Left = 8
    Top = 53
    Width = 27
    Height = 13
    Caption = 'Detail'
  end
  object lProcessName: TLabel
    Left = 8
    Top = 8
    Width = 103
    Height = 16
    Caption = 'lProcessName'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Progress: TProgressBar
    Left = 8
    Top = 69
    Width = 361
    Height = 12
    Min = 0
    Max = 100
    TabOrder = 0
  end
end
