/*
		The^day^of^DooM

	Create Date:	14.05.2012
	Last Update:	19.05.2012
	Full Change:	20.05.2012
	Last Update:	29.05.2012
    Last Update:	29.05.2012
*/

#include <stdio.h>
#include "TDeviceTest.h"

class TDevice : public TDeviceTest {
private:
    TList *lpTestList;

public:
    TDevice();
    ~TDevice();
    void Free(void);
    
    AnsiString Name;
    int analogMeterCount;
    bool arrAnalogIputIsEnable[7];
    bool arrDigitalOutputIsEnable[12];

    void writeToFile(FILE *fp);
    void readFromFile(FILE *fp);

    long getTestCount(void);
    TDeviceTest* getTestListData(long n);

    void addToTestList(TDeviceTest *lpTest);
    
    TDeviceTest currentTest;
};
