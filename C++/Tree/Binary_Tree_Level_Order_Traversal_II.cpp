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

//LeetCode, Binary Tree Level Order Traversal II
//描述

    Given a binary tree, return the bottom-up level order traversal of 
its nodes' values. (ie, from left to right, level by level from leaf to root).
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

    在上一题(binary-tree-Level-order-traversal）的基础上，reverse()一下即可。


******************************************************************/

//代码
//递归法
//LeetCode, Binary Tree Level Order  Traversal II
//时间复杂度O(n)，空间复杂度O(n)

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

//迭代版
//LeetCode, Binary Tree Level Order Traversal II
//迭代版，时间复杂度O(n)，空间复杂度O(1)

class Solution{
public:
    vector<vector<int>> levelOrder(treeNode *root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;

        queue<TreeNode *> current, next;
        vector<int> level;  //elments in level level

        current.push(root);
        while(!current.empty()) {
            while(!current.empty()){
                TreeNode* node = current.front();
                current.pop();
                level.push_back(node->val);
                if(node->left != nullptr) next.push(node->left);
                if(node->right != nullptr) next.push(node->right);
            }
            result.push_back(level);
            level.clear();
            swap(next, current);
        }
        reverse(result.begin(), result.end()); //比上题多这一行
        return result;
    }
};