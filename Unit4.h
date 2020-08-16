#ifndef Unit4H
#define Unit4H

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>

#include "Unit1.h"

class TForm4 : public TForm
{
__published:	// IDE-managed Components
    TButton *Button1;
    TCheckListBox *CheckListBox1;
    TCheckListBox *CheckListBox2;
    TButton *Button2;
    TEdit *Edit1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall OnShow(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
    bool boolSaveExit;
public:		// User declarations
    __fastcall TForm4(TComponent* Owner);
    bool boolSaveAndExit();

    TDevice *lpDevice;
};

extern PACKAGE TForm4 *Form4;
#endif
