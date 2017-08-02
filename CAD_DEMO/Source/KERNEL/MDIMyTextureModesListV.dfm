inherited MDIMyTextureModesList: TMDIMyTextureModesList
  Left = 299
  Top = 369
  Caption = 'MDIMyTextureModesList'
  ClientHeight = 315
  ClientWidth = 571
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  object ToolBar1: TToolBar
    Left = 409
    Top = 290
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
    TabOrder = 0
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
  object SSS: TPanel
    Left = 0
    Top = 0
    Width = 404
    Height = 315
    Align = alLeft
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabOrder = 1
  end
  object LV: TListView
    Left = 410
    Top = 9
    Width = 155
    Height = 278
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
    TabOrder = 2
    ViewStyle = vsList
    OnClick = LVClick
  end
end
