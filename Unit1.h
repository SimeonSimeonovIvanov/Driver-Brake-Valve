#ifndef Unit1H
#define Unit1H

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
#include <QuickRpt.hpp>
#include <Dialogs.hpp>
#include <CheckLst.hpp>
#include <TeeFunci.hpp>

#include "Unit2.h"
#include "TDevice.h"
#include "modbus/modbus.h"

class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *AboutMe1;
    TChart *Chart1;
    TMenuItem *fileExit;
    TMenuItem *filePrintSetings;
    TPrintDialog *PrintDialog1;
    TPrinterSetupDialog *PrinterSetupDialog1;
    TTimer *Timer1;
    TPanel *Panel2;
    TListBox *ListBox1;
    TGroupBox *GroupBox1;
    TFastLineSeries *Series2;
    TFastLineSeries *Series3;
    TFastLineSeries *Series4;
    TFastLineSeries *Series5;
    TFastLineSeries *Series6;
    TFastLineSeries *Series7;
    TMenuItem *Setings1;
    TMenuItem *Connection1;
    TMenuItem *Disconnect1;
    TMenuItem *ConnectoTo1;
    TMenuItem *COM11;
    TMenuItem *COM21;
    TMenuItem *COM31;
    TMenuItem *COM41;
    TMenuItem *COM51;
    TMenuItem *COM61;
    TMenuItem *COM71;
    TMenuItem *COM81;
    TMenuItem *Chart2;
    TMenuItem *N1;
    TMenuItem *N3D1;
    TMenuItem *EDIT1;
    TButton *Button1;
    TButton *Button2;
    TMenuItem *N2;
    TMenuItem *N3;
    TMenuItem *Load1;
    TMenuItem *Save1;
    TMenuItem *TCPIP1;
    TFastLineSeries *Series1;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Form1OnResize(TObject *Sender);
    void __fastcall ListBox1Click(TObject *Sender);
    void __fastcall Setings1Click(TObject *Sender);
    void __fastcall Disconnect1Click(TObject *Sender);
    void __fastcall COM11Click(TObject *Sender);
    void __fastcall filePrintSetingsClick(TObject *Sender);
    void __fastcall N3D1Click(TObject *Sender);
    void __fastcall EDIT1Click(TObject *Sender);
    void __fastcall fileExitClick(TObject *Sender);
    void __fastcall N2Click(TObject *Sender);
    void __fastcall Load1Click(TObject *Sender);
    void __fastcall Save1Click(TObject *Sender);
    void __fastcall OnDestroy(TObject *Sender);
    void __fastcall N3Click(TObject *Sender);
    void __fastcall TCPIP1Click(TObject *Sender);
    void __fastcall COM31Click(TObject *Sender);
    void __fastcall COM61Click(TObject *Sender);
    void __fastcall COM21Click(TObject *Sender);
    void __fastcall COM41Click(TObject *Sender);
    void __fastcall COM51Click(TObject *Sender);
    void __fastcall COM71Click(TObject *Sender);
    void __fastcall COM81Click(TObject *Sender);

private:

public:
    __fastcall TForm1(TComponent* Owner);
    bool OpenSerial(const char * str);

    double chartPos, chartStep;

    HANDLE hComThread;
    unsigned char SlaveID;
    unsigned int uiComIndex;

    MB mbMaster;

    bool fStartTest;

    unsigned int arrADC[7];
    TForm2 *arrAnalogMeter[7];

    char inPort[10], outPort[12];

    HANDLE hTimerThread;

    int deviceCount;
    TDevice arrDeviceType[100];

    void loadFile(char *name);
    void saveFile(char *name);

    void createDeviceListBox(void);

    int COMxxClick(int com);
};

void serialInitDefDCB(DCB *dcb);
DWORD WINAPI comThreadFunc(LPVOID lpParam);

DWORD WINAPI timerThreadFunc(LPVOID lpParam);

extern PACKAGE TForm1 *Form1;

#endif
