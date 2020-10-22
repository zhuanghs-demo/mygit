#include "findmediansortedarrays.h"

findMedianSortedArrays::findMedianSortedArrays()
{

}

findMedianSortedArrays::~findMedianSortedArrays()
{

}

void findMedianSortedArrays::setProblemDesc(Demo *pDemo)
{
    if(!pDemo) return;
    QString str = "给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。\n \
            请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。\n \
            你可以假设 nums1 和 nums2 不会同时为空。\n \
            示例 1: \n \
            nums1 = [1, 3] \n \
            nums2 = [2] \n \
            则中位数是 2.0 \n \
            \n \
            示例 2: \n \
            nums1 = [1, 2] \n \
            nums2 = [3, 4] \n \
            则中位数是 (2 + 3)/2 = 2.5";
     pDemo->setProblemDesc(str);
}

void findMedianSortedArrays::calcResult(Demo* pDemo)
{
    if(!pDemo) return;
    QVector<int> nums1, nums2;
    nums1.clear();
    nums2.clear();
    QStringList listNums1 = pDemo->getInput1Str().split(',');
    for(const QString &strNum:listNums1){
        nums1.append(strNum.toInt());
    }
    QStringList listNums2 = pDemo->getInput2Str().split(',');
    for(const QString &strNum:listNums2){
        nums2.append(strNum.toInt());
    }
    pDemo->setAlgoStart();
    double dResult = findMedianSortedArraysUseDichotomy(nums1, nums2);
    pDemo->setAlgoEnd();
    pDemo->setOutputStr(QString::number(dResult));
}

/**
 * @brief: 二分法查找 时间复杂度：O(log⁡(m+n)) 空间复杂度：O(1)
 * @param:
 * @return:
 */

int getKthElement(const QVector<int>& nums1, const QVector<int>& nums2, int k)
{
    /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
     * 这里的 "/" 表示整除
     * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
     * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
     * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
     * 这样 pivot 本身最大也只能是第 k-1 小的元素
     * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
     * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
     * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
     */

    int m = nums1.size();
    int n = nums2.size();
    int index1 = 0, index2 = 0;

    while (true) {
        // 边界情况
        if (index1 == m) {
            return nums2[index2 + k - 1];
        }
        if (index2 == n) {
            return nums1[index1 + k - 1];
        }
        if (k == 1) {
            return std::min(nums1[index1], nums2[index2]);
        }

        // 正常情况
        int newIndex1 = std::min(index1 + k / 2 - 1, m - 1);
        int newIndex2 = std::min(index2 + k / 2 - 1, n - 1);
        int pivot1 = nums1[newIndex1];
        int pivot2 = nums2[newIndex2];
        if (pivot1 <= pivot2) {
            k -= newIndex1 - index1 + 1;
            index1 = newIndex1 + 1;
        }
        else {
            k -= newIndex2 - index2 + 1;
            index2 = newIndex2 + 1;
        }
    }
    return 0;
}

double findMedianSortedArrays::findMedianSortedArraysUseDichotomy(QVector<int>& nums1, QVector<int>& nums2)
{
    int totalLength = nums1.size() + nums2.size();
    if (totalLength % 2 == 1) {
        return getKthElement(nums1, nums2, (totalLength + 1) / 2);
    }else {
        return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
    }
    return 0.0;
}
