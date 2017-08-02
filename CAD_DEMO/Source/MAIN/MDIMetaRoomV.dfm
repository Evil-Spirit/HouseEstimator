inherited MDIMetaRoom: TMDIMetaRoom
  Left = 159
  Top = 85
  Width = 819
  Height = 524
  Caption = 'MDIMetaRoom'
  PixelsPerInch = 96
  TextHeight = 13
  inherited Splitter1: TSplitter
    Left = 545
    Height = 446
  end
  inherited PCNode: TPageControl
    Width = 545
    Height = 446
    inherited tsInterface: TTabSheet
      inherited MAS: TPanel
        Width = 537
        Height = 367
      end
      inherited pInterface: TPanel
        Width = 537
      end
    end
    inherited tsAttributes: TTabSheet
      inherited Splitter2: TSplitter
        Width = 537
      end
      inherited Attributes: TPanel
        Width = 537
      end
      inherited TB: TPanel
        Width = 537
        Height = 255
      end
    end
    inherited tsDrawView: TTabSheet
      inherited PanelDraw: TPanel
        Width = 537
        Height = 400
      end
    end
    object tsRoom: TTabSheet
      Caption = 'Area'
      ImageIndex = 4
      DesignSize = (
        537
        400)
      object LV: TListView
        Left = 0
        Top = 32
        Width = 264
        Height = 366
        Anchors = [akLeft, akTop, akRight, akBottom]
        Columns = <
          item
            Width = 230
          end>
        DragMode = dmAutomatic
        FullDrag = True
        HideSelection = False
        ReadOnly = True
        RowSelect = True
        ShowColumnHeaders = False
        TabOrder = 0
        ViewStyle = vsReport
      end
      object ToolBar1: TToolBar
        Left = 269
        Top = 9
        Width = 43
        Height = 38
        Align = alNone
        AutoSize = True
        ButtonHeight = 19
        ButtonWidth = 43
        Caption = 'ToolBar1'
        EdgeBorders = []
        Flat = True
        List = True
        ShowCaptions = True
        TabOrder = 1
        object tbtAdd: TToolButton
          Left = 0
          Top = 0
          Caption = 'Add'
          ImageIndex = 0
          Wrap = True
          OnClick = tbtAddClick
        end
        object tbtDel: TToolButton
          Left = 0
          Top = 19
          Caption = 'Delete'
          ImageIndex = 2
          OnClick = tbtDelClick
        end
      end
      object cbDM: TComboBox
        Left = 0
        Top = 8
        Width = 264
        Height = 21
        ItemHeight = 13
        TabOrder = 2
        Items.Strings = (
          #1054#1073#1083#1072#1089#1090#1100' '#1086#1075#1088#1072#1085#1080#1095#1077#1085#1085#1072#1103
          #1054#1073#1083#1072#1089#1090#1100' '#1079#1072#1085#1103#1090#1072#1103)
      end
    end
  end
  inherited Panel1: TPanel
    Top = 446
    Width = 801
  end
  inherited Panel2: TPanel
    Left = 553
    Width = 248
    Height = 446
  end
end
