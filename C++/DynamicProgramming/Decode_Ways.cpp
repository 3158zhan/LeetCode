//2026,xiangyin zhan
//Decode Ways
/*****************************************************************

//描述

    A message containing letters from A-Z is being encoded to numbers 
using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

    Given an encoded message containing digits, determine the total number 
of ways to decode it.

    For example,
    Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
    The number of ways decoding "12" is 2.

//分析

    跟 Climbing Stairs 很类似，不过多加一些判断逻辑。


******************************************************************/

//代码
//动态规划
//LeetCode, Decode Ways
//二维动态规划，时间复杂度O(n)，空间复杂度O(1)

class Solution{
    public:
        int numDecodings(conststring &s) {
            if(s.empty() || s[0] == '0') return 0;

            int prev = 0;
            int cur = 1;
            //长度为n的字符串，有n+1个阶梯
            for(size_t i = 1; i <= s.size(); ++i){
                if(s[i-1] == '0') cur = 0;

                if(i < 2 || !(s[i - 2] == '1' ||
                    (s[i - 2] == '2' && s[i - 1] <= '6')))
                    prev = 0;

                    int tmp = cur;
                    cur = prev + cur;
                    prev = tmp;
            }
            return cur;
        }
};

