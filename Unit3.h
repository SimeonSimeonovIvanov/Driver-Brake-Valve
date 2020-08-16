#ifndef Unit3H
#define Unit3H

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
#include <TeeFunci.hpp>
#include <Dialogs.hpp>
#include <QuickRpt.hpp>
#include <time.h>

class TForm3 : public TForm
{
__published:	// IDE-managed Components
    TButton *Button1;
    TButton *Button2;
    TPrinterSetupDialog *PrinterSetupDialog1;
    TPrintDialog *PrintDialog1;
    TChart *Chart1;
    TFastLineSeries *Series1;
    TFastLineSeries *Series2;
    TFastLineSeries *Series3;
    TFastLineSeries *Series4;
    TFastLineSeries *Series5;
    TFastLineSeries *Series6;
    TFastLineSeries *Series7;
    TEdit *Edit1;
    TLabel *Label1;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall onResize(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall OnShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm3(TComponent* Owner);

    void setDateAndTime(const struct tm *systime);
};

extern PACKAGE TForm3 *Form3;

#endif
