#ifndef Unit6H
#define Unit6H

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>

class TForm6 : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label11;
    TButton *Button1;
    TGroupBox *GroupBox1;
    TListBox *ListBox1;
    TButton *Button2;
    TStringGrid *StringGrid1;
    TEdit *Edit1;
    void __fastcall Edit1OnKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall SG1OnMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall ListBox1Click(TObject *Sender);
    void __fastcall OnShow(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm6(TComponent* Owner);
};

extern PACKAGE TForm6 *Form6;

#endif
