#include "caselibrary.h"
#include "longestpalindrome.h"
#include "findmediansortedarrays.h"

CaseLibrary::CaseLibrary()
{
    initMap();
}

void CaseLibrary::initMap()
{
    m_mapDemoCase.insert(4, new findMedianSortedArrays);
    m_mapDemoCase.insert(5, new longestPalindrome);
}

CaseLibrary::~CaseLibrary()
{
    m_mapDemoCase.clear();
}

CaseLibrary& CaseLibrary::getInstance()
{
    static CaseLibrary m_instance;
    return m_instance;
}

Demo* CaseLibrary::getDemoCase(const int& nCaseNo)
{
    return m_mapDemoCase[nCaseNo];
}
