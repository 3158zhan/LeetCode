//2026,xiangyin zhan
/*****************************************************************

//LeetCode ,线性表
//这类题目考察线性表的操作，例如，数组，单链表，双向链表等。


//LeetCode, Next Permutation
//描述

    Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
    If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
    The replacement must be in-place, do not allocate extra memory.
    Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

    1,2,3 → 1,3,2
    3,2,1 → 1,2,3
    1,1,5 → 1,5,1

//分析

    算法过程如图image/next-Permutation.png所示(下一个排列算法流程)

******************************************************************/



//代码

// LeetCode, Next Permutation
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    void nextPermutation(vector<int> &nums){
        next_permutation(nums.begin(), nums.end());
    }

    template<typename BidiIt>
    bool next_permutation(NidiIt first, BidiIt last){
    // Get a reversed range to simplfy reversed traversal.
    const auto rfirst = reverse_iterator<BidiIt>(last);
    const auto rlast = reverse_iterator<BidiIt>(first);

    //Begin from the second last element to the first element.
    auto pivot = next(rfirst);
    
    //Find 'pivot', which is the first element taht is no less than its
    // successor. 'Prev' is used since 'pivort' is a 'reversed_iterator'.
    while (pivot != rlast && *pivot >= *prev(pivot))
        ++pivot;

        //No such element found, current sequence is already the largest
        //permutation, then rearrange to the first permutation and return false.
        if(pivot == rlast){
            reverse(rfirst, rlast);
            return false;
        }

        //Scan from right to left, find the first element that is greater than
        //'pivot'.
        auto change = find_if(rfirst, oivot, bind1st(less<int>(), *pivot));

        swap(*change, *pivot);
        reverse(rfirst, pivot);

        return ture;
    }
};


