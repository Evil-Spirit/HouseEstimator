object frmWizard3DSImport: TfrmWizard3DSImport
  Left = 108
  Top = 180
  Width = 1125
  Height = 577
  Caption = 'Import scene'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object pcSteps: TPageControl
    Left = 0
    Top = 0
    Width = 521
    Height = 550
    ActivePage = tsSelectMaterial
    Align = alLeft
    MultiLine = True
    TabOrder = 0
    OnChange = pcStepsChange
    object tsSelectObjects: TTabSheet
      Caption = 'Step 1'
      TabVisible = False
      DesignSize = (
        513
        540)
      object Head1: TLabel
        Left = 8
        Top = 8
        Width = 214
        Height = 24
        Caption = 'Step 1 - Select Objects'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label1: TLabel
        Left = 8
        Top = 40
        Width = 192
        Height = 13
        Caption = 'Please, select objects you want to import'
      end
      object lvObjectsList: TListView
        Left = 8
        Top = 64
        Width = 489
        Height = 466
        Anchors = [akLeft, akTop, akBottom]
        BevelKind = bkFlat
        BorderStyle = bsNone
        Checkboxes = True
        Columns = <
          item
            Width = -1
            WidthType = (
              -1)
          end>
        ColumnClick = False
        RowSelect = True
        ShowColumnHeaders = False
        TabOrder = 0
        ViewStyle = vsReport
        OnChange = lvObjectsListChange
      end
    end
    object tsSelectMaterial: TTabSheet
      Caption = 'Step 2'
      ImageIndex = 1
      TabVisible = False
      DesignSize = (
        513
        540)
      object Label2: TLabel
        Left = 8
        Top = 8
        Width = 226
        Height = 24
        Caption = 'Step 2 - Select Materials'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label3: TLabel
        Left = 8
        Top = 40
        Width = 74
        Height = 13
        Caption = 'Select materials'
      end
      object Label4: TLabel
        Left = 477
        Top = 509
        Width = 8
        Height = 13
        Anchors = [akRight, akBottom]
        Caption = '%'
      end
      object lvMaterials: TListView
        Left = 8
        Top = 64
        Width = 489
        Height = 434
        Anchors = [akLeft, akTop, akBottom]
        BevelKind = bkFlat
        BorderStyle = bsNone
        Columns = <
          item
            Width = 200
          end
          item
            Width = 200
          end>
        ColumnClick = False
        Items.Data = {
          320000000100000000000000FFFFFFFFFFFFFFFF0100000000000000094D6174
          657269616C31094D6174657269616C32FFFF}
        RowSelect = True
        ShowColumnHeaders = False
        TabOrder = 0
        ViewStyle = vsReport
        OnChange = lvMaterialsChange
      end
      object btnReplace: TButton
        Left = 8
        Top = 505
        Width = 97
        Height = 25
        Anchors = [akLeft, akBottom]
        Caption = 'Replace material'
        TabOrder = 1
        OnClick = btnReplaceClick
      end
      object btnRestore: TButton
        Left = 112
        Top = 505
        Width = 81
        Height = 25
        Anchors = [akLeft, akBottom]
        Caption = 'Use original'
        TabOrder = 2
        OnClick = btnRestoreClick
      end
      object btnFind: TButton
        Left = 304
        Top = 505
        Width = 91
        Height = 25
        Anchors = [akRight, akBottom]
        Caption = 'Find best match'
        TabOrder = 3
        OnClick = btnFindClick
      end
      object EPS: TEdit
        Left = 400
        Top = 505
        Width = 73
        Height = 21
        Anchors = [akRight, akBottom]
        TabOrder = 4
        Text = '80'
      end
    end
    object tsSelectTextures: TTabSheet
      Caption = 'Step 3'
      ImageIndex = 2
      TabVisible = False
    end
  end
  object Panel1: TPanel
    Left = 521
    Top = 0
    Width = 596
    Height = 550
    Align = alClient
    BevelOuter = bvNone
    Caption = 'Panel1'
    TabOrder = 1
    object Renderer: TPanel
      Left = 0
      Top = 0
      Width = 596
      Height = 509
      Align = alClient
      TabOrder = 0
    end
    object Panel2: TPanel
      Left = 0
      Top = 509
      Width = 596
      Height = 41
      Align = alBottom
      TabOrder = 1
      DesignSize = (
        596
        41)
      object btnNext: TButton
        Left = 513
        Top = 8
        Width = 75
        Height = 25
        Anchors = [akRight, akBottom]
        Caption = 'Next >>'
        TabOrder = 0
        OnClick = btnNextClick
      end
      object btnPrev: TButton
        Left = 433
        Top = 8
        Width = 75
        Height = 25
        Anchors = [akRight, akBottom]
        Caption = '<< Prev'
        TabOrder = 1
        OnClick = btnPrevClick
      end
    end
  end
end
