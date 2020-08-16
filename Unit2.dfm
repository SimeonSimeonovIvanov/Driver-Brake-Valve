object Form2: TForm2
  Left = 355
  Top = 174
  BorderStyle = bsNone
  Caption = 'Vi'
  ClientHeight = 300
  ClientWidth = 300
  Color = clWindow
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = True
  Position = poDefault
  OnClose = OnClose
  OnHide = OnHide
  OnResize = onResize
  OnShow = OnShow
  PixelsPerInch = 96
  TextHeight = 13
  object Timer1: TTimer
    Enabled = False
    Interval = 25
    OnTimer = Timer1Timer
    Left = 144
    Top = 184
  end
end
