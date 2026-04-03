//2026,xiangyin zhan
/*****************************************************************

//LeetCode ,线性表
//这类题目考察线性表的操作，例如，数组，单链表，双向链表等。


//LeetCode, Two Sum
//描述

    Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where
index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not
zero-based.
You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

//分析

    方法1：暴力，复杂度O(n^2)，会超时。
    方法2：hash。用一个哈希表，存储每个数对应的下标，复杂度O(n).
    方法3：先排序，然后左右夹逼，排序O(nlogn),左右夹逼O(n)，最终O(nlogn)。
但是注意，这题需要返回的是下标，而不是数字本身，因此这个方法行不通。


******************************************************************/



//代码


// LeetCode, Two Sum
// 时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    vector<int> twoSum(vector<int> &nums,int target){
        unordered_map<int, int> mapping;
        vector<int> result;
        for(int i = 0;i < nums.size(); i++){
            mapping[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            const int gap = target - nums[i];
            if(mapping.find(gap) != mapping.end() && mapping[gap] > i){
                result.push_back(i + 1);
                result.push_back(mapping[gap] + 1);
                break;
            }
        }
        return result;
    }
};

