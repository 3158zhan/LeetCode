//2026,xiangyin zhan
/*****************************************************************

//LeetCode ,线性表
//这类题目考察线性表的操作，例如，数组，单链表，双向链表等。


//LeetCode,  Permutation Sequence
//描述

    The set [1,2,3,,n] contains a total of n!unique permutations.
    By listing and labeling all of the permutations in order,We get the following sequence (ie,for n = 3):
    "123"
    "132"
    "213"
    "231"
    "312"
    "321"
    Given n and k,return the kth permutation sequence.
    Note:Given n will be between 1 and 9 inclusive.


//分析

    简单的，可以用暴力枚举法，调用 k-1 次 next_permutation()。
    暴力枚举法把前 k个排列都求出来了，比较浪费，而我们只需要第k个排列。
    利用康托编码的思路，假设有n个不重复的元素，第k个排列是a_1, a_2, a_3, ..., a_n，那么a_1是哪一个位置呢？
    我们把a_1去掉，那么剩下的排列为a_2, a_3, ..., a_n, 共计n-1个元素，n-1个元素共有(n-1)!个排列，
于是就可以知道 a_1 = k / (n-1)!。
    同理，a_2, a_3, ..., a_n的值推导如下：


    k_2 = k%(n-1)! 
    a_2 = k_2/(n-2)! 
        ... 
    k_(n-1) = k_(n-2)%2! 
    a_(n-1) = k_(n-1)/1! 
    a_n = 0 


******************************************************************/



//使用next_permutaion()代码

// LeetCode,  Permutation Sequence
// 使用next_permutaion(),TLE 
class Solution {
public:
    string getPermutation(int n, int k){
        string s(n, '0');
        for(int i = 0; i < n; ++i)
        s[i] += i+1;
    for(int i = 0; i < k-1; ++i)
        next_permutation(s.begin(), s.end());
        return s;
    }

    temlate<typename BiliIt>
    bool next_permutation(BiliIt first, BidiIt last) {
        //代码见Next Permutation
    }
};



// LeetCode,  Permutation Sequence
//康托编码，时间复杂度O(n), 空间复杂度O(1)

class Solution {
public:
    string getPermutation(int n, int k){
        string s(n, '0');
        string result;
        for(int i = 0; i < n; ++i)
        s[i] += i + 1;

        return kth_permutaion(s, k);

    }

private:
    int factorial(int n){
        int result = 1;
        for(int i = 1; i <= n; ++i)
            result *= i;
        return result;
    }

    //seq已经排好序，是第一个排列
    temlate<typename Sequnce>
    Sequnce kth_permutation(const Sequnce &seq, int k){
    const int n = seq.size();
    Sequnce S(seq);
    Sequnce result;

    int base = factorial(n - 1);
    --k; //康托编码从0开始

    for(int i = n - 1; i > 0; k %= base, base /= i, --i){
        auto a = next(S.begin(), k / base);
        result.push_back(*a);
        S.erase(a);
    }

    result.push_back(S[0]); //最后一个
    return result;
    }

    
};