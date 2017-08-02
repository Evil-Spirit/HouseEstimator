inherited MDI3DUser: TMDI3DUser
  Left = 498
  Top = 136
  Width = 466
  Height = 360
  Caption = 'MDI3DUser'
  FormStyle = fsMDIChild
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel [0]
    Left = 8
    Top = 8
    Width = 129
    Height = 33
    BevelOuter = bvNone
    Color = 11116182
    TabOrder = 0
    Visible = False
    object Label1: TLabel
      Left = 8
      Top = 8
      Width = 64
      Height = 13
      Caption = #1063#1080#1089#1083#1086' '#1091#1079#1083#1086#1074
    end
    object Label2: TLabel
      Left = 88
      Top = 8
      Width = 3
      Height = 13
    end
  end
  inherited Panel2: TPanel
    Width = 458
    Height = 333
    TabOrder = 1
    inherited View: TVisView
      Width = 456
      Height = 331
    end
  end
  inherited _3DCamera: TVisPerspectiveCamera
    Transformation.Rotation.X = 300
    Transformation.Rotation.Z = 0
    Transformation.Rotation.Y = 0
    Transformation.Rotation.Z = 0
    Transformation.Translation.Z = -16
    Transformation.Translation.X = 0
    Transformation.Translation.Y = 0
    LA_Position.X = -10
    LA_Position.Y = -10
    LA_Position.Z = 5
    LA_LookAt.X = 0
    LA_LookAt.Y = 0
    LA_LookAt.Z = 0
    LA_UpNormal.X = 0
    LA_UpNormal.Y = 0
    ViewAngle = 45
    Left = 88
  end
  inherited Attr3D: TVisAttributes
    ColorAmbient.Color = clSilver
    Left = 88
    Top = 168
  end
  inherited Light0: TVisLight
    ColorAmbient.Color = 0
    ColorDiffuse.Color = clSilver
    ColorSpecular.Color = clWhite
    Direction.Z = 0.75
    Transformation.Rotation.X = 0
    Transformation.Rotation.Y = 0
    Transformation.Rotation.Z = 0
    Transformation.Translation.X = 100
    Transformation.Translation.Y = 50
    Transformation.Translation.Z = 75
    Left = 48
    Top = 168
  end
  inherited Light1: TVisLight
    ColorAmbient.Color = 0
    ColorSpecular.Color = clWhite
    Direction.Z = 0.75
    Transformation.Rotation.X = 0
    Transformation.Rotation.Y = 0
    Transformation.Rotation.Z = 0
    Transformation.Translation.X = -100
    Transformation.Translation.Y = -50
    Transformation.Translation.Z = 75
    Left = 120
    Top = 136
  end
  inherited DiscInvisible: TVisDisc
    Transformation.Rotation.Order = roZXY
    Transformation.Rotation.X = 0
    Transformation.Rotation.Y = 0
    Transformation.Rotation.Z = 0
    Transformation.Translation.X = 0
    Transformation.Translation.Y = 0
    TextureFlags.ParamVector.X = 0
    TextureFlags.ParamVector.Y = 0
    TextureFlags.ParamVector.Z = 0
    Slices = 5
    Stacks = 5
    InnerRadius = 0
    StartAngle = 0
  end
  inherited MaterialInvisible: TVisMaterial
    Face = mfFrontBack
    ColorDiffuse.Color = 9079434
    ColorDiffuse.Alpha = 0
    ColorDiffuse.Alpha = 0
    ColorSpecular.Color = 0
    ColorEmission.Color = 0
  end
  inherited _2DCamera: TVisOrthographicCamera
    Transformation.Rotation.X = 0
    Transformation.Rotation.Y = 0
    Transformation.Rotation.Z = 0
    Transformation.Translation.X = 0
    Transformation.Translation.Y = 0
    LA_Position.X = 1
    LA_Position.Z = 50
    LA_Position.Y = 0
    LA_LookAt.X = 0
    LA_LookAt.Y = 0
    LA_LookAt.Z = 0
    LA_UpNormal.X = 0
    LA_UpNormal.Y = 0
    ViewWidth = 12.5
    ViewHeight = 12.5
  end
  inherited Attr2D: TVisAttributes
    ColorAmbient.Color = clSilver
  end
  object SaveDialog1: TSaveDialog
    FileName = 
      'C:\Documents and Settings\russ\'#1056#1072#1073#1086#1095#1080#1081' '#1089#1090#1086#1083'\'#1087#1088#1086#1073#1083#1077#1084#1072' '#1089' '#1092#1091#1085#1076#1072#1084#1077#1085#1090 +
      #1086#1084
    Filter = 'SOPOS Project (*.home)|*.home'
    Options = [ofOverwritePrompt, ofEnableSizing]
    Left = 160
    Top = 136
  end
end
