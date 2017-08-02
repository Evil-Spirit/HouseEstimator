inherited MDIMetaToolEdit: TMDIMetaToolEdit
  Caption = 'MDIMetaToolEdit'
  Position = poDefault
  PixelsPerInch = 96
  TextHeight = 13
  inherited PCNode: TPageControl
    object tsMetaTool: TTabSheet
      Caption = 'Tools'
      ImageIndex = 3
    end
  end
end
