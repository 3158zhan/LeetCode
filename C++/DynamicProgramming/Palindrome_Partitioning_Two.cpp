//2026,xiangyin zhan
/*****************************************************************
//描述

    Given a string s, partition s such that every substring of the partition is a palindrome.
    Return the minimum cuts needed for a palindrome partitioning of s.
    For example, given s = "aab",
    Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

分析
    定义状态 f(i,j) 表示区间 [i,j] 之间最小的cut数，则状态转移方程为 

        f(i,j)=min{f(i,k)+f(k+1,j)}, i <= k <= j, 0 <= i <= j < n

这是一个二维函数，实际写代码比较麻烦。
 
    所以要转换成一维DP。如果每次，从i往右扫描，每找到一个回文就算一次DP的话，就可以
转换为f(i)=区间[i, n-1]之间最小的cut数}，n为字符串长度，则状态转移方程为

            f(i)= min {f(j+1)+1 }, i <= j < n

    一个问题出现了，就是如何判断fn{[i,j]}是否是回文？每次都从i到j比较一遍？
太浪费了，这里也是一个DP问题。

定义状态fn{P[i][j] = true if [i,j]为回文?，那么

        P[i][j] = str[i] == str[j] && P[i+1][j-1]

******************************************************************/

//代码

//LeetCode, Palindrome Partitioning II
//时间复杂度O(n^2)，空间复杂度O(n^2)

class Solution{
    public:
    int minCut(const string& s){
        const int n = s.size();
        int f[n+1];
        bool p[n][n];
        fill_n(&p[0][0], n * n, false);
        //the worst case is cutting by each char
        for(int i = 0; i <= n; i++)
            f[i] = n - 1 - i;  //最后一个f[n]=-1
        for(int i = n -1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] && (j - i < 2 || p[i + 1][j -1])){
                    p[i][j] = true;
                    f[i] = min(f[i], f[j + 1] + 1);
                }
            }
        }
        return f[0];
    }
};

