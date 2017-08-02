inherited MDIMyTextureFlagsEdit: TMDIMyTextureFlagsEdit
  Left = 531
  Top = 319
  Caption = 'MDIMyTextureFlagsEdit'
  ClientHeight = 208
  ClientWidth = 397
  Constraints.MinHeight = 220
  Constraints.MinWidth = 310
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel [0]
    Left = 96
    Top = 20
    Width = 27
    Height = 13
    Caption = 'Mode'
  end
  object Shift: TPanel
    Left = 8
    Top = 155
    Width = 385
    Height = 43
    Anchors = []
    BevelOuter = bvNone
    Caption = 'Shift'
    TabOrder = 0
  end
  object Scale: TPanel
    Left = 8
    Top = 103
    Width = 385
    Height = 43
    Anchors = []
    BevelOuter = bvNone
    Caption = 'Scale'
    TabOrder = 1
  end
  object Param: TPanel
    Left = 8
    Top = 51
    Width = 385
    Height = 43
    Anchors = []
    BevelOuter = bvNone
    Caption = 'Param'
    TabOrder = 2
  end
  object CBE: TComboBox
    Left = 144
    Top = 16
    Width = 240
    Height = 19
    Style = csOwnerDrawFixed
    Anchors = [akLeft, akTop, akRight, akBottom]
    ItemHeight = 13
    TabOrder = 3
  end
end
