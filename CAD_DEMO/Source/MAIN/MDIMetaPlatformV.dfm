inherited MDIMetaPlatform: TMDIMetaPlatform
  Left = 278
  Top = 342
  Caption = 'MDIMetaPlatform'
  PixelsPerInch = 96
  TextHeight = 13
  inherited PCNode: TPageControl
    ActivePage = tsVisual
    TabIndex = 7
    object tsPlatform: TTabSheet
      Caption = 'Platform'
      ImageIndex = 4
      object cbFirst: TCheckBox
        Left = 24
        Top = 16
        Width = 89
        Height = 17
        Caption = 'Grid'
        TabOrder = 0
        OnClick = cbFirstClick
      end
      object cbLand: TCheckBox
        Left = 24
        Top = 40
        Width = 89
        Height = 17
        Caption = 'Landscape'
        TabOrder = 1
        OnClick = cbLandClick
      end
    end
  end
end
