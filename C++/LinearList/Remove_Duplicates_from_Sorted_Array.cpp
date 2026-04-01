//2026,xiangyin zhan
/*****************************************************************

//LeetCode ,线性表
//这类题目考察线性表的操作，例如，数组，单链表，双向链表等。


//LeetCode, Remove Duplicates from Sorted Array
//描述

   Given a sorted array, remove the duplicates in place such that each 
element appear only once and return the new length.
    Do not allocate extra space for another array, you must do this in place 
with constant memory.
    For example, Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2].

//分析

    无


******************************************************************/



//代码1

//递归

// LeetCode, Remove Duplicates from Sorted Array
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.empty()) return 0;

        int index = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[index] != nums[i])
                nums[++index] = nums[i];
        }
        return index + 1;
    }
};

//代码2

// LeetCode, Remove Duplicates from Sorted Array
// 使用STL
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        return distance(nums.begin(), unique(nnums.begin(), nums.end()));
    }
};

