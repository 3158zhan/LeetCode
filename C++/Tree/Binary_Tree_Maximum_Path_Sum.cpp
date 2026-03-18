//2026,xiangyin zhan
/*****************************************************************

LeetCode 上二叉树的节点定义如下：
//树的节点
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
}

//LeetCode, Binary Tree Maximum Path Sum
//描述

    Given a binary tree, find the maximum path sum.
    The path may start and end at any node in the tree. For example: Given the below binary tree,
          1
         / \
        2   3
       

return 6.

//分析

    这题很难，路径可以从任意节点开始，到任意节点结束。
    可以利用“最大连续子序列和”问题的思路。如果说Array只有一个方向的话，那么Binary Tree其实只是左、右两个方向而已，
我们需要比较两个方向上的值。
    不过，Array可以从头到尾遍历，那么Binary Tree怎么办呢，我们可以采用Binary Tree最常用的dfs来进行遍历。先算出左右
子树的结果L和R，如果L大于0，那么对后续结果是有利的，我们加上L，如果R大于0，对后续结果也是有利的，继续加上R。

******************************************************************/

//代码


//LeetCode, Binary Tree Maimum Path Sum
//时间复杂度O(n)，空间复杂度O(logn)

class Solution{
    public: 
        int maxPathSum(TreeNode *root) {
            max_sum = INT_MIN;
            dfs(root);
            return max_sum;
        }
        private:
        int max_sum;
        int dfs(const TreeNode *root) {
            if(root == nullptr) return 0;
            int l = dfs(root->left);
            int r = dfs(root->right);
            int sum = root->val;
            if(l > 0) sum += 1;
            if(r > 0) sum += r;
            max_sum = max(max_sum, sum);
            return max(r, l) > 0 ? max(r, l) + root->val : root->val;


        }

};

//注意，最后return的时候，只能返回一个方向上的值，为什么呢？因为在递归中，只能向父节点返回，
// 不可能存在L->root->R的路径，只可能是L->root或R->root。