//2026,xiangyin zhan
/*****************************************************************

//LeetCode ,贪心算法


//LeetCode, Container With Most Water
//描述

   Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
with x-axis forms a container, such that the container contains the most water.
    Note: You may not slant the container.

//分析

    每个容器的面积，取决于最短的木板。

    


******************************************************************/

//代码
//LeetCode, Container With Most Water
//时间复杂度O(n)，空间复杂度O(1)
//考虑非字母的情况

class Solution{
public:
        int maxArea(vector<int> &height){
            int start = 0;
            int end = height.size() - 1;
            int result = INT_MIN;
            while(start < end){
                int area = min(height[end], height[start]) * (end - start);
                result = max(result, area);
                if(height[start] <= height[end]){
                    start++;

                } else {
                    end--;
                }
            }
            return result;
        }
};

