object GenImage: TGenImage
  Left = 233
  Top = 150
  BorderStyle = bsDialog
  Caption = 'GenImage'
  ClientHeight = 278
  ClientWidth = 544
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 138
    Top = 80
    Width = 31
    Height = 13
    Caption = 'Width:'
  end
  object Label2: TLabel
    Left = 138
    Top = 104
    Width = 34
    Height = 13
    Caption = 'Height:'
  end
  object lWidth: TLabel
    Left = 202
    Top = 80
    Width = 6
    Height = 13
    Caption = '0'
  end
  object lHeight: TLabel
    Left = 202
    Top = 104
    Width = 6
    Height = 13
    Caption = '0'
  end
  object sColor: TShape
    Left = 82
    Top = 80
    Width = 41
    Height = 33
    OnMouseDown = sColorMouseDown
  end
  object Label5: TLabel
    Left = 16
    Top = 88
    Width = 58
    Height = 13
    Caption = 'Background'
  end
  object LIST: TPanel
    Left = 8
    Top = 16
    Width = 249
    Height = 49
    BevelOuter = bvNone
    Caption = 'LIST'
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 275
    Top = 8
    Width = 260
    Height = 260
    BevelOuter = bvLowered
    TabOrder = 1
    object Image: TImage
      Left = 1
      Top = 1
      Width = 105
      Height = 105
      Center = True
      Constraints.MaxHeight = 260
      Constraints.MaxWidth = 260
      Constraints.MinHeight = 16
      Constraints.MinWidth = 16
      Stretch = True
      OnMouseDown = ImageMouseDown
    end
  end
  object btGen: TButton
    Left = 176
    Top = 240
    Width = 89
    Height = 25
    Caption = 'Generate'
    Enabled = False
    TabOrder = 2
    OnClick = btGenClick
  end
  object btCancel: TButton
    Left = 88
    Top = 240
    Width = 81
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object cbAA: TCheckBox
    Left = 8
    Top = 128
    Width = 97
    Height = 17
    Caption = 'Anti-aliasing'
    TabOrder = 4
  end
  object cbSmooth: TCheckBox
    Left = 120
    Top = 128
    Width = 97
    Height = 17
    Caption = 'Smooth'
    TabOrder = 5
  end
  object btOK: TButton
    Left = 8
    Top = 240
    Width = 75
    Height = 25
    Caption = 'OK'
    Enabled = False
    ModalResult = 1
    TabOrder = 6
  end
  object cbAntiAliasingLine: TCheckBox
    Left = 8
    Top = 152
    Width = 153
    Height = 17
    Caption = 'Anti-aliasing lines'
    TabOrder = 7
  end
  object ColorDialog1: TColorDialog
    Ctl3D = True
    Left = 8
    Top = 192
  end
end
