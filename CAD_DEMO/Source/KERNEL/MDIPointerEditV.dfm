inherited MDIPointerEdit: TMDIPointerEdit
  Left = 492
  Top = 307
  Caption = 'MDIPointerEdit'
  ClientHeight = 35
  ClientWidth = 226
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  object CBE: TComboBoxEx
    Left = 8
    Top = 9
    Width = 209
    Height = 22
    ItemsEx.CaseSensitive = False
    ItemsEx.SortType = stNone
    ItemsEx = <>
    Style = csExDropDownList
    StyleEx = []
    Anchors = [akLeft, akTop, akRight, akBottom]
    ItemHeight = 16
    TabOrder = 0
    OnChange = CBEChange
    Images = ImageLibrary.TreeImages
    DropDownCount = 8
  end
end
