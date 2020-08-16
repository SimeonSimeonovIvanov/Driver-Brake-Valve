object Form6: TForm6
  Left = 497
  Top = 72
  Width = 698
  Height = 461
  Caption = #1055#1088#1077#1075#1083#1077#1076' '#1085#1072' '#1079#1072#1087#1080#1089#1072#1085#1080#1090#1077' '#1090#1077#1089#1090#1086#1074#1077
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = OnShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label11: TLabel
    Left = 40
    Top = 8
    Width = 5
    Height = 16
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Button1: TButton
    Left = 240
    Top = 392
    Width = 89
    Height = 25
    Caption = #1054#1090#1074#1086#1088#1080' '#1090#1077#1089#1090
    TabOrder = 0
    OnClick = Button1Click
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 673
    Height = 369
    Caption = #1050#1088#1072#1085' '#1084#1072#1096#1080#1085#1080#1089#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    object ListBox1: TListBox
      Left = 16
      Top = 24
      Width = 209
      Height = 329
      ItemHeight = 16
      TabOrder = 0
      OnClick = ListBox1Click
    end
    object StringGrid1: TStringGrid
      Left = 240
      Top = 24
      Width = 425
      Height = 329
      ColCount = 4
      DefaultColWidth = 30
      RowCount = 2
      TabOrder = 1
      OnMouseDown = SG1OnMouseDown
      ColWidths = (
        30
        140
        164
        80)
    end
    object Edit1: TEdit
      Left = 536
      Top = 88
      Width = 73
      Height = 24
      TabOrder = 2
      Text = 'Edit1'
      Visible = False
      OnKeyDown = Edit1OnKeyDown
    end
  end
  object Button2: TButton
    Left = 344
    Top = 392
    Width = 73
    Height = 25
    Caption = #1047#1072#1090#1074#1086#1088#1080
    TabOrder = 2
    OnClick = Button2Click
  end
end
