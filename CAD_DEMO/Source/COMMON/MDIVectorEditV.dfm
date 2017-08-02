inherited MDIVECEDIT: TMDIVECEDIT
  Left = 224
  Top = 309
  Caption = 'MDIVECEDIT'
  ClientHeight = 42
  ClientWidth = 289
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  inherited L: TLabel
    Left = 0
    Top = 4
  end
  object Label1: TLabel
    Left = 5
    Top = 21
    Width = 10
    Height = 13
    Caption = 'X:'
  end
  object Label2: TLabel
    Left = 101
    Top = 21
    Width = 10
    Height = 13
    Caption = 'Y:'
  end
  object Label3: TLabel
    Left = 205
    Top = 21
    Width = 10
    Height = 13
    Caption = 'Z:'
  end
  object Label4: TLabel
    Left = 74
    Top = 21
    Width = 11
    Height = 13
    Caption = #1084'.'
  end
  object Label5: TLabel
    Left = 170
    Top = 21
    Width = 11
    Height = 13
    Caption = #1084'.'
  end
  object Label6: TLabel
    Left = 274
    Top = 21
    Width = 11
    Height = 13
    Caption = #1084'.'
  end
  object Edit1: TEdit
    Left = 16
    Top = 17
    Width = 57
    Height = 21
    BiDiMode = bdLeftToRight
    ParentBiDiMode = False
    TabOrder = 0
    Text = '0'
    OnChange = Edit1Change
  end
  object Edit2: TEdit
    Left = 112
    Top = 17
    Width = 57
    Height = 21
    BiDiMode = bdLeftToRight
    ParentBiDiMode = False
    TabOrder = 1
    Text = '0'
    OnChange = Edit2Change
  end
  object Edit3: TEdit
    Left = 216
    Top = 17
    Width = 57
    Height = 21
    BiDiMode = bdLeftToRight
    ParentBiDiMode = False
    TabOrder = 2
    Text = '0'
    OnChange = Edit3Change
  end
  object IsProportional: TCheckBox
    Left = 112
    Top = 0
    Width = 137
    Height = 17
    Caption = #1057#1086#1093#1088#1072#1085#1103#1090#1100' '#1087#1088#1086#1087#1086#1088#1094#1080#1080
    TabOrder = 3
  end
end
