object Form3: TForm3
  Left = 337
  Top = 202
  BorderStyle = bsDialog
  Caption = 'Vector'
  ClientHeight = 196
  ClientWidth = 150
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object EditX: TLabeledEdit
    Left = 16
    Top = 32
    Width = 121
    Height = 21
    EditLabel.Width = 25
    EditLabel.Height = 13
    EditLabel.Caption = 'EditX'
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 0
    Text = '0'
  end
  object EditY: TLabeledEdit
    Left = 16
    Top = 72
    Width = 121
    Height = 21
    EditLabel.Width = 25
    EditLabel.Height = 13
    EditLabel.Caption = 'EditY'
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 1
    Text = '0'
  end
  object EditZ: TLabeledEdit
    Left = 16
    Top = 112
    Width = 121
    Height = 21
    EditLabel.Width = 25
    EditLabel.Height = 13
    EditLabel.Caption = 'EditZ'
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 2
    Text = '0'
  end
  object Accept: TBitBtn
    Left = 16
    Top = 152
    Width = 121
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Reference Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = AcceptClick
    Kind = bkOK
  end
end
