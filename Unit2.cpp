/*
		The^day^of^DooM

	Create Date:	14.05.2012
	Last Update:	19.05.2012
	Full Change:	20.05.2012
	Last Update:	29.05.2012
    Last Update:	06.06.2012
*/

#include <vcl.h>
#pragma hdrstop

#include <math.h>
#include <stdio.h>
#include "Unit2.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
    Timer1->Enabled = false;
}

void TForm2::SetAngle(double a)
{
    angle = a;
}

void TForm2::PaintAnalogMeter(void)
{
    const double deg_rad = 3.141592654 / 180.0;

    int i;
    AnsiString str;
    char buffer[100];
    double x, y, l = (Width / 2) - 30;

    TRect rect = ClientRect;
    Graphics::TBitmap *MemBitmap = new Graphics::TBitmap;

    MemBitmap->Canvas->Brush->Color = clWhite;
    MemBitmap->Width = Width;
    MemBitmap->Height = Height;
    MemBitmap->Canvas->FillRect(rect);

    for(i = -45; i <= 225; i += 27) {
        x = (10 + l) * cos(i * deg_rad);
        y = (10 + l) * sin(i * deg_rad);
        MemBitmap->Canvas->TextOutA(
            (x - 5) + Width / 2,
            (Width / 2) - 5 - (y - 3),
            (270 - (i + 45)) / 27
        );
    }

    MemBitmap->Canvas->TextOutA(0, 0, Caption);

    sprintf(buffer, "Value: %.2f Bar", (270 - angle) / 27);
    MemBitmap->Canvas->TextOutA(20, Height - 20, buffer);

    MemBitmap->Canvas->Pen->Width = 4;
    MemBitmap->Canvas->Pen->Color = clRed;
    MemBitmap->Canvas->Brush->Style = bsSolid; //bsClear;

    x = l * cos((angle - 45) * deg_rad);
    y = l * sin((angle - 45) * deg_rad);

    MemBitmap->Canvas->MoveTo(Width/2, (Width / 2) + 5);
    MemBitmap->Canvas->LineTo(x + Width/2, ((Width / 2) - y) + 5);

    Canvas->Draw(0, 0, MemBitmap);

    delete MemBitmap;
}

void __fastcall TForm2::WMEraseBkgnd(TWMEraseBkgnd &Message)
{
    Message = Message;
}

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
    PaintAnalogMeter();
    Sender = Sender;
}

void __fastcall TForm2::onResize(TObject *Sender)
{
    Height = Width;
    Sender = Sender;
}

void __fastcall TForm2::OnShow(TObject *Sender)
{
    Timer1->Enabled = true;
    Sender = Sender;
}

void __fastcall TForm2::OnHide(TObject *Sender)
{
    Timer1->Enabled = false;
    Sender = Sender;
}

void __fastcall TForm2::OnClose(TObject *Sender, TCloseAction &Action)
{
    Timer1->Enabled = false;
    Sender = Sender;
    Action = Action;
}

