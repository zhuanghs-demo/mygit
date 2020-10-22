#include "longestpalindrome.h"

longestPalindrome::longestPalindrome()
{

}

longestPalindrome::~longestPalindrome()
{

}

void longestPalindrome::setProblemDesc(Demo *pDemo)
{
    if(!pDemo) return;
    QString str = "给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。\n \
            示例 1： \n \
            输入: \"babad\" \n \
            输出: \"bab\" \n \
            注意: \"aba\" 也是一个有效答案。 \n \
            \n \
            示例 2： \n \
            输入: \"cbbd\" \n \
            输出: \"bb\"";
     pDemo->setProblemDesc(str);
}

void longestPalindrome::calcResult(Demo *pDemo)
{
    if(!pDemo) return;
    QString strInput = pDemo->getInput1Str();
    pDemo->setAlgoStart();
    QString strOutput = findLongestPalindromeInOriginalString(strInput, ENUM_DEMO_ALGOTYPE_Dynamic);
    pDemo->setAlgoEnd();
    pDemo->setOutputStr(strOutput);
}

/**
 * @brief:查找中心子串的回文边界
 * @param: 原始字符串 左右索引
 * @return:回文边界
 */
QPair<int, int> longestPalindrome::expandAroundCenter(const QString &s, int nLeft, int nRight)
{
    while(nLeft >=0 && nRight < s.size() && s[nLeft] == s[nRight]){
        nLeft--;
        nRight++;
    }
    return {nLeft+1, nRight-1};
}

/**
 * @brief:查找中心子串的回文边界
 * @param: 原始字符串 左右索引
 * @return:回文臂长
 */
int longestPalindrome::expand(const QString &s, int nLeft, int nRight)
{
    while(nLeft >=0 && nRight < s.size() && s[nLeft] == s[nRight]){
        nLeft--;
        nRight++;
    }
    return (nRight-nLeft-2)/2;
}

QString longestPalindrome::findLongestPalindromeInOriginalString(QString &s, const int &nAlgoType)
{
    int nStart = 0;
    int nEnd = -1;
    QString sAns;
    sAns.clear();

    if(nAlgoType == ENUM_DEMO_ALGOTYPE_Dynamic){
        /**
         * @brief:找到一个字符串的最长回文子串，动态规划算法 时间复杂度O(N*N) 空间复杂度O(N*N)
         * @param: 原始字符串
         * @return: 最长回文子串
         */
        int n = s.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n));
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                }
                else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && l + 1 > nEnd-nStart) {
                    nStart = i;
                    nEnd = i + l;
                }
            }
        }
        sAns = s.mid(nStart, nEnd - nStart + 1);
    }else if(nAlgoType == ENUM_DEMO_ALGOTYPE_Center){
        /**
         * @brief:找到一个字符串的最长回文子串，中心扩散算法 时间复杂度O(N*N) 空间复杂度O(1)
         * @param: 原始字符串
         * @return: 最长回文子串
         */
        for(int i=0; i < s.size(); ++i){
            QPair<int, int> pair1 = expandAroundCenter(s, i, i);
            QPair<int, int> pair2 = expandAroundCenter(s, i, i+1);
            if(pair1.second - pair1.first > nEnd -nStart){
                nStart = pair1.first;
                nEnd = pair1.second;
            }
            if(pair2.second - pair2.first > nEnd -nStart){
                nStart = pair2.first;
                nEnd = pair2.second;
            }
        }
        sAns = s.mid(nStart, nEnd - nStart + 1);
    }else if(nAlgoType == ENUM_DEMO_ALGOTYPE_Manacher){
        /**
         * @brief:找到一个字符串的最长回文子串，Manacher算法 时间复杂度O(N) 空间复杂度O(N)
         * @param: 原始字符串
         * @return: 最长回文子串
         */
        std::string sTransform = "#";
        for(int i = 0; i < s.size(); ++i){
            sTransform += s[i].toAscii();
            sTransform += '#';
        }
        s = sTransform.c_str();

        std::vector<int> arm_len;
        int nMaxRight = -1, nCenter = -1;
        for(int i = 0; i < s.size(); ++i){
            int cur_arm_len;
            if(nMaxRight > i){
                int i_sym = nCenter*2 - i;
                int min_arm_len = std::min(arm_len[i_sym], nMaxRight-i);
                cur_arm_len = expand(s, i - min_arm_len, i + min_arm_len);
            }else{
                cur_arm_len = expand(s, i, i);
            }
            arm_len.push_back(cur_arm_len);
            if(i + cur_arm_len > nMaxRight){
                nCenter = i;
                nMaxRight = i + cur_arm_len;
            }
            if(cur_arm_len*2 + 1 > nEnd - nStart){
                nStart = i - cur_arm_len;
                nEnd = i + cur_arm_len;
            }
        }

        for(int i = nStart; i < nEnd; ++i){
            if(s[i]!='#'){
                sAns += s[i];
            }
        }
    }

    return sAns;
}

