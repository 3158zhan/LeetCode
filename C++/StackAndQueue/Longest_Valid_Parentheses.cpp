//2026,xiangyin zhan
/*****************************************************************

//LeetCode ,栈和队列


//LeetCode, Longest Valid Parentheses
//描述

    Given a string containing just the characters '(' and ')', find the length of the longest valid (wellformed) parentheses substring.
For "(()", the longest valid parentheses substring is "()", which has length = 2.
Another example is ")()())", where the longest valid parentheses substring is "()()", which has
length = 4.

//分析

    无


******************************************************************/

//代码


//LeetCode, Longest Valid Parentheses
//时间复杂度O(n)，空间复杂度O(n)

class Solution {
public:
    int longestValidParentheses(const string& s){
        int max_len = 0, last = -1;  //the position of the last ')'
        stack<int> lefts;  //keep track of the positions of non-matching '('s

        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                lefts.push(i);

            } else {
                if(lefts.empty()) {
                    // no matching left
                    last = i;
            } else {
                //find a matching pair
                lefts.pop();
                if(lefts.empty()){
                    max_len = max(max_len, i-last);
                
                } else {
                    max_len = max(max_len, i-lefts.top());
                }
            }
        }
    }
    return max_len;
  }
     
};