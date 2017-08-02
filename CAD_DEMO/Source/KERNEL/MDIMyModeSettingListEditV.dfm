inherited MDIMyModeSettingListEdit: TMDIMyModeSettingListEdit
  Left = 322
  Top = 112
  Caption = 'MDIMyModeSettingListEdit'
  ClientHeight = 385
  ClientWidth = 669
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  object LV: TListView
    Left = 509
    Top = 16
    Width = 155
    Height = 341
    Anchors = [akTop, akRight, akBottom]
    Columns = <
      item
        Width = 100
      end>
    DragMode = dmAutomatic
    FullDrag = True
    HideSelection = False
    ReadOnly = True
    RowSelect = True
    TabOrder = 0
    ViewStyle = vsList
    OnClick = LVClick
  end
  object SSS: TPanel
    Left = 0
    Top = 0
    Width = 505
    Height = 385
    Align = alLeft
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabOrder = 2
  end
  object ToolBar1: TToolBar
    Left = 510
    Top = 359
    Width = 86
    Height = 19
    Align = alNone
    Anchors = [akRight, akBottom]
    AutoSize = True
    ButtonHeight = 19
    ButtonWidth = 43
    Caption = 'ToolBar1'
    EdgeBorders = []
    Flat = True
    List = True
    ShowCaptions = True
    TabOrder = 1
    object tbtAdd: TToolButton
      Left = 0
      Top = 0
      Caption = 'Add'
      ImageIndex = 0
      OnClick = tbtAddClick
    end
    object tbtDel: TToolButton
      Left = 43
      Top = 0
      Caption = 'Delete'
      ImageIndex = 2
      OnClick = tbtDelClick
    end
  end
  object IsDefault: TCheckBox
    Left = 512
    Top = 0
    Width = 145
    Height = 17
    Anchors = [akTop, akRight]
    Caption = 'Default'
    TabOrder = 3
    OnClick = IsDefaultClick
  end
end
