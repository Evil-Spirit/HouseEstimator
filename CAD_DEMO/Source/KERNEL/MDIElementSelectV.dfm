object MDIElementSelect: TMDIElementSelect
  Left = 346
  Top = 299
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'MDIElementSelect'
  ClientHeight = 286
  ClientWidth = 409
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object LV: TListView
    Left = 0
    Top = 0
    Width = 321
    Height = 286
    Align = alLeft
    Columns = <
      item
        Width = 290
      end>
    DragMode = dmAutomatic
    ReadOnly = True
    RowSelect = True
    ShowColumnHeaders = False
    SmallImages = ImageLibrary.TreeImages
    SortType = stText
    TabOrder = 0
    ViewStyle = vsReport
  end
  object OK: TButton
    Left = 328
    Top = 8
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = OKClick
  end
  object btCancel: TButton
    Left = 328
    Top = 40
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = btCancelClick
  end
end
