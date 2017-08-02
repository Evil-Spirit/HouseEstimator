object Global: TGlobal
  Left = 419
  Top = 261
  BorderStyle = bsToolWindow
  Caption = '[COMMON]'
  ClientHeight = 173
  ClientWidth = 352
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object List: TListView
    Left = 0
    Top = 0
    Width = 352
    Height = 173
    Align = alClient
    Color = clWhite
    Columns = <
      item
        AutoSize = True
        Caption = 'Name'
      end
      item
        AutoSize = True
        Caption = 'Type'
      end
      item
        AutoSize = True
        Caption = 'Value'
      end>
    ColumnClick = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -8
    Font.Name = 'Default'
    Font.Style = []
    ReadOnly = True
    RowSelect = True
    ParentFont = False
    ShowWorkAreas = True
    TabOrder = 0
    ViewStyle = vsReport
    OnDblClick = ListDblClick
    OnKeyDown = ListKeyDown
  end
  object WatchActions: TActionList
    Left = 324
    Top = 144
    object AddItem: TAction
      Caption = 'Add watch'
      ShortCut = 16449
      OnExecute = AddItemExecute
    end
    object DelItem: TAction
      Caption = 'Delete item'
      ShortCut = 16452
      OnExecute = DelItemExecute
      OnUpdate = DelItemUpdate
    end
    object ClearItem: TAction
      Caption = 'Clear all items'
      OnExecute = ClearItemExecute
      OnUpdate = ClearItemUpdate
    end
    object EditItem: TAction
      Caption = 'Edit watch'
      ShortCut = 16453
      OnExecute = EditItemExecute
      OnUpdate = EditItemUpdate
    end
    object InspectItem: TAction
      Caption = 'Inspect item'
      ShortCut = 16457
      OnExecute = InspectItemExecute
      OnUpdate = InspectItemUpdate
    end
  end
  object WatchPopup: TPopupMenu
    Left = 296
    Top = 145
    object AddItem1: TMenuItem
      Action = AddItem
      Caption = 'Add item'
    end
    object DelItem1: TMenuItem
      Action = DelItem
    end
    object Editwatch1: TMenuItem
      Action = EditItem
    end
    object ClearItem1: TMenuItem
      Action = ClearItem
    end
    object Inspectitem1: TMenuItem
      Action = InspectItem
    end
  end
end
