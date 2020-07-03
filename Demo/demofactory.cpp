#include "demofactory.h"
#include "caselibrary.h"

DemoFactory::DemoFactory()
{

}

DemoFactory::~DemoFactory()
{

}

DemoFactory& DemoFactory::instance()
{
    static DemoFactory m_instance;
    return m_instance;
}

Demo* DemoFactory::createDemoCase(const int& nCaseNo)
{
    return CaseLibrary::getInstance().getDemoCase(nCaseNo);
}
