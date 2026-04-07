//2026,xiangyin zhan
/*****************************************************************

//LeetCode ,线性表
//这类题目考察线性表的操作，例如，数组，单链表，双向链表等。


//LeetCode, 3 Sum Closest
//描述

    Given an array S of n integers, find three integers in S such that the sum is closest to a given number,
target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
    For example, given array S = {-1 2 1 -4}, and target = 1.
    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

//分析

    先排序，然后左右夹逼，复杂度O(n^2).
    


******************************************************************/



//代码


// LeetCode, 3Sum Closest
// 先排序，然后左右夹逼，注意跳过重复的数，时间复杂度O(n^2)，空间复杂度O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums,int target){
        int result = 0;
        int min_gap = INT_MAX;

        sort(nums.begin(), nums.end());

        for(auto a = nums.begin(); a !+ prev(nums.end(), 2); ++a){
            auto b = next(a);
            auto c = prev(nums.end());

            while(b < c){
                const int sum = *a + *b + *c;
                const int gap = abs(sum - target);

                if(gap < min_gap){
                    result = sum;
                    min_gap = gap;
                }

                if(sum < target) ++b;
                else  --c;

            }
        }

        return result;
    }
};

