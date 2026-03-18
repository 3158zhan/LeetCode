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

//LeetCode, Maximum Depth of Binary  Tree
//描述

    Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the
farthest leaf node.

//分析

    

******************************************************************/

//代码


//LeetCode, Maximum Depth of Binary  Tree
//时间复杂度O(n)，空间复杂度O(logn)

class Solution{
public:
    int maxDepth(TreeNode *root) {
        if(root == nullptr) return 0;

        return max(maxDepth(root->left),maxDepth(root->right)) + 1;
    }

};
