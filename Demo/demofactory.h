#ifndef DEMOFACTORY_H
#define DEMOFACTORY_H

#include "demo.h"

class DemoFactory
{
public:
    static DemoFactory& instance();
    ~DemoFactory();

    enum DEMONUMBER{
        ENUM_DEMO_unknown = 0,
        ENUM_DEMO_1st,
        ENUM_DEMO_2nd,
        ENUM_DEMO_3rd,
        ENUM_DEMO_4th,
        ENUM_DEMO_5th,
        ENUM_DEMO_6th,
        ENUM_DEMO_7th,
        ENUM_DEMO_8th,
        ENUM_DEMO_9th,
        ENUM_DEMO_10th,
        ENUM_DEMO_11st,
        ENUM_DEMO_max
    };

public:
    Demo* createDemoCase(const int nCaseNo);

private:
    explicit DemoFactory();
};

#endif // DEMOFACTORY_H
