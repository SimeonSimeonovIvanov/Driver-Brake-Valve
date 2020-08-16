/*
		The^day^of^DooM

	Create Date:	14.05.2012
	Last Update:	19.05.2012
	Full Change:	20.05.2012
	Last Update:	29.05.2012
    Last Update:	29.05.2012
*/

#include "TDevice.h"

TDevice::TDevice()
{
    Name = "NONAME";
    analogMeterCount = 0;

    lpTestList = NULL;

    for(int i = 0; i < 7; i++) {
        arrAnalogIputIsEnable[i] = false;
    }

    for(int i = 0; i < 12; i++) {
        arrDigitalOutputIsEnable[i] = false;
    }
}

TDevice::~TDevice() // ?????????????
{
    Free();
}

void TDevice::Free(void)
{
    if(NULL == lpTestList) return;
    for(int i = 0; i < lpTestList->Count; i++) {
        delete (TDeviceTest*)lpTestList->Items[i];
    }
    lpTestList = NULL;
}

void TDevice::writeToFile(FILE *fp)
{
    if(NULL != fp) {
        char *buffer;
        int i = 1 + Name.Length();

        fwrite(&i, sizeof(i), 1, fp);
        if(NULL != (buffer = (char*)malloc(sizeof(char) * i))) {
            sprintf(buffer, "%s", Name);
            fwrite(buffer, i, 1, fp);
            free(buffer);
        }

        fwrite(&analogMeterCount, sizeof(analogMeterCount), 1, fp);
        fwrite(&arrAnalogIputIsEnable, sizeof(arrAnalogIputIsEnable), 1, fp);
        fwrite(&arrDigitalOutputIsEnable, sizeof(arrDigitalOutputIsEnable), 1, fp);

        long n = 0;
        if(NULL != lpTestList) {
            n = lpTestList->Count;
        }
        fwrite(&n, sizeof(long), 1, fp);
        for(i = 0; i < n; i++) {
            ((TDeviceTest*)lpTestList->Items[i])->save_to_file_ptr(fp);
        }
    }
}

void TDevice::readFromFile(FILE *fp)
{
    if(NULL != fp) {
        int i;
        char *buffer;

        Free();

        fread(&i, sizeof(i), 1, fp);
        if(NULL == (buffer = (char*)malloc(sizeof(char) * i))) return;

        fread(buffer, i * sizeof(char), 1, fp);
        Name = buffer;
        free(buffer);

        fread(&analogMeterCount, sizeof(analogMeterCount), 1, fp);
        fread(&arrAnalogIputIsEnable, sizeof(arrAnalogIputIsEnable), 1, fp);
        fread(&arrDigitalOutputIsEnable, sizeof(arrDigitalOutputIsEnable), 1, fp);

        long n;
        fread(&n, sizeof(long), 1, fp);
        if(!n) return; 

        lpTestList = new TList();
        for(i = 0; i < n; i++) {
            TDeviceTest *lpDeviceTest = new TDeviceTest();
            lpTestList->Add(lpDeviceTest);
            ((TDeviceTest*)lpTestList->Items[i])->load_from_file_ptr(fp);
        }
    }
}

long TDevice::getTestCount(void)
{
    if(NULL == lpTestList) return 0;
    return lpTestList->Count;
}

TDeviceTest* TDevice::getTestListData(long n)
{
    TDeviceTest *lpDeviceTest = (TDeviceTest*)lpTestList->Items[n];
    return lpDeviceTest;
}

void TDevice::addToTestList(TDeviceTest *lpTest)
{
    TDeviceTest *lpTemp = new TDeviceTest();

    lpTemp->setTestTime((tm*)lpTest->getTestTime());
    lpTemp->setSerialNumber(lpTest->getSerialNumber());

    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < lpTest->getSeriesCount(i); j++) {
            lpTemp->addToSeries(i, lpTest->getYValue(i, j));
        }
    }

    if(NULL == lpTestList) {
        lpTestList = new TList();
    }
    lpTestList->Add(lpTemp);
}