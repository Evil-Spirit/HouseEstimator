inherited MDIConfig: TMDIConfig
  Left = 162
  Top = 284
  Width = 747
  Height = 473
  Caption = 'MDIConfig'
  OldCreateOrder = True
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 739
    Height = 446
    ActivePage = tsTechnology
    Align = alClient
    TabIndex = 0
    TabOrder = 0
    TabPosition = tpBottom
    object tsTechnology: TTabSheet
      Caption = 'Technology'
      object tvTechnology: TTreeView
        Left = 0
        Top = 25
        Width = 731
        Height = 395
        Align = alClient
        Color = clWhite
        DragCursor = crDefault
        DragMode = dmAutomatic
        HideSelection = False
        Images = ImageLibrary.TreeImages
        Indent = 27
        ParentShowHint = False
        ReadOnly = True
        RightClickSelect = True
        RowSelect = True
        ShowHint = False
        TabOrder = 0
        OnDblClick = tvTechnologyDblClick
        OnDeletion = tvTechnologyDeletion
        OnDragDrop = tvTechnologyDragDrop
        OnDragOver = tvTechnologyDragOver
        OnMouseDown = tvTechnologyMouseDown
        OnStartDrag = tvTechnologyStartDrag
        Items.Data = {
          01000000230000000000000000000000FFFFFFFFFFFFFFFF0000000002000000
          0AD2E5F5EDEEEBEEE3E8FF210000000100000001000000FFFFFFFFFFFFFFFF00
          0000000000000008DDEBE5ECE5EDF2FB1F0000000200000002000000FFFFFFFF
          FFFFFFFF000000000000000006D1E2FFE7EAE8}
      end
      object ToolBar1: TToolBar
        Left = 0
        Top = 0
        Width = 731
        Height = 25
        Caption = 'ToolBar1'
        Flat = True
        Images = ImageLibrary.ActionImages
        TabOrder = 1
        object ToolButton1: TToolButton
          Left = 0
          Top = 0
          Action = New
        end
        object ToolButton4: TToolButton
          Left = 23
          Top = 0
          Action = NewFol
        end
        object ToolButton7: TToolButton
          Left = 46
          Top = 0
          Action = NewCopy
        end
        object ToolButton2: TToolButton
          Left = 69
          Top = 0
          Action = Edit
        end
        object ToolButton3: TToolButton
          Left = 92
          Top = 0
          Action = Del
        end
        object ToolButton5: TToolButton
          Left = 115
          Top = 0
          Action = UpAction
        end
        object ToolButton6: TToolButton
          Left = 138
          Top = 0
          Action = DownAction
        end
        object ToolButton8: TToolButton
          Left = 161
          Top = 0
          Action = ExportHere
        end
        object ToolButton9: TToolButton
          Left = 184
          Top = 0
          Action = ImportHere
        end
      end
    end
    object tsOptions: TTabSheet
      Caption = 'Options'
      ImageIndex = 1
      object pcOptions: TPageControl
        Left = 0
        Top = 0
        Width = 731
        Height = 420
        ActivePage = tsInterface
        Align = alClient
        TabIndex = 0
        TabOrder = 0
        object tsInterface: TTabSheet
          Caption = 'Panel of objects'
        end
        object tsMainVariable: TTabSheet
          Caption = 'Basic variables'
          ImageIndex = 1
        end
      end
    end
  end
  object AL: TActionList
    Left = 696
    Top = 344
    object New: TAction
      Caption = 'New'
      ImageIndex = 0
      OnExecute = NewExecute
    end
    object NewFol: TAction
      Caption = 'New group'
      ImageIndex = 3
      OnExecute = NewFolExecute
    end
    object NewCopy: TAction
      Caption = 'Copy ...'
      ImageIndex = 6
      OnExecute = NewCopyExecute
    end
    object Edit: TAction
      Caption = 'Edit'
      ImageIndex = 1
      OnExecute = EditExecute
    end
    object Del: TAction
      Caption = 'Delete'
      ImageIndex = 2
      OnExecute = DelExecute
    end
    object UpAction: TAction
      Caption = 'Shift up'
      Hint = 'Shift up'
      ImageIndex = 4
      OnExecute = UpActionExecute
    end
    object DownAction: TAction
      Caption = 'Shift down'
      Hint = 'Shift down'
      ImageIndex = 5
      OnExecute = DownActionExecute
    end
    object ExportHere: TAction
      Caption = 'Export ...'
      Hint = 'Export data|Export data to Excel ...'
      ImageIndex = 7
      OnExecute = ExportHereExecute
    end
    object ImportHere: TAction
      Caption = 'Import ...'
      Hint = 'Import data|Import data from Excel ...'
      ImageIndex = 8
      OnExecute = ImportHereExecute
    end
  end
  object PopupMenu1: TPopupMenu
    Images = ImageLibrary.ActionImages
    Left = 696
    Top = 376
    object N1: TMenuItem
      Action = New
    end
    object N4: TMenuItem
      Action = NewFol
    end
    object N5: TMenuItem
      Action = NewCopy
    end
    object N2: TMenuItem
      Action = Edit
      Default = True
    end
    object N3: TMenuItem
      Action = Del
    end
    object UpAction1: TMenuItem
      Action = UpAction
    end
    object DownAction1: TMenuItem
      Action = DownAction
    end
  end
  object OD: TOpenDialog
    Filter = 'Excel WorkBook (*.xls)|*.xls'
    Title = #1059#1082#1072#1078#1080#1090#1077' '#1092#1072#1081#1083' '#1076#1083#1103' '#1080#1084#1087#1086#1088#1090#1072
    Left = 656
    Top = 312
  end
  object SD: TSaveDialog
    FileName = 
      'C:\Documents and Settings\russ\'#1056#1072#1073#1086#1095#1080#1081' '#1089#1090#1086#1083'\'#1087#1088#1086#1073#1083#1077#1084#1072' '#1089' '#1092#1091#1085#1076#1072#1084#1077#1085#1090 +
      #1086#1084
    Filter = 
      'SOPOS Project (*.home)|*.home|Bitmap Image (*.bmp)|*.bmp|Excel W' +
      'orkBook (*.xls)|*.xls'
    Options = [ofOverwritePrompt, ofEnableSizing]
    Title = #1059#1082#1072#1078#1080#1090#1077' '#1092#1072#1081#1083' '#1076#1083#1103' '#1101#1082#1089#1087#1086#1088#1090#1072
    Left = 696
    Top = 312
  end
end
