#ifndef CASELIBRARY_H
#define CASELIBRARY_H

#include <QMap>
#include "demo.h"

class CaseLibrary
{
public:
    static CaseLibrary& getInstance();
    ~CaseLibrary();

public:
    void initMap();
    Demo* getDemoCase(const int& nCaseNo);

private:
    explicit CaseLibrary();
    QMap<int, Demo*>  m_mapDemoCase;
};

#endif // CASELIBRARY_H
