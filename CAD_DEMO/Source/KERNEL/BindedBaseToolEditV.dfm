object BindedBaseToolEdit: TBindedBaseToolEdit
  Left = 209
  Top = 120
  Align = alClient
  BorderStyle = bsNone
  Caption = 'BindedBaseToolEdit'
  ClientHeight = 406
  ClientWidth = 604
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 209
    Top = 0
    Width = 8
    Height = 406
    Cursor = crHSplit
    Beveled = True
  end
  object pBlocks: TPanel
    Left = 217
    Top = 0
    Width = 387
    Height = 406
    Align = alClient
    BevelOuter = bvNone
    Ctl3D = False
    ParentCtl3D = False
    TabOrder = 0
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 209
    Height = 406
    Align = alLeft
    Anchors = []
    Caption = 'Blocks'
    Ctl3D = True
    ParentCtl3D = False
    TabOrder = 1
    object Panel2: TPanel
      Left = 2
      Top = 15
      Width = 110
      Height = 389
      Align = alClient
      BevelOuter = bvNone
      BorderWidth = 4
      Caption = 'Panel2'
      TabOrder = 0
      object lvBlocks: TListView
        Left = 4
        Top = 4
        Width = 102
        Height = 381
        Align = alClient
        BorderWidth = 1
        Columns = <
          item
            Caption = 'Name'
            Width = 200
          end>
        ColumnClick = False
        Ctl3D = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        GridLines = True
        ReadOnly = True
        RowSelect = True
        ParentFont = False
        SmallImages = ImageLibrary.BlocksImageList
        TabOrder = 0
        ViewStyle = vsReport
        OnResize = lvBlocksResize
        OnSelectItem = lvBlocksSelectItem
      end
    end
    object Panel3: TPanel
      Left = 112
      Top = 15
      Width = 95
      Height = 389
      Align = alRight
      BevelOuter = bvNone
      TabOrder = 1
      object ToolBar: TToolBar
        Left = 9
        Top = 9
        Width = 58
        Height = 44
        Align = alNone
        AutoSize = True
        ButtonWidth = 58
        Caption = 'ToolBar1'
        EdgeBorders = []
        Flat = True
        Images = ImageLibrary.ActionImages
        List = True
        ShowCaptions = True
        TabOrder = 0
        object tbNew: TToolButton
          Left = 0
          Top = 0
          Caption = 'New'
          DropdownMenu = pmBlocksTypes
          ImageIndex = 0
          PopupMenu = pmBlocksTypes
          Wrap = True
        end
        object tbDelete: TToolButton
          Left = 0
          Top = 22
          Caption = 'Delete'
          ImageIndex = 2
          OnClick = tbDeleteClick
        end
      end
      object Button1: TButton
        Left = 8
        Top = 104
        Width = 73
        Height = 25
        Caption = 'EditRender'
        TabOrder = 1
        OnClick = Button1Click
      end
    end
  end
  object pmBlocksTypes: TPopupMenu
    Images = ImageLibrary.BlocksImageList
    OwnerDraw = True
    OnPopup = pmBlocksTypesPopup
    Left = 160
    Top = 80
    object spmStateBlock: TMenuItem
      Caption = 'State'
      ImageIndex = 1
      OnClick = spmStateBlockClick
    end
    object spmActionBlock: TMenuItem
      Caption = 'Action'
      ImageIndex = 2
      OnClick = spmActionBlockClick
    end
    object spmConditionalBlock: TMenuItem
      Caption = 'Conditional'
      ImageIndex = 3
      OnClick = spmConditionalBlockClick
    end
  end
end
