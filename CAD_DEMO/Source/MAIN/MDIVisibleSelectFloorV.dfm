object MDIVisibleSelectFloor: TMDIVisibleSelectFloor
  Left = 266
  Top = 168
  Width = 330
  Height = 313
  Caption = #1042#1080#1076#1080#1084#1099#1077' '#1069#1090#1072#1078#1080
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object btOK: TButton
    Left = 79
    Top = 248
    Width = 75
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 0
    OnClick = btOKClick
  end
  object btCancel: TButton
    Left = 167
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object rbAll: TRadioButton
    Left = 16
    Top = 8
    Width = 129
    Height = 17
    Caption = 'All'
    TabOrder = 2
    OnClick = rbActualAndClick
  end
  object rbActual: TRadioButton
    Left = 16
    Top = 32
    Width = 129
    Height = 17
    Caption = 'Actual floor'
    TabOrder = 3
    OnClick = rbActualAndClick
  end
  object rbActualAnd: TRadioButton
    Left = 16
    Top = 56
    Width = 137
    Height = 17
    Caption = 'Actual floor and '
    TabOrder = 4
    OnClick = rbActualAndClick
  end
  object LB: TListBox
    Left = 16
    Top = 80
    Width = 289
    Height = 153
    ItemHeight = 13
    MultiSelect = True
    TabOrder = 5
  end
end
