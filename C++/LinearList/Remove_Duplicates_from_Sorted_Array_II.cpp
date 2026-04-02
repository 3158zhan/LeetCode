//2026,xiangyin zhan
/*****************************************************************

//LeetCode ,线性表
//这类题目考察线性表的操作，例如，数组，单链表，双向链表等。


//LeetCode, Remove Duplicates from Sorted Array II
//描述

   Follow up for ”Remove Duplicates”: What if duplicates are allowed at most twice?
    For example, Given sorted array A = [1,1,1,2,2,3],
    Your function should return length = 5, and A is now [1,1,2,2,3]

//分析

    加一个变量记录一下元素出现的次数即可。这题因为是已经排序的数组，所以一个变量即可解决。
如果是没有排序的数组，则需要引入一个hashmap来记录出现次数。



******************************************************************/



//代码1


// LeetCode, Remove Duplicates from Sorted Array II
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.size() <= 2)  return nums.size();

        int index = 2;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] != nums[index - 2])
                nums[index++] = nums[i];
        }
        return index;
    }
};

//代码2

// LeetCode, Remove Duplicates from Sorted Array II
// 下面是一个更简洁的版本。上面的代码略长，不过扩展性好一些，
// 例如将occur < 2改为occur < 3，就变成了允许重复最多3次。
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        const int n = nums.size();
        int index = 0;
        for(int i = 0; i < n; ++i){
            if(i > 0 && i < n - 1 && nums[i] == nums[i - 1] 
                && nums[i] == nums[i + 1])
                continue;

            nums[index++] = nums[i];
        }
        return index;
    }
};

