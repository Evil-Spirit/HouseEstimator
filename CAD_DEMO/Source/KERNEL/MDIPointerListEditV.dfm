inherited MDIPointerListEdit: TMDIPointerListEdit
  Left = 318
  Top = 201
  Caption = 'MDIPointerListEdit'
  ClientHeight = 272
  ClientWidth = 344
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  object LV: TListView
    Left = 0
    Top = 0
    Width = 256
    Height = 272
    Align = alClient
    Columns = <
      item
        Width = 150
      end>
    DragMode = dmAutomatic
    FullDrag = True
    HideSelection = False
    ReadOnly = True
    RowSelect = True
    ShowColumnHeaders = False
    SmallImages = ImageLibrary.TreeImages
    TabOrder = 0
    ViewStyle = vsReport
  end
  object PButtons: TPanel
    Left = 256
    Top = 0
    Width = 88
    Height = 272
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 1
    object ToolBar1: TToolBar
      Left = 7
      Top = 4
      Width = 79
      Height = 110
      Align = alNone
      AutoSize = True
      ButtonWidth = 79
      Caption = 'ToolBar1'
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
        OnClick = btAddClick
      end
      object tbReset: TToolButton
        Left = 0
        Top = 22
        Caption = 'Empty'
        ImageIndex = 0
        Wrap = True
        Visible = False
        OnClick = tbResetClick
      end
      object tbtDel: TToolButton
        Left = 0
        Top = 44
        Caption = 'Delete'
        ImageIndex = 2
        Wrap = True
        OnClick = btDelClick
      end
      object tbtUp: TToolButton
        Left = 0
        Top = 66
        Caption = 'Shift Up'
        ImageIndex = 4
        Wrap = True
        OnClick = sbupClick
      end
      object tbtDown: TToolButton
        Left = 0
        Top = 88
        Caption = 'Shift Down'
        ImageIndex = 5
        OnClick = sbdownClick
      end
    end
  end
end
