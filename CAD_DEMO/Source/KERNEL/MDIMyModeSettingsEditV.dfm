inherited MDIMyModeSettingsEdit: TMDIMyModeSettingsEdit
  Left = 442
  Top = 227
  Caption = 'MDIMyModeSettingsEdit'
  ClientHeight = 396
  ClientWidth = 446
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel [0]
    Left = 20
    Top = 316
    Width = 116
    Height = 13
    Caption = 'Position correction mode'
  end
  object Label1: TLabel [1]
    Left = 20
    Top = 247
    Width = 99
    Height = 13
    Caption = 'Size correction mode'
  end
  object OverSize: TPanel
    Left = 11
    Top = 270
    Width = 302
    Height = 36
    BevelOuter = bvNone
    Caption = 'OverSize'
    TabOrder = 0
  end
  object OverPos: TPanel
    Left = 11
    Top = 334
    Width = 302
    Height = 36
    BevelOuter = bvNone
    Caption = 'OverPos'
    TabOrder = 1
  end
  object cbRender: TCheckBox
    Left = 24
    Top = 371
    Width = 73
    Height = 17
    Caption = 'Visible'
    TabOrder = 2
  end
  object cbOverSize: TComboBox
    Left = 168
    Top = 243
    Width = 145
    Height = 19
    Style = csOwnerDrawFixed
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 3
    Text = '<None>'
    Items.Strings = (
      '<None>'
      'Add'
      'Replace')
  end
  object cbOverPos: TComboBox
    Left = 168
    Top = 309
    Width = 145
    Height = 19
    Style = csOwnerDrawFixed
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 5
    Text = '<None>'
    Items.Strings = (
      '<None>'
      'Add'
      'Replace')
  end
  object cbFLAT_2D: TCheckBox
    Left = 104
    Top = 371
    Width = 73
    Height = 17
    Caption = 'Flat'
    TabOrder = 4
  end
  object pcMatTex: TPageControl
    Left = 0
    Top = 0
    Width = 446
    Height = 233
    ActivePage = MAT
    Align = alTop
    TabIndex = 0
    TabOrder = 6
    object MAT: TTabSheet
      Caption = 'Materials'
    end
    object TEX: TTabSheet
      Caption = 'Textures'
      ImageIndex = 1
    end
  end
end
