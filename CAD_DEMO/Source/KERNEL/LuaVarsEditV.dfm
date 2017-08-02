object LuaVarsEdit: TLuaVarsEdit
  Left = 251
  Top = 228
  Width = 576
  Height = 142
  Caption = 'LuaVarsEdit'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    568
    115)
  PixelsPerInch = 96
  TextHeight = 13
  object LV: TListView
    Left = 0
    Top = 0
    Width = 507
    Height = 115
    Align = alLeft
    Anchors = [akLeft, akTop, akRight, akBottom]
    Columns = <
      item
        Caption = 'Name'
        Tag = 120
        Width = 120
      end
      item
        Alignment = taCenter
        Caption = 'Type'
        Tag = 75
        Width = 75
      end
      item
        Alignment = taCenter
        Caption = 'Initial value'
        Tag = 85
        Width = 85
      end
      item
        Caption = 'Description'
        Tag = 120
        Width = 120
      end
      item
        Caption = 'Meter unit'
        Tag = 55
        Width = 65
      end>
    GridLines = True
    ReadOnly = True
    RowSelect = True
    TabOrder = 0
    ViewStyle = vsReport
    OnDblClick = btEditClick
  end
  object Buttons: TToolBar
    Left = 509
    Top = 1
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
    TabOrder = 1
    object tbtAdd: TToolButton
      Left = 0
      Top = 0
      Caption = 'Add'
      ImageIndex = 0
      Wrap = True
      OnClick = btAddClick
    end
    object tbtEdit: TToolButton
      Left = 0
      Top = 22
      Caption = 'Edit'
      ImageIndex = 1
      Wrap = True
      OnClick = btEditClick
    end
    object tbtDel: TToolButton
      Left = 0
      Top = 44
      Caption = 'Delete'
      ImageIndex = 2
      OnClick = btDelClick
    end
  end
end
