object AddLuaVar: TAddLuaVar
  Left = 373
  Top = 239
  Width = 348
  Height = 235
  Caption = 'AddLuaVar'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lName: TLabel
    Left = 32
    Top = 16
    Width = 28
    Height = 13
    Caption = 'Name'
  end
  object lType: TLabel
    Left = 32
    Top = 48
    Width = 24
    Height = 13
    Caption = 'Type'
  end
  object Label1: TLabel
    Left = 32
    Top = 80
    Width = 53
    Height = 13
    Caption = 'Initial value'
  end
  object Label2: TLabel
    Left = 32
    Top = 112
    Width = 53
    Height = 13
    Caption = 'Description'
  end
  object Label3: TLabel
    Left = 32
    Top = 144
    Width = 47
    Height = 13
    Caption = 'Meter unit'
  end
  object cbVarType: TComboBox
    Left = 112
    Top = 44
    Width = 201
    Height = 19
    Style = csOwnerDrawFixed
    ItemHeight = 13
    TabOrder = 0
  end
  object eVarName: TEdit
    Left = 112
    Top = 12
    Width = 201
    Height = 21
    TabOrder = 1
  end
  object eVarVal: TEdit
    Left = 112
    Top = 76
    Width = 201
    Height = 21
    TabOrder = 2
  end
  object btOK: TButton
    Left = 64
    Top = 175
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 3
    OnClick = btOKClick
  end
  object btCancel: TButton
    Left = 192
    Top = 175
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 4
    OnClick = btCancelClick
  end
  object eComment: TEdit
    Left = 112
    Top = 108
    Width = 201
    Height = 21
    TabOrder = 5
  end
  object eMeter: TEdit
    Left = 112
    Top = 140
    Width = 201
    Height = 21
    TabOrder = 6
  end
end
