#ifndef LONGESTPALINDROME_H
#define LONGESTPALINDROME_H

/**
 * @ProjName:   Demo
 * @FileName:   longestpalindrome.h
 * @Author:     zhuanghs
 * @Date:       2020-06-29 17:55
 * @Brief:      LeetCode 5. 最长回文子串
                给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
                示例 1：
                输入: "babad"
                输出: "bab"
                注意: "aba" 也是一个有效答案。

                示例 2：
                输入: "cbbd"
                输出: "bb"
 */
#include "demo.h"

class longestPalindrome
{
public:
    enum ENUM_DEMO_ALGOTYPE{
        ENUM_DEMO_ALGOTYPE_Dynamic,//动态规划
        ENUM_DEMO_ALGOTYPE_Center,//中心扩散
        ENUM_DEMO_ALGOTYPE_Manacher//Manacher
    };

public:
    explicit longestPalindrome();
    ~longestPalindrome();

public:
    void setProblemDesc(Demo* pDemo);
    void calcResult(Demo *pDemo);

public:
    QPair<int, int> expandAroundCenter(const QString &s,int nLeft, int nRight);
    int expand(const QString &s, int nLeft, int nRight);
    QString findLongestPalindromeInOriginalString(QString &s, const int &nAlgoType);
};

#endif // LONGESTPALINDROME_H
