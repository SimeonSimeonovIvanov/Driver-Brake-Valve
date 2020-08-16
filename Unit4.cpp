/*
		The^day^of^DooM

	Create Date:	14.05.2012
	Last Update:	19.05.2012
	Full Change:	20.05.2012
	Last Update:	29.05.2012
    Last Update:	06.06.2012
*/

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "Unit4.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;

__fastcall TForm4::TForm4(TComponent* Owner) : TForm(Owner)
{
    int i;
    char buffer[100];

    boolSaveExit = false;

    for(i = 0; i < 7; i++) {
        sprintf(buffer, "Манометър %d", 1 + i);
        CheckListBox1->AddItem(buffer, Owner);
    }
    for(i = 0; i < 12; i++) {
        sprintf(buffer, "Вентил %d", 1 + i);
        CheckListBox2->AddItem(buffer, Owner);
    }
}

void __fastcall TForm4::Button1Click(TObject *Sender)
{
    boolSaveExit = false;
    Close();
    Sender = Sender;
}

void __fastcall TForm4::Button2Click(TObject *Sender)
{
    boolSaveExit = true;
    lpDevice->Name = Edit1->Text;

    for(int i = 0; i < 7; i++) {
        lpDevice->arrAnalogIputIsEnable[i] = CheckListBox1->Checked[i];
    }

    for(int i = 0; i < 12; i++) {
        lpDevice->arrDigitalOutputIsEnable[i] = CheckListBox2->Checked[i];
    }

    lpDevice->analogMeterCount = 0;
    for(int i = 0; i < 7; i++) {
        if(lpDevice->arrAnalogIputIsEnable[i]) {
            ++lpDevice->analogMeterCount;
        }
    }

    Close();
    Sender = Sender;
}

void __fastcall TForm4::OnShow(TObject *Sender)
{
    Edit1->Text = lpDevice->Name;

    for(int i = 0; i < 7; i++) {
        CheckListBox1->Checked[i] = lpDevice->arrAnalogIputIsEnable[i];
    }

    for(int i = 0; i < 12; i++) {
        CheckListBox2->Checked[i] = lpDevice->arrDigitalOutputIsEnable[i];
    }
    Sender = Sender;
}

bool TForm4::boolSaveAndExit()
{
    return boolSaveExit;
}
