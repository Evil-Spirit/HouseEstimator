inherited MDIMetaVisParam: TMDIMetaVisParam
  Left = 276
  Top = 190
  Caption = 'MDIMetaVisParam'
  Position = poDefault
  PixelsPerInch = 96
  TextHeight = 13
  inherited PCNode: TPageControl
    inherited tsAdvancedSuper: TTabSheet
      inherited Image1: TImage
        Top = 136
      end
    end
    object tsparam: TTabSheet
      Caption = 'Parameters'
      ImageIndex = 3
      object Label3: TLabel
        Left = 8
        Top = 16
        Width = 37
        Height = 13
        Caption = 'Material'
      end
      object Label4: TLabel
        Left = 200
        Top = 16
        Width = 36
        Height = 13
        Caption = 'Texture'
      end
      object TML: TPanel
        Left = 0
        Top = 66
        Width = 377
        Height = 217
        BevelOuter = bvNone
        Caption = 'TML'
        TabOrder = 0
      end
      object MAT: TPanel
        Left = 8
        Top = 32
        Width = 193
        Height = 33
        BevelOuter = bvNone
        Caption = 'MAT'
        TabOrder = 1
      end
      object TEX: TPanel
        Left = 200
        Top = 32
        Width = 193
        Height = 33
        BevelOuter = bvNone
        Caption = 'TEX'
        TabOrder = 2
      end
    end
  end
end
