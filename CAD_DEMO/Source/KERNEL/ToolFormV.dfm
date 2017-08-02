object ToolForm: TToolForm
  Left = 431
  Top = 249
  BorderIcons = []
  BorderStyle = bsNone
  Caption = 'ToolForm'
  ClientHeight = 178
  ClientWidth = 147
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object pCoordinates: TPanel
    Left = 0
    Top = 0
    Width = 147
    Height = 89
    Align = alTop
    BorderWidth = 5
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnResize = pCoordinatesResize
    object bDecD: TSpeedButton
      Left = 6
      Top = 7
      Width = 15
      Height = 30
      AllowAllUp = True
      GroupIndex = 2
      Transparent = False
    end
    object bPolD: TSpeedButton
      Left = 6
      Top = 48
      Width = 15
      Height = 30
      AllowAllUp = True
      GroupIndex = 1
      Transparent = False
    end
    object Label1: TLabel
      Left = 26
      Top = 6
      Width = 16
      Height = 16
      Caption = 'x :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 25
      Top = 23
      Width = 17
      Height = 16
      Caption = 'y :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 28
      Top = 47
      Width = 14
      Height = 16
      Caption = 'r :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 24
      Top = 64
      Width = 18
      Height = 16
      Caption = 'a :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object eDecX: TEdit
      Left = 42
      Top = 5
      Width = 100
      Height = 19
      AutoSize = False
      Constraints.MaxHeight = 20
      Constraints.MaxWidth = 150
      Constraints.MinHeight = 10
      Constraints.MinWidth = 40
      Ctl3D = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 0
    end
    object ePolR: TEdit
      Left = 42
      Top = 46
      Width = 100
      Height = 19
      Constraints.MaxHeight = 20
      Constraints.MaxWidth = 150
      Constraints.MinHeight = 10
      Constraints.MinWidth = 40
      Ctl3D = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 2
    end
    object eDecY: TEdit
      Left = 42
      Top = 23
      Width = 100
      Height = 19
      Constraints.MaxHeight = 20
      Constraints.MaxWidth = 150
      Constraints.MinHeight = 10
      Constraints.MinWidth = 40
      Ctl3D = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 1
    end
    object ePolA: TEdit
      Left = 42
      Top = 64
      Width = 100
      Height = 19
      Constraints.MaxHeight = 20
      Constraints.MaxWidth = 150
      Constraints.MinHeight = 10
      Constraints.MinWidth = 40
      Ctl3D = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 3
    end
  end
  object pCustom: TPanel
    Left = 0
    Top = 89
    Width = 147
    Height = 89
    Align = alClient
    TabOrder = 1
  end
end
