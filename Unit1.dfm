object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 809
  ClientWidth = 1090
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 8
    Top = 8
    Width = 913
    Height = 769
    OnMouseDown = Image1MouseDown
    OnMouseMove = Image1MouseMove
    OnMouseUp = Image1MouseUp
  end
  object Button1: TButton
    Left = 927
    Top = 8
    Width = 159
    Height = 49
    Caption = #1042#1089#1090#1072#1074#1080#1090#1100' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077
    TabOrder = 0
    OnClick = Button1Click
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 790
    Width = 1090
    Height = 19
    Panels = <>
    SimplePanel = True
  end
  object Button2: TButton
    Left = 927
    Top = 143
    Width = 159
    Height = 25
    Caption = #1047#1072#1082#1086#1085#1095#1080#1090#1100
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 927
    Top = 752
    Width = 75
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 1011
    Top = 752
    Width = 75
    Height = 25
    Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100
    TabOrder = 4
    OnClick = Button4Click
  end
  object RadioGroup1: TRadioGroup
    Left = 927
    Top = 63
    Width = 159
    Height = 74
    Caption = #1048#1085#1076#1080#1082#1072#1090#1086#1088' ('#1085#1077' '#1072#1082#1090#1080#1074#1077#1085')'
    Enabled = False
    ItemIndex = 0
    Items.Strings = (
      #1042#1077#1088#1090#1080#1082#1072#1083#1100
      #1058#1086#1095#1082#1080)
    TabOrder = 5
  end
  object FileSaveDialog1: TFileSaveDialog
    FavoriteLinks = <>
    FileTypes = <>
    Options = []
    Left = 864
    Top = 16
  end
  object FileOpenDialog1: TFileOpenDialog
    FavoriteLinks = <>
    FileTypes = <>
    Options = []
    Left = 864
    Top = 72
  end
end
