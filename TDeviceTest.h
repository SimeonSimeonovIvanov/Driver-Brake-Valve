/*
		The^day^of^DooM

	Create Date:	14.05.2012
	Last Update:	19.05.2012
	Full Change:	20.05.2012
	Last Update:	29.05.2012
    Last Update:	29.05.2012
*/

#include <time.h>
#include <stdio.h>
#include <Chart.hpp>
#include <Classes.hpp>

class TDeviceTest {
private:
    long count;
    TList *lpTestData[7];
    struct tm testTime;
    AnsiString SerialNumber;

public:
    TDeviceTest();
    ~TDeviceTest();
    void Free(void);

    void setTestTime(void);
    void setTestTime(struct tm *lpTime);
    void getTestTime(struct tm *lpTime);
    const struct tm * getTestTime(void);

    void getTestDataFromChart(TChart *lpChart);
    void setTestDataToChart(TChart *lpChart, double inc);

    long getSeriesCount(void);
    long getSeriesCount(int chart);

    void addToSeries(unsigned int series, double data);

    double getYValue(unsigned int series, unsigned int x);

    AnsiString getSerialNumber();
    void setSerialNumber(AnsiString sn);

    void save_to_file_ptr(FILE *fp);
    void load_from_file_ptr(FILE *fp);
};
