#include "demofactory.h"
#include "longestpalindrome.h"
#include "findmediansortedarrays.h"

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

Demo* DemoFactory::createDemoCase(const int nCaseNo)
{
    if(nCaseNo == ENUM_DEMO_unknown){
        return nullptr;
    }else if(nCaseNo == ENUM_DEMO_1st){
        return nullptr;
    }else if(nCaseNo == ENUM_DEMO_2nd){
        return nullptr;
    }else if(nCaseNo == ENUM_DEMO_3rd){
        return nullptr;
    }else if(nCaseNo == ENUM_DEMO_4th){
        return new findMedianSortedArrays;
    }else if(nCaseNo == ENUM_DEMO_5th){
        return new longestPalindrome;
    }else if(nCaseNo == ENUM_DEMO_6th){
        return nullptr;
    }else if(nCaseNo == ENUM_DEMO_7th){
        return nullptr;
    }else if(nCaseNo == ENUM_DEMO_8th){
        return nullptr;
    }else if(nCaseNo == ENUM_DEMO_9th){
        return nullptr;
    }else if(nCaseNo == ENUM_DEMO_10th){
        return nullptr;
    }else if(nCaseNo == ENUM_DEMO_11st){
        return nullptr;
    }else if(nCaseNo == ENUM_DEMO_max){
        return nullptr;
    }
    return nullptr;
}
