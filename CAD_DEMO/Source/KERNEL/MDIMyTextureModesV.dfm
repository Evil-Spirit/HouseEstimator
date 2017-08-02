inherited MDIMyTextureModes: TMDIMyTextureModes
  Left = 297
  Top = 188
  Caption = 'MDIMyTextureModes'
  ClientHeight = 167
  ClientWidth = 226
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  inherited LBL: TLabel
    Left = 200
    Top = 8
    Visible = False
  end
  object lMode: TLabel
    Left = 3
    Top = 8
    Width = 47
    Height = 13
    Caption = 'Apply to...'
  end
  object cbMode: TComboBox
    Left = 80
    Top = 4
    Width = 113
    Height = 19
    Style = csOwnerDrawFixed
    ItemHeight = 13
    TabOrder = 0
    OnChange = cbModeChange
  end
  object gbMinMax: TGroupBox
    Left = 0
    Top = 32
    Width = 226
    Height = 135
    Align = alBottom
    Caption = 'Decorating options'
    TabOrder = 1
    object Label1: TLabel
      Left = 16
      Top = 24
      Width = 95
      Height = 13
      Caption = 'Upper limit by height'
    end
    object Label2: TLabel
      Left = 16
      Top = 72
      Width = 95
      Height = 13
      Caption = 'Lower limit by height'
    end
    object edZMax: TEdit
      Left = 16
      Top = 40
      Width = 121
      Height = 21
      TabOrder = 0
      Text = 'edZMax'
    end
    object edZMin: TEdit
      Left = 16
      Top = 88
      Width = 121
      Height = 21
      TabOrder = 1
      Text = 'Edit1'
    end
  end
end
