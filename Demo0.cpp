/*
		The^day^of^DooM

	Create Date:	14.05.2012
	Last Update:	19.05.2012
	Full Change:	20.05.2012
	Last Update:	29.05.2012
    Last Update:	29.05.2012
*/

#include <vcl.h>
#pragma hdrstop

USEFORM("Unit1.cpp", Form1);
USEFORM("Unit3.cpp", Form3);
USEFORM("Unit2.cpp", Frame2); /* TFrame: File Type */
USEFORM("Unit4.cpp", Form4);
USEFORM("Unit5.cpp", Form5);
USEFORM("Unit6.cpp", Form6);
USEFORM("Unit7.cpp", Form7);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try {
        Application->Initialize();
        Application->Title = "Express service";
        Application->CreateForm(__classid(TForm1), &Form1);
         Application->CreateForm(__classid(TForm3), &Form3);
         Application->CreateForm(__classid(TForm4), &Form4);
         Application->CreateForm(__classid(TForm5), &Form5);
         Application->CreateForm(__classid(TForm6), &Form6);
         Application->CreateForm(__classid(TForm7), &Form7);
         Application->Run();
    } catch(Exception &exception) {
        Application->ShowException(&exception);
    } catch(...) {
        try {
            throw Exception("");
        } catch(Exception &exception) {
            Application->ShowException(&exception);
        }
    }
    return 0;
}
