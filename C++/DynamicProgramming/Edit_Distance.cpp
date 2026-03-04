//2026,xiangyin zhan
/*****************************************************************
//描述

    Given two words word1 and word2, find the minimum number of steps 
required to convert word1 to word2. (each operation is counted as 1 step.)
    You have the following 3 operations permitted on a word:
    • Insert a character
    • Delete a character
    • Replace a character

//分析

    设状态为f[i][j]，表示 A[0,i]和 B[0,j]之间的最小编辑距离。设A[0,i]的形式是
str1c，B[0,j]的形式是str2d，
    1.如果 c==d，则 f[i][j] = f[i-1][j-1]；
    2.如果 c!=d，
        (a)如果将c替换成d，则 f[i][j] = f[i-1][j-1]+1；
        (b)  如果在c后面添加一个d，则 f[i][j] = f[i][j-1]+1；
        (c) 如果将c删除，则 f[i][j] = f[i-1][j]+1；

******************************************************************/

//代码
//动态规划
//LeetCode, Edit Distance
//二维动态规划，时间复杂度O(n*m)，空间复杂度O(n*m)

class Solution{
    public:
    int minDistance(const string &word1, const string &word2){
        const size_t n = word1.size();
        const size_t m = word2.size();
        //长度为n的字符串，有n+1个隔板
        int f[n + 1][m + 1];
        for(size_t i = 0; i <= n; i++)
        f[i][0] = i;
        
        for(size_t j = 0; j <= m; j++)
        f[0][j] = j;
        
        for(size_t i = 1; i <= n; i++){
            for(size_t j = 1; j <= m; j++){
                    if(word1[i - 1] == word2[j - 1])
                            f[i][j] = f[i - 1][j - 1];
            else {
                int mn = min(f[i - 1][j], f[i][j - 1]);
                f[i][j] = 1 + min(f[i - 1][j - 1], mn);
                }
            }
        }
        return f[n][m];
    }
};

//动态规划+滚动数组

//LeetCode, Edit Distance
//二维动规+滚动数组，时间复杂度O(n*m)，空间复杂度O(n)

class Solution{
    public:
        int minDistance(const string &word1,const string &word2){
            if(word1.length() < word2.length())
                return minDistance(word2, word1);
            int f[word2.length() + 1];
            int upper_left = 0;  //额外用一个变量记录f[i-1][j-1]

            for(size_t i = 0; i <= word2.size(); ++i) 
                f[i] = i;

                for(size_t j = 1; j <= word2.size(); ++i){
                     upper_left = f[0];
                     f[0] = i;

                     for(size_t j = 1; j <= word2.size(); ++j){
                        int upper = f[j];

                        if(word1[i - 1] == word2[j - 1])
                            f[j] = upper_left;
                        else
                            f[j] = 1 + min(upper_left, min(f[j], f[j - 1]));

                            upper_left = upper;
                    }
            }
            return f[word2.length()];
     }
};