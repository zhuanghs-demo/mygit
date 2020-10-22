#ifndef FINDMEDIANSORTEDARRAYS_H
#define FINDMEDIANSORTEDARRAYS_H

/**
 * @ProjName:   Demo
 * @FileName:   findmediansortedarrays.h
 * @Author:     zhuanghs
 * @Date:       2020-07-01 12:18
 * @Brief:      LeetCode 4. 寻找两个正序数组的中位数
                给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
                请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
                你可以假设 nums1 和 nums2 不会同时为空。
                示例 1:
                nums1 = [1, 3]
                nums2 = [2]
                则中位数是 2.0

                示例 2:
                nums1 = [1, 2]
                nums2 = [3, 4]
                则中位数是 (2 + 3)/2 = 2.5
 */
#include "demo.h"

class findMedianSortedArrays
{
public:
    explicit findMedianSortedArrays();
    ~findMedianSortedArrays();

public:
    void setProblemDesc(Demo* pDemo);
    void calcResult(Demo* pDemo);
    double findMedianSortedArraysUseDichotomy(QVector<int>& nums1, QVector<int>& nums2);
};

#endif // FINDMEDIANSORTEDARRAYS_H
