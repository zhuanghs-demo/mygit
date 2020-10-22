#ifndef DEMOFACTORY_H
#define DEMOFACTORY_H

#include "demo.h"
#include "problemtypeno.h"
using namespace problemspace;

class DemoFactory : public QObject
{
    Q_OBJECT
public:
    static DemoFactory& instance();
    ~DemoFactory();

public:
    int getDemoInedx();
    Demo* createDemoBase();


protected slots:
    void slotDemoCaseChange(int nCaseNo);

private:
    explicit DemoFactory();
    void initMapData();

private:
    Demo* m_pDemo;
    QMap<int, QString> m_mapProblem;
};

#endif // DEMOFACTORY_H
