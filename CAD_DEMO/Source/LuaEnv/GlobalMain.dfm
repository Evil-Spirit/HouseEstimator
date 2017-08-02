object Global: TGlobal
  Left = 414
  Top = 263
  BorderStyle = bsToolWindow
  Caption = 'Global variables'
  ClientHeight = 175
  ClientWidth = 310
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  PixelsPerInch = 96
  TextHeight = 13
  object List: TListView
    Left = 0
    Top = 0
    Width = 310
    Height = 175
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
    ReadOnly = True
    RowSelect = True
    TabOrder = 0
    ViewStyle = vsReport
    OnClick = ListClick
  end
end
