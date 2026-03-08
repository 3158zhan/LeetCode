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

//Binary Tree Zigzag Level Order Traversal
//描述

    Given a binary tree, return the zigzag level order traversal of its nodes’ values. 
(ie, from left to right,then right to left for the next level and alternate between).
    For example: Given binary tree {3, 9, 20, #, #, 15, 7}
        3
       / \
      9  20
        /  \
       15   7

return its bottom-up level order traversal as:
    [
      [15,7]
      [9,20],
      [3],
    ]

//分析

    在上一题(binary-tree-tevel-order-traversal）的基础上，reverse()一下即可。


******************************************************************/

//代码
//递归法
//LeetCode, Binary Tree Level Order  Traversal II
//使用栈，时间复杂度O(n)，空间复杂度O(n)

class Solution{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root){
        traverse(root, 1, result);
        std::reverse(result.begin(), result.end());  //比上题多次一行
        return result;
    }

    void traverse(TreeNode *root, size_t level, vector<vector<int>> &result){
        if(!root) return;

        if(level > result.size())
            result.push_back(vector<int>());

            result[level-1].push_back(root->val);
            traverse(root->left, level+1, result);
            traverse(root->right, level+1, result);
    }
    
};

