inherited MDITriggerBlockEdit: TMDITriggerBlockEdit
  Left = 429
  Top = 149
  Caption = 'MDITriggerBlockEdit'
  ClientHeight = 192
  ClientWidth = 314
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  object LV: TListView
    Left = 0
    Top = 0
    Width = 200
    Height = 192
    Align = alLeft
    Anchors = [akLeft, akTop, akRight, akBottom]
    Columns = <
      item
        AutoSize = True
      end>
    DragMode = dmAutomatic
    FullDrag = True
    GridLines = True
    HideSelection = False
    ReadOnly = True
    RowSelect = True
    ShowColumnHeaders = False
    SmallImages = ImageLibrary.TreeImages
    TabOrder = 1
    ViewStyle = vsReport
    OnDblClick = tbtEditClick
  end
  object Buttons: TToolBar
    Left = 206
    Top = 15
    Width = 58
    Height = 66
    Align = alNone
    Anchors = [akTop, akRight]
    AutoSize = True
    ButtonWidth = 58
    Caption = 'Buttons'
    EdgeBorders = []
    Flat = True
    Images = ImageLibrary.ActionImages
    List = True
    ShowCaptions = True
    TabOrder = 0
    object tbtAdd: TToolButton
      Left = 0
      Top = 0
      Caption = 'Add'
      ImageIndex = 0
      Wrap = True
      OnClick = tbtAddClick
    end
    object tbtEdit: TToolButton
      Left = 0
      Top = 22
      Caption = 'Edit'
      ImageIndex = 1
      Wrap = True
      OnClick = tbtEditClick
    end
    object tbtDel: TToolButton
      Left = 0
      Top = 44
      Caption = 'Delete'
      ImageIndex = 2
      OnClick = tbtDelClick
    end
  end
  object PM: TPopupMenu
    Images = ImageLibrary.TreeImages
    Left = 208
    Top = 96
  end
end
