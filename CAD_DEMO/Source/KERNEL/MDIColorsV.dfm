object MDIColors: TMDIColors
  Left = 454
  Top = 131
  BorderStyle = bsSingle
  Caption = 'MDIColors'
  ClientHeight = 119
  ClientWidth = 355
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 96
    Top = 72
    Width = 257
    Height = 41
    Caption = 'Face'
    TabOrder = 5
    object cbFace: TComboBox
      Left = 16
      Top = 12
      Width = 225
      Height = 21
      ItemHeight = 13
      TabOrder = 0
      Text = 'cbFace'
      OnChange = ShininessChange
    end
  end
  object GBDiffuse: TGroupBox
    Left = 88
    Top = 0
    Width = 89
    Height = 73
    Caption = 'Diffuse'
    TabOrder = 1
    object Diffuse: TShape
      Left = 16
      Top = 16
      Width = 57
      Height = 25
      OnMouseDown = AmbientMouseDown
    end
    object DiffuseA: TTrackBar
      Left = 8
      Top = 48
      Width = 73
      Height = 17
      Max = 1000
      Orientation = trHorizontal
      PageSize = 1
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      ThumbLength = 15
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = ShininessChange
    end
  end
  object GBSpecular: TGroupBox
    Left = 176
    Top = 0
    Width = 89
    Height = 73
    Caption = 'Specular'
    TabOrder = 2
    object Specular: TShape
      Left = 16
      Top = 16
      Width = 57
      Height = 25
      OnMouseDown = AmbientMouseDown
    end
    object SpecularA: TTrackBar
      Left = 8
      Top = 48
      Width = 73
      Height = 17
      Max = 1000
      Orientation = trHorizontal
      PageSize = 1
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      ThumbLength = 15
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = ShininessChange
    end
  end
  object GREmission: TGroupBox
    Left = 264
    Top = 0
    Width = 89
    Height = 73
    Caption = 'Emission'
    TabOrder = 3
    object Emission: TShape
      Left = 16
      Top = 16
      Width = 57
      Height = 25
      OnMouseDown = AmbientMouseDown
    end
    object EmissionA: TTrackBar
      Left = 8
      Top = 48
      Width = 73
      Height = 17
      Max = 1000
      Orientation = trHorizontal
      PageSize = 1
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      ThumbLength = 15
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = ShininessChange
    end
  end
  object GRShininess: TGroupBox
    Left = 0
    Top = 72
    Width = 89
    Height = 41
    Caption = 'Shininess'
    TabOrder = 4
    object Shininess: TTrackBar
      Left = 8
      Top = 16
      Width = 73
      Height = 17
      Max = 20000
      Orientation = trHorizontal
      PageSize = 1
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      ThumbLength = 15
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = ShininessChange
    end
  end
  object GRAmbient: TGroupBox
    Left = 0
    Top = 0
    Width = 89
    Height = 73
    Caption = 'Ambient'
    TabOrder = 0
    object Ambient: TShape
      Left = 16
      Top = 16
      Width = 57
      Height = 25
      OnMouseDown = AmbientMouseDown
    end
    object AmbientA: TTrackBar
      Left = 8
      Top = 48
      Width = 73
      Height = 17
      Max = 1000
      Orientation = trHorizontal
      PageSize = 1
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      ThumbLength = 15
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = ShininessChange
    end
  end
  object ColorDialog: TColorDialog
    Ctl3D = True
    CustomColors.Strings = (
      'ColorA=000000'
      'ColorB=FFFFFFFF'
      'ColorC=FFFFFFFF'
      'ColorD=FFFFFFFF'
      'ColorE=FFFFFFFF'
      'ColorF=FFFFFFFF'
      'ColorG=FFFFFFFF'
      'ColorH=FFFFFFFF'
      'ColorI=FFFFFFFF'
      'ColorJ=FFFFFFFF'
      'ColorK=FFFFFFFF'
      'ColorL=FFFFFFFF'
      'ColorM=FFFFFFFF'
      'ColorN=FFFFFFFF'
      'ColorO=FFFFFFFF'
      'ColorP=FFFFFFFF')
    Left = 304
    Top = 16
  end
end
