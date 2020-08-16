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

#include "Unit3.h"
#include "Unit1.h"
#include <Printers.hpp>

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;

__fastcall TForm3::TForm3(TComponent* Owner)
    : TForm(Owner)
{
    
}

void __fastcall TForm3::Button1Click(TObject *Sender)
{
/*    Edit1->Enabled = false;
    Edit1->BorderStyle = bsNone;

    Printer()->Orientation = poLandscape;
    Printer()->BeginDoc();

    int x = Printer()->PageWidth;
    int y = Printer()->PageHeight;

    int width, height;

    if((x / Panel1->Width) < (y / Panel1->Height)) {
        width = Panel1->Width * (0.5 + x / Panel1->Width);
        height = Panel1->Height * (0.5 + x / Panel1->Width);
    } else {
        width = Panel1->Width * (0.5 + y / Panel1->Height);
        height = Panel1->Height * (0.5 + y / Panel1->Height);
    }

    Printer()->Canvas->CopyRect(Rect(x - width, y - height, width, height), Canvas, Rect(Panel1->Left, Panel1->Top, Panel1->Width, Panel1->Height));

    Printer()->EndDoc();

    Edit1->Enabled = true;
    Edit1->BorderStyle = bsSingle;*/

    if( PrintDialog1->Execute() ){
        try {
            Printer()->Orientation = poLandscape;
            Button1->Hide();
            Button2->Hide();
            //Edit1->Enabled = false;
            Edit1->BorderStyle = bsNone;
            Print();
            Button1->Show();
            Button2->Show();
            //Edit1->Enabled = true;
            Edit1->BorderStyle = bsSingle;
        } catch(...) {
            throw;
        }
    }
    Sender = Sender;
}

void TForm3::setDateAndTime(const struct tm *systime)
{
    char buffer[100];
    strftime(buffer, sizeof(buffer) - 1, "%x (%X)", systime);
    Label1->Caption = buffer;
}

void __fastcall TForm3::onResize(TObject *Sender)
{
    Form1->Top = 0;
    Form1->Left = 0;

    Chart1->Left = 50;
    Chart1->Width = Form1->Width - (Chart1->Left + Chart1->Left);

    Chart1->Top = Form1->Height - Form1->Height * 2.0/3.0;
    Chart1->Height = Form1->Height - (Chart1->Top + Chart1->Left);

    Edit1->Left = Chart1->Left;
    Edit1->Top = Chart1->Top - 6 * Edit1->Height;


    /*Panel1->Left = 10;
    Panel1->Width = Form1->Width - 2 * Panel1->Left;
    Panel1->Top = 50;
    Panel1->Height = Form1->Height - (Panel1->Top + Panel1->Left);

    Chart1->Left = 5;
    Chart1->Width = Panel1->Width - (Chart1->Left + 10);

    Chart1->Top = Panel1->Height - Panel1->Height * (3.0 / 4.0);
    Chart1->Height = Panel1->Height - (Chart1->Top + 30);*/
    Sender = Sender;
}

void __fastcall TForm3::Button2Click(TObject *Sender)
{
    Chart1->CleanupInstance();
    Form3->Close();
    Sender = Sender;
}

void __fastcall TForm3::OnShow(TObject *Sender)
{
    Chart1->View3D = Form1->Chart1->View3D;
    for(int i = 0; i < 7; i++) {
        Chart1->Series[i]->Title = Form1->Chart1->Series[i]->Title;
        Chart1->Series[i]->ShowInLegend = Chart1->Series[i]->Active;
        Chart1->Series[i]->SeriesColor = Form1->Chart1->Series[i]->SeriesColor;
    }
    Sender = Sender;
}
