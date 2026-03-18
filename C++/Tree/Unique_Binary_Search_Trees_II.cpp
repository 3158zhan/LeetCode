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

//LeetCode, Unique Binary Search Trees II 
//描述

    Given n, generate all structurally unique BST’s (binary search trees) that store values 1...n.
    For example, Given n = 3, your program should return all 5 unique BST’s shown below
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

//分析

    见前面一题Unique Binary Search Trees。


******************************************************************/

//代码


//递归法
//LeetCode, Unique Binary Seaerch Trees II


class Solution{
public:
    vector<TreeNode *> generate(int start, int end) {
        vector<TreeNode*> subTree;
        if(start > end) {
                subTree.push_back(nullptr);
                return subTree;
            
        }
        for(int k = start; k <= end; k++) {
            vector<TreeNode*> leftSubs = generate(start, k - 1);
            vector<TreeNode*> rightSubs = generate(k + 1, end);
            for(auto i : leftSubs) {
                for(auto j : rightSubs) {
                   TreeNode *node = new TreeNode(k);
                   node->left = i;
                   node->right = j;
                   subTree.push_back(node); 
                }
            }
        }
        return subTree;
    }
};





