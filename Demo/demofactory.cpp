#include "demofactory.h"
DemoFactory::DemoFactory()
{
    initMapData();
    m_pDemo = new Demo;
    m_pDemo->setProblemGroupBoxData(m_mapProblem);
    m_pDemo->setProblemGroupBoxIndex(0);
    connect(m_pDemo,SIGNAL(indexChange(int)), this, SLOT(slotDemoCaseChange(int)));
}

void DemoFactory::initMapData()
{
    m_mapProblem.insert(ENUM_DEMO_unknown, QObject::tr("无"));
    m_mapProblem.insert(ENUM_DEMO_1st, QObject::tr("1"));
    m_mapProblem.insert(ENUM_DEMO_2nd, QObject::tr("2"));
    m_mapProblem.insert(ENUM_DEMO_3rd, QObject::tr("3"));
    m_mapProblem.insert(ENUM_DEMO_4th, QObject::tr("4. 寻找两个正序数组的中位数"));
    m_mapProblem.insert(ENUM_DEMO_5th, QObject::tr("5. 最长回文子串"));
    m_mapProblem.insert(ENUM_DEMO_6th, QObject::tr("6"));
    m_mapProblem.insert(ENUM_DEMO_7th, QObject::tr("7"));
    m_mapProblem.insert(ENUM_DEMO_8th, QObject::tr("8"));
    m_mapProblem.insert(ENUM_DEMO_9th, QObject::tr("9"));
    m_mapProblem.insert(ENUM_DEMO_10th, QObject::tr("10"));
    m_mapProblem.insert(ENUM_DEMO_11st, QObject::tr("11"));
}

DemoFactory::~DemoFactory()
{
    m_mapProblem.clear();
}

DemoFactory& DemoFactory::instance()
{
    static DemoFactory m_instance;
    return m_instance;
}

int DemoFactory::getDemoInedx()
{
    return m_pDemo->getProblemCurrentNo();
}

Demo* DemoFactory::createDemoBase()
{
    return m_pDemo;
}

void DemoFactory::slotDemoCaseChange(int nCaseNo)
{
    qDebug() << "题目:" << m_mapProblem.value(nCaseNo);
    return;
}
