object MDIViewSettings: TMDIViewSettings
  Left = 338
  Top = 236
  BorderStyle = bsDialog
  Caption = 'MDIViewSettings'
  ClientHeight = 240
  ClientWidth = 413
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 413
    Height = 97
    Align = alTop
    Caption = '2D Mode'
    TabOrder = 0
    object Label1: TLabel
      Left = 9
      Top = 20
      Width = 87
      Height = 13
      Caption = 'Background color:'
    end
    object Label2: TLabel
      Left = 48
      Top = 60
      Width = 48
      Height = 13
      Caption = 'Grid color:'
    end
    object shBackColor2d: TShape
      Left = 101
      Top = 16
      Width = 65
      Height = 25
      OnMouseDown = shBackColor2dMouseDown
    end
    object shNetColor2d: TShape
      Left = 101
      Top = 56
      Width = 65
      Height = 25
      OnMouseDown = shBackColor2dMouseDown
    end
    object rbPoints2d: TRadioButton
      Left = 240
      Top = 24
      Width = 113
      Height = 17
      Caption = 'rbPoints2d'
      TabOrder = 0
    end
    object rbLines2d: TRadioButton
      Left = 240
      Top = 56
      Width = 113
      Height = 17
      Caption = 'rbLines2d'
      TabOrder = 1
    end
  end
  object GroupBox2: TGroupBox
    Left = 0
    Top = 97
    Width = 413
    Height = 97
    Align = alTop
    Caption = '3D Mode'
    TabOrder = 1
    object Label3: TLabel
      Left = 8
      Top = 20
      Width = 87
      Height = 13
      Caption = 'Background color:'
    end
    object Label4: TLabel
      Left = 47
      Top = 60
      Width = 48
      Height = 13
      Caption = 'Grid color:'
    end
    object shBackColor3d: TShape
      Left = 101
      Top = 16
      Width = 65
      Height = 25
      OnMouseDown = shBackColor2dMouseDown
    end
    object shNetColor3d: TShape
      Left = 101
      Top = 56
      Width = 65
      Height = 25
      OnMouseDown = shBackColor2dMouseDown
    end
    object rbPoints3d: TRadioButton
      Left = 240
      Top = 24
      Width = 113
      Height = 17
      Caption = 'rbPoints2d'
      TabOrder = 0
    end
    object rbLines3d: TRadioButton
      Left = 240
      Top = 56
      Width = 113
      Height = 17
      Caption = 'rbLines2d'
      TabOrder = 1
    end
  end
  object btOK: TBitBtn
    Left = 120
    Top = 208
    Width = 75
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 2
  end
  object btCancel: TBitBtn
    Left = 208
    Top = 208
    Width = 75
    Height = 25
    Cancel = True
    Caption = #1054#1090#1084#1077#1085#1072
    ModalResult = 2
    TabOrder = 3
    NumGlyphs = 2
  end
  object CD: TColorDialog
    Ctl3D = True
    Left = 368
    Top = 16
  end
end
