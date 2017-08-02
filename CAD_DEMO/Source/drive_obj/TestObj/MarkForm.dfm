object Form4: TForm4
  Left = 309
  Top = 224
  BorderStyle = bsDialog
  Caption = 'Mark Options'
  ClientHeight = 161
  ClientWidth = 216
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Accept: TBitBtn
    Left = 40
    Top = 120
    Width = 121
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Reference Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = AcceptClick
    Kind = bkOK
  end
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 8
    Width = 201
    Height = 57
    Caption = 'Mark by'
    TabOrder = 1
  end
  object RadioButton1: TRadioButton
    Left = 16
    Top = 24
    Width = 113
    Height = 17
    Caption = 'Index'
    Checked = True
    TabOrder = 2
    TabStop = True
  end
  object RadioButton2: TRadioButton
    Left = 16
    Top = 40
    Width = 161
    Height = 17
    Caption = 'FCuts.Count || FPlane.Count'
    TabOrder = 3
  end
  object LabeledEdit1: TLabeledEdit
    Left = 16
    Top = 88
    Width = 193
    Height = 21
    EditLabel.Width = 27
    EditLabel.Height = 13
    EditLabel.Caption = 'Value'
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 4
    Text = '0'
  end
end
