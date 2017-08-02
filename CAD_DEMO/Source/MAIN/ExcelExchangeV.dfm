object ExcelExchange: TExcelExchange
  Left = 258
  Top = 130
  BorderStyle = bsDialog
  BorderWidth = 5
  Caption = 'ExcelExchange'
  ClientHeight = 316
  ClientWidth = 377
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    377
    316)
  PixelsPerInch = 96
  TextHeight = 13
  object LV: TListView
    Left = 0
    Top = 0
    Width = 250
    Height = 273
    Anchors = [akLeft, akTop, akBottom]
    Checkboxes = True
    Columns = <
      item
        Caption = 'Name'
        Width = 146
      end
      item
        Alignment = taCenter
        Caption = 'Type'
        Width = 100
      end>
    ReadOnly = True
    RowSelect = True
    TabOrder = 0
    ViewStyle = vsReport
    OnClick = LVClick
  end
  object btOK: TButton
    Left = 256
    Top = 8
    Width = 113
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = btOKClick
  end
  object cbCreateAttributes: TCheckBox
    Left = 2
    Top = 280
    Width = 337
    Height = 17
    Caption = 'Create attributes i fvalue is not empty'
    Checked = True
    State = cbChecked
    TabOrder = 2
  end
  object cbText: TCheckBox
    Left = 2
    Top = 296
    Width = 337
    Height = 17
    Caption = 'Import text (not value)'
    TabOrder = 3
  end
  object cbType: TComboBox
    Left = 256
    Top = 48
    Width = 121
    Height = 21
    Enabled = False
    ItemHeight = 13
    ItemIndex = 2
    TabOrder = 4
    Text = 'String'
    OnCloseUp = cbTypeCloseUp
    Items.Strings = (
      'Integer'
      'Float'
      'String')
  end
end
