object MDITexture: TMDITexture
  Left = 156
  Top = 203
  Width = 400
  Height = 203
  Caption = 'MDITexture'
  Color = clBtnFace
  Constraints.MinHeight = 167
  Constraints.MinWidth = 179
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 128
    Top = 13
    Width = 60
    Height = 13
    Caption = 'ENV_MODE'
  end
  object Label2: TLabel
    Left = 0
    Top = 149
    Width = 64
    Height = 13
    Caption = 'MAG FILTER'
  end
  object Label3: TLabel
    Left = 208
    Top = 149
    Width = 60
    Height = 13
    Caption = 'MIN FILTER'
  end
  object GRAmbient: TGroupBox
    Left = 0
    Top = 32
    Width = 89
    Height = 73
    Caption = 'Ambient'
    TabOrder = 0
    object Blend: TShape
      Left = 16
      Top = 16
      Width = 57
      Height = 25
      OnMouseDown = BlendMouseDown
    end
    object BlendA: TTrackBar
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
      OnChange = BlendAChange
    end
  end
  object Alpha: TTrackBar
    Left = 8
    Top = 112
    Width = 73
    Height = 17
    Max = 1000
    Orientation = trHorizontal
    PageSize = 1
    Frequency = 1
    Position = 0
    SelEnd = 0
    SelStart = 0
    TabOrder = 1
    ThumbLength = 15
    TickMarks = tmBoth
    TickStyle = tsNone
    OnChange = BlendAChange
  end
  object GroupBox1: TGroupBox
    Left = 96
    Top = 32
    Width = 97
    Height = 105
    Caption = 'Rotation'
    TabOrder = 2
    object RotX: TTrackBar
      Left = 8
      Top = 16
      Width = 17
      Height = 81
      Max = 360
      Orientation = trVertical
      PageSize = 1
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      ThumbLength = 15
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = BlendAChange
    end
    object RotY: TTrackBar
      Left = 36
      Top = 16
      Width = 23
      Height = 82
      Max = 360
      Orientation = trVertical
      PageSize = 1
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 1
      ThumbLength = 15
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = BlendAChange
    end
    object RotZ: TTrackBar
      Left = 64
      Top = 16
      Width = 23
      Height = 82
      Max = 360
      Orientation = trVertical
      PageSize = 1
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 2
      ThumbLength = 15
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = BlendAChange
    end
  end
  object CBE: TComboBox
    Left = 192
    Top = 8
    Width = 193
    Height = 22
    Style = csOwnerDrawFixed
    ItemHeight = 16
    TabOrder = 3
    OnChange = BlendAChange
  end
  object GroupBox2: TGroupBox
    Left = 192
    Top = 32
    Width = 97
    Height = 105
    Caption = 'Scale'
    TabOrder = 4
    object ScaX: TTrackBar
      Left = 8
      Top = 16
      Width = 17
      Height = 82
      Max = 500
      Min = -500
      Orientation = trVertical
      PageSize = 1
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      ThumbLength = 15
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = BlendAChange
    end
    object ScaY: TTrackBar
      Left = 40
      Top = 16
      Width = 17
      Height = 82
      Max = 500
      Min = -500
      Orientation = trVertical
      PageSize = 1
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 1
      ThumbLength = 15
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = BlendAChange
    end
    object ScaZ: TTrackBar
      Left = 71
      Top = 16
      Width = 17
      Height = 82
      Max = 500
      Min = -500
      Orientation = trVertical
      PageSize = 1
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 2
      ThumbLength = 15
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = BlendAChange
    end
  end
  object GroupBox3: TGroupBox
    Left = 288
    Top = 32
    Width = 97
    Height = 105
    Caption = 'Position'
    TabOrder = 5
    object PosX: TTrackBar
      Left = 8
      Top = 16
      Width = 17
      Height = 82
      Max = 500
      Min = -500
      Orientation = trVertical
      PageSize = 1
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      ThumbLength = 15
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = BlendAChange
    end
    object PosY: TTrackBar
      Left = 40
      Top = 16
      Width = 17
      Height = 82
      Max = 500
      Min = -500
      Orientation = trVertical
      PageSize = 1
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 1
      ThumbLength = 15
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = BlendAChange
    end
    object PosZ: TTrackBar
      Left = 72
      Top = 16
      Width = 17
      Height = 82
      Max = 500
      Min = -500
      Orientation = trVertical
      PageSize = 1
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 2
      ThumbLength = 15
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = BlendAChange
    end
  end
  object cbMAG: TComboBox
    Left = 71
    Top = 144
    Width = 114
    Height = 22
    Style = csOwnerDrawFixed
    ItemHeight = 16
    TabOrder = 6
    OnChange = BlendAChange
  end
  object cbMIN: TComboBox
    Left = 271
    Top = 144
    Width = 114
    Height = 22
    Style = csOwnerDrawFixed
    ItemHeight = 16
    TabOrder = 7
    OnChange = BlendAChange
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
    Left = 24
    Top = 47
  end
end
