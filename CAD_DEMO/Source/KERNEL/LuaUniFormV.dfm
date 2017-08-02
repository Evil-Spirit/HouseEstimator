object LuaUniForm: TLuaUniForm
  Left = 327
  Top = 180
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  BorderWidth = 2
  Caption = 'LuaUniForm'
  ClientHeight = 454
  ClientWidth = 588
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  DesignSize = (
    588
    454)
  PixelsPerInch = 96
  TextHeight = 13
  object btOK: TButton
    Left = 351
    Top = 420
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'OK'
    TabOrder = 0
    OnClick = btOKClick
  end
  object btCancel: TButton
    Left = 431
    Top = 420
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = btCancelClick
  end
  object btApply: TButton
    Left = 511
    Top = 420
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'Apply'
    TabOrder = 2
    OnClick = btApplyClick
  end
  object pView: TPanel
    Left = 284
    Top = 0
    Width = 304
    Height = 414
    Anchors = [akTop, akRight, akBottom]
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Caption = 'pView'
    TabOrder = 3
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 277
    Height = 414
    Anchors = []
    BevelOuter = bvNone
    Caption = 'Panel1'
    TabOrder = 4
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 277
    Height = 414
    Anchors = []
    BevelOuter = bvNone
    Caption = 'Panel1'
    TabOrder = 5
  end
  object Panel3: TPanel
    Left = 0
    Top = 0
    Width = 277
    Height = 414
    Anchors = []
    BevelOuter = bvNone
    Caption = 'Panel1'
    TabOrder = 6
  end
  object Panel4: TPanel
    Left = 0
    Top = 0
    Width = 277
    Height = 414
    Anchors = []
    BevelOuter = bvNone
    Caption = 'Panel1'
    TabOrder = 7
  end
  object Panel5: TPanel
    Left = 0
    Top = 0
    Width = 277
    Height = 414
    Anchors = []
    BevelOuter = bvNone
    Caption = 'Panel1'
    TabOrder = 8
  end
end
