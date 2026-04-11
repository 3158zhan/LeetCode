//2026,xiangyin zhan
/*****************************************************************

//LeetCode ,线性表
//这类题目考察线性表的操作，例如，数组，单链表，双向链表等。


//LeetCode, Remove Element
//描述

    Given an array and a value, remove all instances of that value in place and return the new length.
    The order of elements can be changed. It doesn’t matter what you leave beyond the new length

//分析

    无

******************************************************************/



//代码1

// LeetCode, Remove Element
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int removeElement(vector<int> & nums, int target){
        int index = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != target) {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};



//代码2

// LeetCode, Remove Element
// 使用remove()
// 时间复杂度，O(n)，空间复杂度O(1)
class Solution {
public:
    int removeElement(vector<int> & nums, int target){
        return distance(nums.begin(), remove(nums.begin(),nums.end(), target));
    }
};

