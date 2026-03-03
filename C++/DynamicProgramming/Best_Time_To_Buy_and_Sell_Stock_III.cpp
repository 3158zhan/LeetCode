//2026,xiangyin zhan
/*****************************************************************
//描述

    Say you have an array for which the i-th element is the price of a given stock on day i.
    Design an algorithm to find the maximum profit. You may complete at most two transactions.
    Note: You may not engage in multiple transactions at the same time (ie, you must sell the 
stock before you buy again).


分析
    设状态f(i)，表示区间[0,i](0 <= i <= n-1)的最大利润，状态g(i)，表示区间[i, n-1](0 <= i <= n-1)
的最大利润，则最终答案为 max{f(i)+g(i)},0 <= i <= n-1。

    允许在一天内买进又卖出，相当于不交易，因为题目的规定是最多两次，而不是一定要两次。
    将原数组变成差分数组，本题也可以看做是最大 m 子段和, m = 2.

******************************************************************/

//代码

//LeetCode, Best Time to Buy and Stock III
//时间复杂度O(n)，空间复杂度O(n)

class Solution{
    public:
     int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        const int n = prices.size();
        vector<int> f(n, 0);
        vector<int> g(n, 0);

        for (int i = 1, valley = prices[0]; i < n; ++i) {
            valley = min(valley, prices[i]);
            f[i] = max(f[i - 1], prices[i] - valley);
        }

        for (int i = n - 2, peak = prices[n - 1]; i >= 0; --i) {
            peak = max(peak, prices[i]);
            g[i] = max(g[i], peak - prices[i]);
        }

        int max_profit = 0;
        for (int i = 0; i < n; ++i)
            max_profit = max(max_profit, f[i] + g[i]);

        return max_profit;
    }
};

