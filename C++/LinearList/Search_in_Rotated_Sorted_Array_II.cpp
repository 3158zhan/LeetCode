//2026,xiangyin zhan
/*****************************************************************

//LeetCode ,线性表
//这类题目考察线性表的操作，例如，数组，单链表，双向链表等。


//LeetCode, Search in Rotated Sorted Array II
//描述

    Follow up for ”Search in Rotated Sorted Array”: What if duplicates are allowed?
    Would this affect the run-time complexity? How and why?
    Write a function to determine if a given target is in the array.

//分析

    允许重复元素，则上一题中如果A[m]>=A[1],那么[1,m]为递增序列的假设就不能成立了，比如[1,3,1,1,1]。
    如果A[m]>=A[1]不能确定递增，那么就把它拆分为两个条件：
    •若A[m]>A[1],则区间[1,m]一定递增
    •若A[m]==A[1]确定不了，那就l++,往下看下一步即可。


******************************************************************/



//代码


// LeetCode, Search in Rotated Sorted Array II
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    bool search(const vector<int>& nums, int target){
        int first = 0,last = nums.size();
        while(first != last){
            const int mid = first + (last - first) / 2;
            if(nums[mid] == target)
                return true;
            if(nums[first] < nums[mid]){
                if(nums[first] <= target && target < nums[mid])
                    last = mid;
                else
                    first = mid + 1;
            } else if(nums[first] > nums[mid]){
                if(nums[mid] < target && target <= nums[last-1])
                    first = mid + 1;
                else    
                    last = mid;
            } else  
                //skip duplicate one
                first++;
        }
        return false; 
    }
};


