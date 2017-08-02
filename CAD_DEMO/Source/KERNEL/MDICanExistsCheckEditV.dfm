inherited MDICanExistsCheckEdit: TMDICanExistsCheckEdit
  Left = 413
  Top = 266
  Caption = 'MDICanExistsCheckEdit'
  ClientHeight = 289
  ClientWidth = 538
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  object TV: TTreeView
    Left = 0
    Top = 25
    Width = 538
    Height = 264
    Align = alClient
    Color = clWhite
    DragCursor = crDefault
    HideSelection = False
    Indent = 27
    ParentShowHint = False
    ReadOnly = True
    RightClickSelect = True
    RowSelect = True
    ShowHint = False
    TabOrder = 1
    OnMouseDown = TVMouseDown
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 538
    Height = 25
    Caption = 'ToolBar1'
    Flat = True
    TabOrder = 0
    object ToolButton1: TToolButton
      Left = 0
      Top = 0
      Caption = #1053#1086#1074#1099#1081
      ImageIndex = 0
    end
    object ToolButton4: TToolButton
      Left = 23
      Top = 0
      Caption = #1053#1086#1074#1072#1103' '#1075#1088#1091#1087#1087#1072
      ImageIndex = 3
    end
    object ToolButton3: TToolButton
      Left = 46
      Top = 0
      Caption = #1059#1076#1072#1083#1080#1090#1100
      ImageIndex = 2
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 80
    Top = 128
    object N1: TMenuItem
      Caption = #1053#1086#1074#1072#1103' '#1089#1074#1103#1079#1082#1072' '#1074' '#1075#1088#1091#1087#1087#1077
      ImageIndex = 0
      OnClick = N1Click
    end
    object N4: TMenuItem
      Caption = #1053#1086#1074#1072#1103' '#1075#1088#1091#1087#1087#1072' '#1089#1074#1103#1079#1086#1082
      ImageIndex = 3
      OnClick = N4Click
    end
    object N3: TMenuItem
      Caption = #1059#1076#1072#1083#1080#1090#1100
      ImageIndex = 2
      OnClick = N3Click
    end
  end
  object ImageList1: TImageList
    Left = 48
    Top = 128
  end
end
