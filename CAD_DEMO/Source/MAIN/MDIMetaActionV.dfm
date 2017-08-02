inherited MDIMetaAction: TMDIMetaAction
  Caption = 'MDIMetaAction'
  Position = poDefault
  PixelsPerInch = 96
  TextHeight = 13
  inherited PCNode: TPageControl
    object tsAction: TTabSheet
      Caption = 'Picture Index'
      ImageIndex = 2
      object StaticText1: TStaticText
        Left = 16
        Top = 64
        Width = 153
        Height = 49
        AutoSize = False
        Caption = 'For adding module use method'
        TabOrder = 0
      end
      object cbeUserImage: TComboBoxEx
        Left = 112
        Top = 24
        Width = 57
        Height = 22
        ItemsEx.CaseSensitive = False
        ItemsEx.SortType = stNone
        ItemsEx = <>
        StyleEx = []
        Ctl3D = True
        ItemHeight = 16
        ParentColor = True
        ParentCtl3D = False
        TabOrder = 1
        Images = Config.UserImages
        DropDownCount = 8
      end
      object cbEnabled: TCheckBox
        Left = 16
        Top = 16
        Width = 89
        Height = 17
        Caption = 'Enabled'
        TabOrder = 2
      end
      object cbVisible: TCheckBox
        Left = 16
        Top = 40
        Width = 89
        Height = 17
        Caption = 'Visible'
        TabOrder = 3
      end
    end
  end
end
