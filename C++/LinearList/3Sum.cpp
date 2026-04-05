//2026,xiangyin zhan
/*****************************************************************

//LeetCode ,线性表
//这类题目考察线性表的操作，例如，数组，单链表，双向链表等。


//LeetCode, 3 Sum
//描述

    Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
    Note:
    • Elements in a triplet (a, b, c) must be in non-descending order. (ie, a ≤ b ≤ c)
    • The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4}.
    A solution set is:
        (-1, 0, 1)
        (-1, -1, 2)

//分析

    先排序，然后左右夹逼，复杂度O(n^2).
    这个方法可以推广到k-sum,先排序，然后做k - 2次循环，在最内层循环左右夹逼，
时间复杂度是O(max{nlogn, n^k-1})。


******************************************************************/



//代码


// LeetCode, 3Sum
// 先排序，然后左右夹逼，注意跳过重复的数，时间复杂度O(n^2)，空间复杂度O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> result;
        if(nums.size() < 3) return result;
        sort(nums.begin(),, nums.end());
        const int target = 0;

        auto last = nums.end();
        for(auto i = nums.begin(); i < last-2; ++i){
            auto j = i+1;
            if(i > nums.begin() && *i == *(i-1)) continue;
            auto k = last-1;
            while(j < k){
                if(*i + *j + *k < target){
                    ++j;
                    while(*j == *(j - 1) && j < k) ++j;

                } else if (*i + *j + *k > target){
                    --k;
                    while(*k == *(k + 1) && j < k) --k;
                } else {
                    result.push_back({*i, *j, *k});
                    ++j;
                    --k;
                    while(*j == *(j - 1) && *k == *(k + 1) && j < k) ++j;
                }
            }
        }
        return result;
    }
};

