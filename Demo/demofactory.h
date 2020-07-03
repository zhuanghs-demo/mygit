#ifndef DEMOFACTORY_H
#define DEMOFACTORY_H

#include "demo.h"

class DemoFactory
{
public:
    static DemoFactory& instance();
    ~DemoFactory();

public:
    Demo* createDemoCase(const int& nCaseNo);

private:
    explicit DemoFactory();
};

#endif // DEMOFACTORY_H
