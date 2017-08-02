object OffsetCell: TOffsetCell
  Left = 381
  Top = 276
  BorderStyle = bsDialog
  Caption = #1059#1076#1072#1083#1077#1085#1080#1077' '#1103#1095#1077#1077#1082
  ClientHeight = 118
  ClientWidth = 207
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 8
    Width = 43
    Height = 13
    Caption = #1059#1076#1072#1083#1080#1090#1100
  end
  object Button1: TButton
    Left = 16
    Top = 88
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 96
    Top = 88
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 1
    OnClick = Button2Click
  end
  object rbLeftOffset: TRadioButton
    Left = 16
    Top = 32
    Width = 169
    Height = 17
    Caption = #1071#1095#1077#1081#1082#1080', '#1089#1086' '#1089#1076#1074#1080#1075#1086#1084' '#1074#1083#1077#1074#1086
    TabOrder = 2
  end
  object rbTopOffset: TRadioButton
    Left = 16
    Top = 56
    Width = 169
    Height = 17
    Caption = #1071#1095#1077#1081#1082#1080', '#1089#1086' '#1089#1076#1074#1080#1075#1086#1084' '#1074#1074#1077#1088#1093
    Checked = True
    TabOrder = 3
    TabStop = True
  end
end
