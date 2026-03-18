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

//LeetCode, Validate Binary Search Tree
//描述

    Given a binary tree, determine if it is a valid binary search tree (BST).
    Assume a BST is defined as follows:
    • The left subtree of a node contains only nodes with keys less than the node’s key.
    • The right subtree of a node contains only nodes with keys greater than the node’s key.
    • Both the left and right subtrees must also be binary search trees


//分析

    
******************************************************************/

//代码


//LeetCode, Validate Binary Search Tree
//时间复杂度O(n)，空间复杂度O(logn)

class Solution{
public:
    bool isValidBST(TreeNode * root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }

    bool isValidBST(TreeNode* root, int lower, int upper) {
        if(root == nullptr) return true;
        return root->val > lower && root->val < upper
                    && isValidBST(root->left, lower, root->val)
                    && isValidBST(root->right, root->val, upper);
    }
};

