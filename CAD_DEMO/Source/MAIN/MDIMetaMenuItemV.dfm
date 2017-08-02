inherited MDIMetaMenuItem: TMDIMetaMenuItem
  Caption = 'MDIMetaMenuItem'
  PixelsPerInch = 96
  TextHeight = 13
  inherited PCNode: TPageControl
    ActivePage = tsMain
    TabIndex = 0
    inherited tsMetaUI: TTabSheet
      object Label3: TLabel [0]
        Left = 24
        Top = 80
        Width = 28
        Height = 13
        Caption = 'Event'
      end
      object Label2: TLabel [1]
        Left = 24
        Top = 128
        Width = 97
        Height = 17
        AutoSize = False
        Caption = 'List of Pictures'
      end
      object MetaAction: TPanel
        Left = 120
        Top = 72
        Width = 193
        Height = 33
        BevelOuter = bvNone
        Caption = 'MetaAction'
        TabOrder = 2
      end
      object ChildBMPSet: TPanel
        Left = 120
        Top = 120
        Width = 193
        Height = 33
        BevelOuter = bvNone
        Caption = 'ChildBMPSet'
        TabOrder = 3
      end
    end
  end
end
