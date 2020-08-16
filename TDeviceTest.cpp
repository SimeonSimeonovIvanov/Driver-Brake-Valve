/*
		The^day^of^DooM

	Create Date:	14.05.2012
	Last Update:	19.05.2012
	Full Change:	20.05.2012
	Last Update:	29.05.2012
    Last Update:	06.06.2012
*/

#include "TDeviceTest.h"

TDeviceTest::TDeviceTest()
{
    count = 0;
    for(int i = 0; i < ARRAYSIZE(lpTestData); i++) {
        lpTestData[i] = NULL;
    }
}

TDeviceTest::~TDeviceTest()
{
    TDeviceTest::Free();
}

void TDeviceTest::Free(void)
{
    for(int i = 0; i < ARRAYSIZE(lpTestData); i++) {
        if(NULL != lpTestData[i]) {
            for(int j = 0; j < lpTestData[i]->Count; j++) {
                delete lpTestData[i]->Items[j];
            }
            lpTestData[i] = NULL;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
void TDeviceTest::getTestDataFromChart(TChart *lpChart)
{
    for(int i = 0; i < lpChart->SeriesCount(); i++) {
        for(int j = 0; j < lpChart->Series[i]->Count(); j++) {
            addToSeries(i, lpChart->Series[i]->YValue[j]);
        }
    }

    count = lpChart->SeriesCount();
}

void TDeviceTest::setTestDataToChart(TChart *lpChart, double inc)
{
    for(int i = 0; i < sizeof(lpTestData) / sizeof(*lpTestData); i++) {
        double pos = 0;

        lpChart->Series[i]->Clear();
        if(NULL != lpTestData[i]) {
            for(int j = 0; j < lpTestData[i]->Count; j++) {
                lpChart->Series[i]->AddXY(pos, *((double*)lpTestData[i]->Items[j]));
                pos += inc;
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
long TDeviceTest::getSeriesCount(void)
{
    return count;
}

long TDeviceTest::getSeriesCount(int series)
{
    if(NULL == lpTestData[series]) return 0;
    return lpTestData[series]->Count;
}

void TDeviceTest::addToSeries(unsigned int series, double data)
{
    if(series < ARRAYSIZE(lpTestData)) {
        if(NULL == lpTestData[series]) {
            lpTestData[series] = new TList();
        }

        double *temp = new double;
        *temp = data;

        lpTestData[series]->Add(temp);

        count = lpTestData[series]->Count; // ?????????
    }
}

double TDeviceTest::getYValue(unsigned int series, unsigned int x)
{
    double *data = (double*)lpTestData[series]->Items[x];
    return *data;
}

void TDeviceTest::save_to_file_ptr(FILE *fp)
{
    if(NULL == fp) return;

    char *buffer;
    long n = 1 + SerialNumber.Length();

    fwrite(&n, sizeof(n), 1, fp);
    if(NULL != (buffer = (char*)malloc(n * sizeof(char)))) {
        sprintf(buffer, "%s", SerialNumber);
        fwrite(buffer, n, 1, fp);
        free(buffer);
    }

    for(int i = 0; i < ARRAYSIZE(lpTestData); i++) {

        if(NULL == lpTestData[i]) n = 0;
        else n = lpTestData[i]->Count;
        fwrite(&n, sizeof(long), 1, fp);
        if(n) {
            fwrite(&testTime, sizeof(testTime), 1, fp);
        }

        for(int j = 0; j < n; j++) {
            double data;
            data = *((double*)lpTestData[i]->Items[j]);
            fwrite(&data, sizeof(double), 1, fp);
        }
    }
}

void TDeviceTest::load_from_file_ptr(FILE *fp)
{
    if(NULL == fp) return;

    long n;
    char *buffer;

    fread(&n, sizeof(n), 1, fp);
    if(NULL == (buffer = (char*)malloc(n * sizeof(char)))) return;

    fread(buffer, n * sizeof(char), 1, fp);
    SerialNumber = buffer;
    free(buffer);

    Free();

    for(int i = 0; i < ARRAYSIZE(lpTestData); i++) {
        fread(&n, sizeof(long), 1, fp);
        if(n) {
            fread(&testTime, sizeof(testTime), 1, fp);
        }

        for(int j = 0; j < n; j++) {
            double data;
            fread(&data, sizeof(double), 1, fp);
            addToSeries(i, data);
        }
    }
}

void TDeviceTest::setSerialNumber(AnsiString sn)
{
    SerialNumber = sn;
}

AnsiString TDeviceTest::getSerialNumber()
{
    return SerialNumber;
}

void TDeviceTest::setTestTime(void)
{
    struct tm *systime;
    time_t t = time(NULL);
    systime = localtime(&t);
    setTestTime(systime);
}

void TDeviceTest::setTestTime(struct tm *lpTime)
{
    testTime = *lpTime;
}

void TDeviceTest::getTestTime(struct tm *lpTime)
{
    *lpTime = testTime;
}

const struct tm * TDeviceTest::getTestTime(void)
{
    return &testTime;
}
