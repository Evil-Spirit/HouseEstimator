inherited MDITV: TMDITV
  Left = 693
  Top = 127
  BorderStyle = bsNone
  Caption = 'MDITV'
  ClientHeight = 284
  ClientWidth = 268
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  inherited Panel2: TPanel
    Width = 268
    Height = 258
    inherited View: TVisView
      Width = 266
      Height = 256
      Cursor = crSizeAll
      BackgroundColor = 11837067
      Coordinates.Visible = False
      Camera = _3DCamera
      Color = 11837067
    end
  end
  object pViewButtons: TPanel [1]
    Left = 0
    Top = 258
    Width = 268
    Height = 26
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    object Label1: TLabel
      Left = 8
      Top = 8
      Width = 3
      Height = 13
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGrayText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      Transparent = True
    end
    object Label2: TLabel
      Left = 64
      Top = 8
      Width = 3
      Height = 13
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGrayText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      Transparent = True
    end
    object Label3: TLabel
      Left = 216
      Top = 8
      Width = 32
      Height = 13
      Caption = 'Label1'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGrayText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      Transparent = True
    end
    object tbViewButtons: TToolBar
      Left = 204
      Top = 2
      Width = 62
      Height = 22
      Align = alRight
      AutoSize = True
      ButtonHeight = 30
      ButtonWidth = 31
      Caption = 'tbViewButtons'
      EdgeInner = esNone
      EdgeOuter = esNone
      Flat = True
      Images = ImageLibrary.ScrollImg
      TabOrder = 0
      object tbPlus: TToolButton
        Tag = 1
        Left = 0
        Top = 0
        Caption = 'tbPlus'
        ImageIndex = 6
        OnMouseDown = tbMinusMouseDown
        OnMouseUp = tbPlusMouseUp
      end
      object tbMinus: TToolButton
        Tag = -1
        Left = 31
        Top = 0
        Caption = 'tbMinus'
        ImageIndex = 5
        OnMouseDown = tbMinusMouseDown
        OnMouseUp = tbPlusMouseUp
      end
    end
  end
  inherited _3DCamera: TVisPerspectiveCamera
    Transformation.Rotation.X = 270
    Transformation.Rotation.Z = 45
    Transformation.Rotation.Y = 0
    Transformation.Translation.Z = -7.5
    Transformation.Translation.X = 0
    Transformation.Translation.Y = 0
    LA_Position.X = -7.5
    LA_Position.Y = -7.5
    LA_Position.Z = 5
    LA_LookAt.X = 0
    LA_LookAt.Y = 0
    LA_LookAt.Z = 0
    LA_UpNormal.X = 0
    LA_UpNormal.Y = 0
    ViewAngle = 45
    Top = 104
  end
  inherited Attr3D: TVisAttributes
    ColorAmbient.Alpha = 0.300000011920929
    ColorAmbient.Color = 0
  end
  inherited Light1: TVisLight [4]
    ColorAmbient.Color = clGray
    ColorAmbient.Alpha = 0.300000011920929
    ColorDiffuse.Alpha = 0.300000011920929
    ColorSpecular.Color = clWhite
    ColorSpecular.Alpha = 0.300000011920929
    Kind = lkDirection
    Direction.Z = 0.75
    Transformation.Rotation.X = 0
    Transformation.Rotation.Y = 0
    Transformation.Rotation.Z = 0
    Transformation.Translation.X = -100
    Transformation.Translation.Y = -50
    Left = 32
    Top = 32
  end
  inherited Light0: TVisLight [5]
    ColorAmbient.Color = clGray
    ColorAmbient.Alpha = 0.300000011920929
    ColorDiffuse.Alpha = 0.300000011920929
    ColorSpecular.Color = clWhite
    ColorSpecular.Alpha = 0.300000011920929
    Direction.Z = 0.75
    Transformation.Rotation.X = 0
    Transformation.Rotation.Y = 0
    Transformation.Rotation.Z = 0
    Transformation.Translation.X = 100
    Transformation.Translation.Y = 50
    Top = 32
  end
  inherited DiscInvisible: TVisDisc
    Enabled = False
    Transformation.Rotation.X = 0
    Transformation.Rotation.Y = 0
    Transformation.Rotation.Z = 0
    Transformation.Translation.Z = -0.5
    Transformation.Translation.X = 0
    Transformation.Translation.Y = 0
    TextureFlags.ParamVector.X = 0
    TextureFlags.ParamVector.Y = 0
    TextureFlags.ParamVector.Z = 0
    OuterRadius = 2
    Top = 104
    InnerRadius = 0
    StartAngle = 0
  end
  inherited MaterialInvisible: TVisMaterial
    ColorDiffuse.Alpha = 1
    ColorSpecular.Color = 0
    ColorEmission.Color = 0
    Top = 136
  end
  inherited _2DCamera: TVisOrthographicCamera
    Transformation.Rotation.X = 0
    Transformation.Rotation.Y = 0
    Transformation.Rotation.Z = 0
    Transformation.Translation.X = 0
    Transformation.Translation.Y = 0
    LA_Position.Z = -100
    LA_Position.X = 0
    LA_Position.Y = 0
    LA_LookAt.X = 0
    LA_LookAt.Y = 0
    LA_LookAt.Z = 0
    LA_UpNormal.X = 0
    LA_UpNormal.Y = 0
    ViewWidth = 5
    ViewHeight = 5
    Top = 104
  end
  inherited Attr2D: TVisAttributes
    ColorAmbient.Alpha = 0.300000011920929
    ColorAmbient.Color = 0
  end
  object VisNode: TVisNode
    Transformation.Rotation.X = 0
    Transformation.Rotation.Y = 0
    Transformation.Rotation.Z = 0
    Transformation.Scale.X = 1
    Transformation.Scale.Y = 1
    Transformation.Scale.Z = 1
    Transformation.Translation.X = 0
    Transformation.Translation.Y = 0
    Transformation.Translation.Z = 0
    Transformation.Order = toTraRotSca
    Left = 120
    Top = 72
  end
  object _Timer: TTimer
    Enabled = False
    Interval = 25
    OnTimer = _TimerTimer
    Left = 48
    Top = 176
  end
  object VisTexture1: TVisTexture
    MinFilter = tfLinear
    MagFilter = tfLinear
    Alpha = 1
    Mode = tmModulate
    BlendColor.Alpha = 1
    BlendColor.Color = 0
    Transformation.Rotation.X = 0
    Transformation.Rotation.Y = 0
    Transformation.Rotation.Z = 0
    Transformation.Scale.X = 1
    Transformation.Scale.Y = 1
    Transformation.Scale.Z = 1
    Transformation.Translation.X = 0
    Transformation.Translation.Y = 0
    Transformation.Translation.Z = 0
    Transformation.Order = toRotTraSca
    Left = 120
    Top = 104
  end
end
