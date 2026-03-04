//2026,xiangyin zhan
//Distinct Subsequences
/*****************************************************************

//描述

    Given a string S and a string T, count the number of distinct subsequences of T in S.
    A subsequence of a string is a new string which is formed from the original string 
by deleting some (can be none) of the characters without disturbing the relative 
positions of the remaining characters. 
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

    Here is an example: S = "rabbbit", T = "rabbit"
Return 3.


//分析

    设状态为$f(i,j)$，表示\fn{T[0,j]}在\fn{S[0,i]}里出现的次数。首先，无论\fn{S[i]}和 
T[j]是否相等，若不使用 S[i]，则 f(i,j)=f(i-1,j) ；若 S[i]==T[j]，则可以使用 S[i]，
此时 f(i,j) = f(i-1,j) + f(i - 1 , j - 1)。


******************************************************************/

//代码
//动态规划
//LeetCode, Distinct Subsequnces
//二维动态规划+滚动数组，时间复杂度O(m*n)，空间复杂度O(n)

class Solution{
    public:
        int numDistinct(const string &S,const string &T) {
            vector<int> f(T.size() + 1);
            f[0] = 1;
            for(int i = 0; i < S.size(); ++i){
                for(int j = T.size() - 1; j >= 0; --j) {
                    f[j + 1] += S[i] == T[j] ? f[j] : 0;
                }
            }
            return f[T.size()];
        }
};

