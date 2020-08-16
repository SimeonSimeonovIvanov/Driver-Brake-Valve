//---------------------------------------------------------------------------


#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
    TTimer *Timer1;
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall onResize(TObject *Sender);
    void __fastcall OnShow(TObject *Sender);
    void __fastcall OnHide(TObject *Sender);
    void __fastcall OnClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
    double angle;
    void PaintAnalogMeter(void);
    void __fastcall WMEraseBkgnd(TWMEraseBkgnd &Message);
public:		// User declarations
    __fastcall TForm2(TComponent* Owner);
    void SetAngle(double a);



BEGIN_MESSAGE_MAP
   MESSAGE_HANDLER(WM_ERASEBKGND,TWMEraseBkgnd,WMEraseBkgnd)
END_MESSAGE_MAP(TForm)
};

#endif
