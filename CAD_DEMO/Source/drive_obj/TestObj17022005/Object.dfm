object Form1: TForm1
  Left = 200
  Top = 219
  Width = 689
  Height = 474
  Caption = 'Geometric Core Test'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar1: TStatusBar
    Left = 0
    Top = 408
    Width = 681
    Height = 20
    Panels = <
      item
        Width = 100
      end
      item
        Width = 100
      end>
    SimplePanel = False
  end
  object PointMaterial: TVisMaterial
    Face = mfFront
    ColorAmbient.Alpha = 1
    ColorAmbient.Color = 0
    ColorDiffuse.Color = clRed
    ColorDiffuse.Alpha = 1
    ColorSpecular.Alpha = 1
    ColorSpecular.Color = 0
    ColorEmission.Color = clRed
    ColorEmission.Alpha = 1
    Shininess = 0
    Cached = False
    Left = 128
    Top = 40
  end
  object MaterialOther: TVisMaterial
    Face = mfFront
    ColorAmbient.Color = clYellow
    ColorAmbient.Alpha = 1
    ColorDiffuse.Color = clYellow
    ColorDiffuse.Alpha = 1
    ColorSpecular.Alpha = 1
    ColorSpecular.Color = 0
    ColorEmission.Color = clYellow
    ColorEmission.Alpha = 1
    Shininess = 0
    Cached = False
    Left = 160
    Top = 40
  end
  object PolygonMaterial: TVisMaterial
    Face = mfFront
    ColorAmbient.Alpha = 1
    ColorAmbient.Color = 0
    ColorDiffuse.Color = clSkyBlue
    ColorDiffuse.Alpha = 1
    ColorSpecular.Alpha = 1
    ColorSpecular.Color = 0
    ColorEmission.Alpha = 1
    ColorEmission.Color = 0
    Shininess = 0
    Cached = False
    Left = 192
    Top = 40
  end
  object MaterialLeft: TVisMaterial
    Face = mfFront
    ColorAmbient.Color = 3355443
    ColorAmbient.Alpha = 1
    ColorDiffuse.Color = clBlue
    ColorDiffuse.Alpha = 1
    ColorSpecular.Alpha = 1
    ColorSpecular.Color = 0
    ColorEmission.Color = clBlue
    ColorEmission.Alpha = 1
    Shininess = 0
    Cached = False
    Left = 128
    Top = 80
  end
  object MaterialRight: TVisMaterial
    Face = mfFront
    ColorAmbient.Color = 3355443
    ColorAmbient.Alpha = 1
    ColorDiffuse.Color = clRed
    ColorDiffuse.Alpha = 1
    ColorSpecular.Alpha = 1
    ColorSpecular.Color = 0
    ColorEmission.Color = clRed
    ColorEmission.Alpha = 1
    Shininess = 0
    Cached = False
    Left = 160
    Top = 80
  end
  object MaterialItr: TVisMaterial
    Face = mfFront
    ColorAmbient.Color = 3355443
    ColorAmbient.Alpha = 1
    ColorDiffuse.Color = clFuchsia
    ColorDiffuse.Alpha = 1
    ColorSpecular.Alpha = 1
    ColorSpecular.Color = 0
    ColorEmission.Color = clFuchsia
    ColorEmission.Alpha = 1
    Shininess = 0
    Cached = False
    Left = 192
    Top = 80
  end
  object MaterialPolyLeft: TVisMaterial
    Face = mfFrontBack
    ColorAmbient.Color = 3355443
    ColorAmbient.Alpha = 1
    ColorDiffuse.Color = clBlue
    ColorDiffuse.Alpha = 1
    ColorSpecular.Alpha = 1
    ColorSpecular.Color = 0
    ColorEmission.Alpha = 1
    ColorEmission.Color = 0
    Shininess = 0
    Cached = False
    Left = 224
    Top = 40
  end
  object MaterialPolyRight: TVisMaterial
    Face = mfFrontBack
    ColorAmbient.Color = 3355443
    ColorAmbient.Alpha = 1
    ColorDiffuse.Color = clRed
    ColorDiffuse.Alpha = 1
    ColorSpecular.Alpha = 1
    ColorSpecular.Color = 0
    ColorEmission.Alpha = 1
    ColorEmission.Color = 0
    Shininess = 0
    Cached = False
    Left = 256
    Top = 40
  end
  object MainMenu1: TMainMenu
    Left = 96
    Top = 40
    object Object1: TMenuItem
      Caption = '&File'
      object Load1: TMenuItem
        AutoHotkeys = maAutomatic
        Caption = '&Open'
        ShortCut = 16463
        OnClick = Load1Click
      end
      object Save1: TMenuItem
        AutoHotkeys = maAutomatic
        Caption = '&Save'
        ShortCut = 16467
        OnClick = Save1Click
      end
      object SavePolygonAsFigure1: TMenuItem
        Caption = 'Save&PolygonAsFigure'
        OnClick = SavePolygonAsFigure1Click
      end
      object SaveObjectAsFigure1: TMenuItem
        Caption = 'Save&ObjectAsFigure'
        OnClick = SaveObjectAsFigure1Click
      end
      object Convert1: TMenuItem
        Caption = '&Convert'
        OnClick = Convert1Click
      end
      object Clear1: TMenuItem
        AutoHotkeys = maAutomatic
        Caption = '&Reset'
        ShortCut = 16466
        OnClick = Clear1Click
      end
    end
    object Create1: TMenuItem
      Caption = 'Edit'
      object objClear1: TMenuItem
        Caption = '&Clear'
        OnClick = objClear1Click
      end
      object Extrude1: TMenuItem
        Caption = 'E&xtrude'
        OnClick = Extrude1Click
      end
      object Rotate1: TMenuItem
        Caption = '&Rotate'
        OnClick = Rotate1Click
      end
      object Move1: TMenuItem
        Caption = '&Move'
        OnClick = Move1Click
      end
      object ScaleTo1: TMenuItem
        Caption = '&ScaleTo'
        OnClick = ScaleTo1Click
      end
      object objSpiltByPlane1: TMenuItem
        Caption = 'S&piltByPlane'
        OnClick = objSpiltByPlane1Click
      end
      object objSliceByPlane1: TMenuItem
        Caption = 'S&liceByPlane'
        OnClick = objSliceByPlane1Click
      end
      object Info1: TMenuItem
        Caption = '&Info'
        OnClick = Info1Click
      end
      object PolygonPlaceOnPlane1: TMenuItem
        Caption = 'Polygon.PlaceOnPlane'
        OnClick = PolygonPlaceOnPlane1Click
      end
      object TransformToPlane1: TMenuItem
        Caption = 'TransformToPlane'
        OnClick = TransformToPlane1Click
      end
      object AnalyticalRender1: TMenuItem
        Caption = 'AnalyticalRender'
        OnClick = AnalyticalRender1Click
      end
    end
    object Primitive1: TMenuItem
      Caption = '&Primitive'
      object Square1: TMenuItem
        Caption = '&Square'
        OnClick = Square1Click
      end
      object Circle1: TMenuItem
        Caption = '&Circle'
        OnClick = Circle1Click
      end
      object Ring1: TMenuItem
        Caption = '&Ring'
        OnClick = Ring1Click
      end
      object HoledRing1: TMenuItem
        Caption = '&HoledRing'
        OnClick = HoledRing1Click
      end
      object HoledXRing1: TMenuItem
        Caption = '&XRing'
        OnClick = HoledXRing1Click
      end
      object Pyramid1: TMenuItem
        Caption = '&Pyramid'
        OnClick = Pyramid1Click
      end
    end
    object Operation1: TMenuItem
      Caption = '&Optimize'
      object Optimize1: TMenuItem
        Caption = '&Optimize'
        OnClick = Optimize1Click
      end
      object DetectHolesAtAll1: TMenuItem
        Caption = '&DetectHolesAtAll'
        OnClick = DetectHolesAtAll1Click
      end
      object CrossCutsAtAll1: TMenuItem
        Caption = 'Cr&ossCutsAtAll'
        OnClick = CrossCutsAtAll1Click
      end
      object WeldPointsAtAll1: TMenuItem
        Caption = '&WeldPointsAtAll'
        Enabled = False
        OnClick = WeldPointsAtAll1Click
      end
      object objSolidCheck1: TMenuItem
        Caption = 'Solid&Check'
        OnClick = objSolidCheck1Click
      end
      object obj1: TMenuItem
        Caption = 'Solid&Fix'
        OnClick = obj1Click
      end
      object RefreshView1: TMenuItem
        Caption = '&RefreshView'
        OnClick = RefreshView1Click
      end
      object SyncronizePolygonsWises1: TMenuItem
        Caption = 'S&yncronizePolygonsWises'
        OnClick = SyncronizePolygonsWises1Click
      end
      object Triangulate1: TMenuItem
        Caption = 'Triangulate'
        OnClick = Triangulate1Click
      end
      object CalculateNormals1: TMenuItem
        Caption = 'Calculate&Normals'
        OnClick = CalculateNormals1Click
      end
      object FreeUnused1: TMenuItem
        Caption = 'Free&Unused'
        OnClick = FreeUnused1Click
      end
    end
    object Object2: TMenuItem
      Caption = 'Ob&ject'
      Checked = True
      RadioItem = True
      object N11: TMenuItem
        AutoCheck = True
        Caption = '&A'
        Checked = True
        RadioItem = True
        OnClick = N11Click
      end
      object N21: TMenuItem
        AutoCheck = True
        Caption = '&B'
        RadioItem = True
        OnClick = N21Click
      end
    end
    object Boolean1: TMenuItem
      Caption = '&Boolean'
      object AB1: TMenuItem
        Caption = 'A &xor B'
        OnClick = AB1Click
      end
      object AB2: TMenuItem
        Caption = '&A minus B'
        OnClick = AB2Click
      end
      object BA1: TMenuItem
        Caption = '&B minus A'
        OnClick = BA1Click
      end
      object AB3: TMenuItem
        Caption = 'A a&nd B'
        OnClick = AB3Click
      end
    end
    object Render1: TMenuItem
      Caption = '&Render'
      object Points1: TMenuItem
        AutoCheck = True
        Caption = '&Points'
        Checked = True
        OnClick = Points1Click
      end
      object Cuts1: TMenuItem
        AutoCheck = True
        Caption = '&Cuts'
        Checked = True
        OnClick = Cuts1Click
      end
      object Polygons1: TMenuItem
        AutoCheck = True
        Caption = 'Pol&ygons'
        Checked = True
        OnClick = Polygons1Click
      end
      object Normals1: TMenuItem
        AutoCheck = True
        Caption = '&Normals'
        Checked = True
        OnClick = Normals1Click
      end
      object Holes1: TMenuItem
        AutoCheck = True
        Caption = '&Holes'
        Checked = True
        OnClick = Holes1Click
      end
      object fg1: TMenuItem
        Caption = '**********'
        Enabled = False
      end
      object Mark2: TMenuItem
        AutoCheck = True
        Caption = '&Mark'
        Checked = True
        RadioItem = True
        OnClick = Mark2Click
      end
      object Classify1: TMenuItem
        AutoCheck = True
        Caption = 'C&lassify'
        RadioItem = True
        OnClick = Classify1Click
      end
      object Error1: TMenuItem
        AutoCheck = True
        Caption = '&Error'
        RadioItem = True
        OnClick = Error1Click
      end
      object Smooth1: TMenuItem
        AutoCheck = True
        Caption = '&Smooth'
        RadioItem = True
        OnClick = Smooth1Click
      end
      object Color1: TMenuItem
        AutoCheck = True
        Caption = 'C&olor'
        RadioItem = True
        OnClick = Color1Click
      end
    end
    object Mark1: TMenuItem
      Caption = '&Mark'
      object Point1: TMenuItem
        Caption = '&Point'
        OnClick = Point1Click
      end
      object Cut1: TMenuItem
        Caption = '&Cut'
        OnClick = Cut1Click
      end
      object Polygon1: TMenuItem
        Caption = 'Pol&ygon'
        OnClick = Polygon1Click
      end
      object ClearMarks1: TMenuItem
        Caption = '&Clear'
        OnClick = ClearMarks1Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = '*.sgo'
    Filter = 
      'All Supported|*.sgo;*.gob|Old SOPOS Geometry|*.sgo|New SOPOS Geo' +
      'metry|*.gob'
    OptionsEx = [ofExNoPlacesBar]
    Title = #1054#1090#1082#1088#1099#1090#1100' SGO - '#1075#1077#1086#1084#1077#1090#1088#1080#1102
    Left = 128
    Top = 112
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '*.gob'
    Filter = 'SOPOS Geometry Object|*.gob'
    OptionsEx = [ofExNoPlacesBar]
    Title = #1057#1086#1093#1088#1072#1085#1080#1090#1100' Geometry Object'
    Left = 160
    Top = 112
  end
  object OpenDialog2: TOpenDialog
    DefaultExt = '*.sgo'
    Filter = 'Old SOPOS Geometry|*.sgo'
    Options = [ofHideReadOnly, ofAllowMultiSelect, ofEnableSizing]
    OptionsEx = [ofExNoPlacesBar]
    Title = #1054#1090#1082#1088#1099#1090#1100' SGO - '#1075#1077#1086#1084#1077#1090#1088#1080#1102
    Left = 192
    Top = 112
  end
  object VisTexture1: TVisTexture
    MinFilter = tfLinear_Linear
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
    Left = 288
    Top = 40
  end
  object HoleMaterial: TVisMaterial
    Face = mfFront
    ColorAmbient.Color = 3355443
    ColorAmbient.Alpha = 1
    ColorDiffuse.Color = clTeal
    ColorDiffuse.Alpha = 0.5
    ColorSpecular.Alpha = 1
    ColorSpecular.Color = 0
    ColorEmission.Alpha = 1
    ColorEmission.Color = 0
    Shininess = 0
    Cached = False
    Left = 224
    Top = 80
  end
  object MaterialMark: TVisMaterial
    Face = mfFrontBack
    ColorAmbient.Color = 3355443
    ColorAmbient.Alpha = 1
    ColorDiffuse.Color = clLime
    ColorDiffuse.Alpha = 1
    ColorSpecular.Alpha = 1
    ColorSpecular.Color = 0
    ColorEmission.Color = clLime
    ColorEmission.Alpha = 1
    Shininess = 0
    Cached = False
    Left = 256
    Top = 80
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 250
    OnTimer = Timer1Timer
    Left = 88
    Top = 72
  end
end
