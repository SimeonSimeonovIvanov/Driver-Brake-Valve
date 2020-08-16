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

#include "Unit1.h"
#include "Unit4.h"
#include "Unit5.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;

__fastcall TForm5::TForm5(TComponent* Owner)
    : TForm(Owner)
{
}

void __fastcall TForm5::OnShow(TObject *Sender)
{
    ListBox1->Clear();
    for(int i = 0; i < Form1->deviceCount; i++) {
        ListBox1->AddItem(Form1->arrDeviceType[i].Name, Sender);
    }
}

// Редактиране на апарат от списъка:
void __fastcall TForm5::Button1Click(TObject *Sender)
{
    if(ListBox1->ItemIndex > -1) {
        int oldSelectListBoxItem[] = {
            ListBox1->ItemIndex,
            Form1->ListBox1->ItemIndex
        };

        Form4->Caption = "Редактирай апарат:";
        Form4->lpDevice = &Form1->arrDeviceType[ListBox1->ItemIndex];
        Form4->ShowModal();
        ListBox1->Clear();
        Form1->ListBox1->Clear();
        for(int i = 0; i < Form1->deviceCount; i++) {
            ListBox1->AddItem(Form1->arrDeviceType[i].Name, Sender);
            Form1->ListBox1->AddItem(Form1->arrDeviceType[i].Name, Sender);
        }
        ListBox1->Selected[oldSelectListBoxItem[0]] = true;
        if(oldSelectListBoxItem[1] > -1) {
            Form1->ListBox1->Selected[oldSelectListBoxItem[1]] = true;
        }
    }
    Form1->ListBox1->OnClick(Sender);
}

// Добавяне на апарат към списъка:
void __fastcall TForm5::Button2Click(TObject *Sender)
{
    if(Form1->deviceCount < 99) {
        TDevice temp;

        Form4->Caption = "Добави апарат:";
        Form4->lpDevice = &temp;
        Form4->ShowModal();

        if(true == Form4->boolSaveAndExit()) {
            Form1->arrDeviceType[Form1->deviceCount] = temp;
            ListBox1->AddItem(Form1->arrDeviceType[Form1->deviceCount].Name, Sender);
            Form1->ListBox1->AddItem(Form1->arrDeviceType[Form1->deviceCount].Name, Sender);
            ++Form1->deviceCount;
        }
    }
}

// Премахване на апарат от списъка:
void __fastcall TForm5::Button3Click(TObject *Sender)
{
    if(ListBox1->ItemIndex > -1) {
        Form1->arrDeviceType[ListBox1->ItemIndex].Name = "";
        Form1->arrDeviceType[ListBox1->ItemIndex].analogMeterCount = 0;
        for(int i = 0; i < 7; i++) {
            Form1->arrAnalogMeter[i]->Hide();
            Form1->Chart1->Series[i]->Active = false;
            Form1->Chart1->Series[i]->ShowInLegend = false;
            Form1->arrDeviceType[ListBox1->ItemIndex].arrAnalogIputIsEnable[i] = false;
        }

        for(int i = 0; i < 12; i++) {
            Form1->arrDeviceType[ListBox1->ItemIndex].arrDigitalOutputIsEnable[i] = false;
        }

        for(int i = ListBox1->ItemIndex; i < ListBox1->Count ; i++) {
            Form1->arrDeviceType[i] = Form1->arrDeviceType[i + 1];
        }

        int n = ListBox1->ItemIndex;
        ListBox1->Items->Delete(n);
        Form1->ListBox1->Items->Delete(n);
        --Form1->deviceCount;

        Button1->Enabled = false;
        Button3->Enabled = false;
    }
    Sender = Sender;
}

void __fastcall TForm5::ListBox1Click(TObject *Sender)
{
    if(ListBox1->ItemIndex > -1) {
        Button1->Enabled = true;
        Button3->Enabled = true;
    }
    Sender = Sender;
}
