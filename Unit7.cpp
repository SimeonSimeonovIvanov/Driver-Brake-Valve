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

#include "Unit7.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;

__fastcall TForm7::TForm7(TComponent* Owner)
    : TForm(Owner)
{
}

void __fastcall TForm7::OnShow(TObject *Sender)
{
    saveAndExit = false;
    Sender = Sender;
}

void __fastcall TForm7::Button1Click(TObject *Sender)
{
    saveAndExit = true;
    Close();
    Sender = Sender;
}

void __fastcall TForm7::Button2Click(TObject *Sender)
{
    Close();
    Sender = Sender;
}
