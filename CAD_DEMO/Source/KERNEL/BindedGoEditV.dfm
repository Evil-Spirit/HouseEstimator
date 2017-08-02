object BindedGoEdit: TBindedGoEdit
  Left = 431
  Top = 282
  BorderIcons = [biMinimize, biMaximize]
  BorderStyle = bsSingle
  Caption = 'BindedGoEdit'
  ClientHeight = 140
  ClientWidth = 215
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object lEvent: TLabel
    Left = 12
    Top = 40
    Width = 34
    Height = 13
    Caption = 'Event :'
  end
  object lKey: TLabel
    Left = 12
    Top = 72
    Width = 51
    Height = 13
    Caption = #1050#1083#1072#1074#1080#1096#1072' :'
  end
  object lMouseButton: TLabel
    Left = 12
    Top = 72
    Width = 71
    Height = 13
    Caption = 'Mouse button :'
  end
  object lNextBlock: TLabel
    Left = 12
    Top = 10
    Width = 50
    Height = 13
    Caption = 'Switch to :'
  end
  object cbEvent: TComboBox
    Left = 96
    Top = 40
    Width = 105
    Height = 19
    Style = csOwnerDrawFixed
    ItemHeight = 13
    TabOrder = 0
    OnChange = cbEventChange
  end
  object eKey: TEdit
    Left = 96
    Top = 72
    Width = 105
    Height = 21
    TabOrder = 1
    Text = 'Press key...'
    OnChange = eKeyChange
    OnKeyDown = eKeyKeyDown
  end
  object cbMouseButton: TComboBox
    Left = 96
    Top = 72
    Width = 105
    Height = 19
    Style = csOwnerDrawFixed
    ItemHeight = 13
    TabOrder = 2
  end
  object cbNextBlock: TComboBox
    Left = 96
    Top = 8
    Width = 105
    Height = 19
    Style = csOwnerDrawFixed
    ItemHeight = 13
    TabOrder = 3
  end
  object bOk: TButton
    Left = 16
    Top = 104
    Width = 73
    Height = 25
    Caption = 'OK'
    TabOrder = 4
    OnClick = bOkClick
  end
  object bCancel: TButton
    Left = 120
    Top = 104
    Width = 73
    Height = 25
    Caption = 'Cancel'
    TabOrder = 5
    OnClick = bCancelClick
  end
end
