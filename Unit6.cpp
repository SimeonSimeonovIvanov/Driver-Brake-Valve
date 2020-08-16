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

#include <time.h>
#include "Unit1.h"
#include "Unit3.h"
#include "Unit6.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;

__fastcall TForm6::TForm6(TComponent* Owner)
    : TForm(Owner)
{
    StringGrid1->Cells[0][0] = "¹";
    StringGrid1->Cells[1][0] = "ÄÀÒÀ";
    StringGrid1->Cells[2][0] = "ÑÅÐÈÅÍ ÍÎÌÅÐ";
}

int gX, gY;
int gOldX = -1, gOldY = -1;

void __fastcall TForm6::SG1OnMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    StringGrid1->MouseToCell(X, Y, gX, gY);

    if( ListBox1->ItemIndex >-1 &&
        (gY > 0 && Form1->arrDeviceType[ListBox1->ItemIndex].getTestCount() >= gY)
    ) {
        Button1->Enabled = true;
    } else {
        Button1->Enabled = false;
    }

    if(gX == 2 && gY > 0) {
        Edit1->Top = StringGrid1->Top + StringGrid1->DefaultRowHeight * gY + 4; //((StringGrid1->DefaultRowHeight - Edit1->Height));

        if(false == Edit1->Visible) {
            Edit1->Text = StringGrid1->Cells[gX][gY];
            Edit1->Visible = true;
            Edit1->SetFocus();

            gOldX = gX;
            gOldY = gY;
        } else {
            if(gY != gOldY || gX != gOldY) {
                Edit1->Visible = false;

                gOldX = gX;
                gOldY = gY;
            }
        }
    } else {
        if(true == Edit1->Visible) {
            StringGrid1->Cells[gOldX][gOldY] = Edit1->Text;

            gOldX = gX;
            gOldY = gY;
        }

        Edit1->Visible = false;
    }
    Sender = Sender;
    Button = Button;
    Shift = Shift;
}

void __fastcall TForm6::Edit1OnKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(13 == Key && true == Edit1->Visible) {
        StringGrid1->Cells[gX][gY] = Edit1->Text;
        Edit1->Visible = false;
    }
    Sender = Sender;
    Shift = Shift;
}

void __fastcall TForm6::ListBox1Click(TObject *Sender)
{
    if(ListBox1->ItemIndex < 0) return;

    Button1->Enabled = false;

    StringGrid1->RowCount = 2 + Form1->arrDeviceType[ListBox1->ItemIndex].getTestCount();

    for(int i = 0; i < 4; i++) {
        StringGrid1->Cells[i][1] = "";
        StringGrid1->Cells[i][StringGrid1->RowCount - 1] = "";
    }
    
    for(int i = 1; i <= StringGrid1->RowCount - 2; i++) {
        char buffer[100];
        struct tm systime;
        TDeviceTest *lpDeviceTest;

        lpDeviceTest = Form1->arrDeviceType[ListBox1->ItemIndex].getTestListData(i - 1);

        lpDeviceTest->getTestTime(&systime);
        strftime(buffer, 99, "%x (%X)", &systime);

        StringGrid1->Cells[0][i] = i;
        StringGrid1->Cells[1][i] = buffer;
        StringGrid1->Cells[2][i] = lpDeviceTest->getSerialNumber();
        StringGrid1->Cells[3][i] = lpDeviceTest->getSeriesCount();
    }
    Sender = Sender;
}

void __fastcall TForm6::OnShow(TObject *Sender)
{
    ListBox1->Clear();
    for(int i = 0; i < Form1->deviceCount; i++) {
        ListBox1->AddItem(Form1->arrDeviceType[i].Name, NULL);
    }

    if(ListBox1->Items->Count) {
        ListBox1->ItemIndex = 0;
    }
    ListBox1Click(Sender);
    Button1->Enabled = false;
}

void __fastcall TForm6::Button1Click(TObject *Sender)
{
    if( ListBox1->ItemIndex < 0 || gY < 1                               ||
        !Form1->arrDeviceType[ListBox1->ItemIndex].getTestCount()       ||
        Form1->arrDeviceType[ListBox1->ItemIndex].getTestCount() < gY
    ) return;

    TDeviceTest *lpDeviceTest = Form1->arrDeviceType[ListBox1->ItemIndex].getTestListData(gY - 1);

    lpDeviceTest->setTestDataToChart(Form3->Chart1, Form1->chartStep);

    Form3->setDateAndTime(lpDeviceTest->getTestTime());

    for(int i = 0; i < 7; i++) {
        if(lpDeviceTest->getSeriesCount(i)) {
            Form3->Chart1->Series[i]->Active = true;
        } else {
            Form3->Chart1->Series[i]->Active = false;
        }
    }
    Form3->Show();
    Sender = Sender;
}

void __fastcall TForm6::Button2Click(TObject *Sender)
{
    ListBox1->Clear();
    Close();
    Sender = Sender;
}

