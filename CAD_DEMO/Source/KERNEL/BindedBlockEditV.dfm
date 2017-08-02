object BindedBlockEdit: TBindedBlockEdit
  Left = 283
  Top = 201
  Align = alClient
  BorderStyle = bsNone
  Caption = 'BindedBlockEdit'
  ClientHeight = 316
  ClientWidth = 416
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 0
    Top = 161
    Width = 416
    Height = 8
    Cursor = crVSplit
    Align = alTop
  end
  object pBlockEdit: TPanel
    Left = 0
    Top = 0
    Width = 416
    Height = 161
    Align = alTop
    Ctl3D = False
    ParentCtl3D = False
    TabOrder = 0
    object Panel1: TPanel
      Left = 276
      Top = 1
      Width = 139
      Height = 159
      Align = alRight
      BevelOuter = bvNone
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 0
      object lNameSB: TLabel
        Left = 40
        Top = 6
        Width = 56
        Height = 13
        Caption = 'Block name'
      end
      object lExecutedEvent: TLabel
        Left = 15
        Top = 115
        Width = 69
        Height = 13
        Caption = 'Execute event'
      end
      object ToolBar1: TToolBar
        Left = 18
        Top = 46
        Width = 58
        Height = 66
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
          ImageIndex = 0
          Wrap = True
          OnClick = tbNewClick
        end
        object tbEdit: TToolButton
          Left = 0
          Top = 22
          Caption = 'Edit'
          ImageIndex = 1
          Wrap = True
          OnClick = tbEditClick
        end
        object tbDelete: TToolButton
          Left = 0
          Top = 44
          Caption = 'Delete'
          ImageIndex = 2
          OnClick = tbDeleteClick
        end
      end
      object cbExEvent: TComboBox
        Left = 17
        Top = 128
        Width = 105
        Height = 21
        Style = csDropDownList
        ItemHeight = 13
        TabOrder = 1
      end
      object eName: TEdit
        Left = 17
        Top = 19
        Width = 105
        Height = 21
        Ctl3D = True
        ParentCtl3D = False
        TabOrder = 2
        Text = 'Block'
        OnChange = eNameChange
      end
    end
    object GroupBox1: TGroupBox
      Left = 1
      Top = 1
      Width = 275
      Height = 159
      Align = alClient
      Caption = 'Switch to'
      Ctl3D = True
      ParentCtl3D = False
      TabOrder = 1
      object Panel2: TPanel
        Left = 2
        Top = 15
        Width = 271
        Height = 142
        Align = alClient
        BevelOuter = bvNone
        BorderWidth = 4
        Caption = 'Panel2'
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 0
        object lvNextBlock: TListView
          Left = 4
          Top = 4
          Width = 263
          Height = 134
          Align = alClient
          BevelKind = bkFlat
          BorderStyle = bsNone
          Columns = <>
          ColumnClick = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          GridLines = True
          ReadOnly = True
          RowSelect = True
          ParentFont = False
          ParentShowHint = False
          ShowHint = False
          SmallImages = ImageLibrary.BlocksImageList
          TabOrder = 0
          ViewStyle = vsReport
          OnDblClick = lvNextBlockDblClick
          OnResize = lvNextBlockResize
        end
      end
    end
  end
  object pLuaModuleEdit: TPanel
    Left = 0
    Top = 169
    Width = 416
    Height = 147
    Align = alClient
    BevelOuter = bvNone
    Ctl3D = False
    ParentCtl3D = False
    TabOrder = 1
  end
end
