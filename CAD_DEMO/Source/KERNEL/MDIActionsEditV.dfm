inherited MDIActionsEdit: TMDIActionsEdit
  Left = 294
  Top = 170
  Caption = 'MDIActionsEdit'
  ClientHeight = 270
  ClientWidth = 451
  OldCreateOrder = True
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Tools: TGroupBox
    Left = 0
    Top = 0
    Width = 185
    Height = 270
    Align = alLeft
    Caption = 'Modification tools'
    TabOrder = 0
  end
  object CreateTools: TGroupBox
    Left = 185
    Top = 0
    Width = 266
    Height = 270
    Align = alClient
    Caption = 'Creation tools'
    TabOrder = 1
  end
end
