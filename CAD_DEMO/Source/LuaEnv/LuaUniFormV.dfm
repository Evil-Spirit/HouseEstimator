object LuaUniForm: TLuaUniForm
  Left = 419
  Top = 237
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  BorderWidth = 2
  Caption = 'LuaUniForm'
  ClientHeight = 314
  ClientWidth = 568
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
    568
    314)
  PixelsPerInch = 96
  TextHeight = 13
  object btOK: TButton
    Left = 331
    Top = 280
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = #1054#1050
    TabOrder = 0
    OnClick = btOKClick
  end
  object btCancel: TButton
    Left = 411
    Top = 280
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 1
    OnClick = btCancelClick
  end
  object btApply: TButton
    Left = 491
    Top = 280
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
    TabOrder = 2
    OnClick = btApplyClick
  end
  object pView: TPanel
    Left = 257
    Top = 0
    Width = 311
    Height = 274
    Anchors = [akTop, akRight, akBottom]
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Caption = 'pView'
    TabOrder = 3
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 257
    Height = 274
    Anchors = [akLeft, akTop, akRight, akBottom]
    BevelOuter = bvNone
    Caption = 'Panel1'
    TabOrder = 4
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 257
    Height = 274
    Anchors = [akLeft, akTop, akRight, akBottom]
    BevelOuter = bvNone
    Caption = 'Panel1'
    TabOrder = 5
  end
  object Panel3: TPanel
    Left = 0
    Top = 0
    Width = 257
    Height = 274
    Anchors = [akLeft, akTop, akRight, akBottom]
    BevelOuter = bvNone
    Caption = 'Panel1'
    TabOrder = 6
  end
  object Panel4: TPanel
    Left = 0
    Top = 0
    Width = 257
    Height = 274
    Anchors = [akLeft, akTop, akRight, akBottom]
    BevelOuter = bvNone
    Caption = 'Panel1'
    TabOrder = 7
  end
  object Panel5: TPanel
    Left = 0
    Top = 0
    Width = 257
    Height = 274
    Anchors = [akLeft, akTop, akRight, akBottom]
    BevelOuter = bvNone
    Caption = 'Panel1'
    TabOrder = 8
  end
end
