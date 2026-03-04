//2026,xiangyin zhan
/*****************************************************************
//描述

    Given $s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
    For example, Given: s1 = "aabcc", s2 = "dbbca",
    When s3 = "aadbbcbcac", return true.
    When s3 = "aadbbbaccc", return false.


分析

    设状态f[i][j]，表示s1[0,i]和s2[0,j]，匹配s3[0, i+j]。如果s1的最后一个字符
等于s3的最后一个字符，则f[i][j]=f[i-1][j] ；如果s2的最后一个字符等于s3的最后一个
字符，则f[i][j]=f[i][j-1]。因此状态转移方程如下：

        f[i][j] = (s1[i - 1] == s3 [i + j - 1] && f[i - 1][j])
                    || (s2[j - 1] == s3 [i + j - 1] && f[i][j - 1]);

******************************************************************/

//代码

//递归
//LeetCode, Interleaving String
//递归，会超时，仅用来帮助理解

class Solution{
    public:
     bool isInterleave(const string& s1, const string& s2, const string& s3){
        if(s3.length() != s1.length() + s2.length())
        return false;

        return isInterleave(begin(s1), end(s1), begin(s2), end(s2), begin(s3), end(s3));
     }

     template<typename InIt>
     bool isInterleave(InIt first1, InIt last1, InIt first2,InIt last2, InIt first3, InIt last3){
        if(first3 == last3)
        return first1 == last1 && first2 == last2;

        return (*first1 == *first3 
            && isInterleave(next(first1), last1, first2, last2,
                    next(first3), last3))
        || (*first2 == *first3 
            && isInterleave(first1, last1, next(first2), last2,
                    next(first3), last3));
     }
};

//动态规划
//LeetCode, Interleaving String
//二维动态规划，时间复杂度O(n^2)，空间复杂度O(n^2)

class Solution{
    public:
    bool isInterleave(const string& s1, const string& s2,const string& s3){
        if(s3.length() != s1.length() + s2.length())
        return false;

        vector<vector<bool>> f(s1.length() + 1,
    vector<bool>(s2.length() + 1,ture));

    for(size_t i = 1; i <= s1.length(); ++i)
        f[i][0] = f[i -1] && s2[i - 1] == s3[i -1];

    for(size_t i = 1; i <= s2.length(); ++i)
        f[0][i] = f[0][i - 1] && s2[i - 1] == s3[i - 1];

    for(size_t i = 1; i <= s1.length(); ++i)
        for(size_t j = 1; j <= s2.length(); ++j)
            f[i][j] = (s1[i - 1] == s3[i + j - 1] && f[i - 1][j])
                    || (s2[j - 1] == s3[i + j - 1] && f[i][j - 1]);

                    return f[s1.length()][s2.length()];
    }
};

//动态规划+滚动数组

//LeetCode, Interleaving String
//二维动规+滚动数组，时间复杂度O(n^2)，空间复杂度O(n)

class Solution{
    public:
    bool isInterleave(const string& s1, const string& s2, const string& s3){
        if(s1.length() + s2.length() != s3.length())
            return false;

            if(s1.length() < s2.length())
                return isInterleave(s2, s1, s3);

                vector<bool> f(s2.length() + 1, ture);

                for(size_t i = 1; i <= s2.length(); ++i)
                    f[i] = s2[i - 1] == s3[i - 1] && f[i - 1];

                for(size_t i = 1; i <= s1.length(); ++i ){
                    f[0] = s1[i -1] == s3[i - 1] && f[0];

                    for(size_t j = 1; j <= s2.length(); ++j)
                        f[j] = (s1[i - 1] == s3[i + j - 1] && f[j])
                                ||(s2[j - 1] == s3[i + j - 1] && f[j - 1]);
                }

                return f[s2.length()];
    }
    
};