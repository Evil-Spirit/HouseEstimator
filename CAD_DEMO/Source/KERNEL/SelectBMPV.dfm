object SelectBMP: TSelectBMP
  Left = 362
  Top = 220
  Anchors = [akLeft, akTop, akRight]
  BorderStyle = bsDialog
  Caption = 'SelectBMP'
  ClientHeight = 458
  ClientWidth = 457
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  OnShow = FormShow
  DesignSize = (
    457
    458)
  PixelsPerInch = 96
  TextHeight = 13
  object LV: TListView
    Left = 8
    Top = 40
    Width = 347
    Height = 408
    Anchors = [akLeft, akTop, akRight, akBottom]
    Columns = <
      item
        AutoSize = True
      end>
    Constraints.MinHeight = 100
    Constraints.MinWidth = 100
    FlatScrollBars = True
    FullDrag = True
    IconOptions.AutoArrange = True
    IconOptions.WrapText = False
    Items.Data = {1D0000000100000000000000FFFFFFFFFFFFFFFF000000000000000000}
    ReadOnly = True
    RowSelect = True
    ParentShowHint = False
    ShowColumnHeaders = False
    ShowHint = False
    TabOrder = 0
    ViewStyle = vsReport
  end
  object CBE: TComboBoxEx
    Left = 8
    Top = 8
    Width = 348
    Height = 22
    ItemsEx.CaseSensitive = False
    ItemsEx.SortType = stNone
    ItemsEx = <>
    StyleEx = []
    Anchors = [akLeft, akTop, akRight]
    ItemHeight = 16
    TabOrder = 1
    OnChange = CBEChange
    DropDownCount = 8
  end
  object btOK: TButton
    Left = 372
    Top = 8
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'OK'
    TabOrder = 2
    OnClick = btOKClick
  end
  object btCancel: TButton
    Left = 372
    Top = 40
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Cancel'
    TabOrder = 3
    OnClick = btCancelClick
  end
  object btClear: TButton
    Left = 372
    Top = 72
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Clear'
    TabOrder = 4
    OnClick = btClearClick
  end
end
