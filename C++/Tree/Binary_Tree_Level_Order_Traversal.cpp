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

//Binary Tree Lever Order Traversal
//描述

    Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3, 9, 20, #, #, 15, 7},

        3
       / \
      9  20
        /  \
       15   7

return its level order traversal as:

    [
      [3],
      [9,20],
      [15,7]
    ]

//分析

    无

******************************************************************/

//代码

//LeetCode, Binary Tree Level Order Traversal
//递归版，时间复杂度O(n)，空间复杂度O(n)

class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        traverse(root, 1, result);
        return result;
    }

    void tracerse(TreeNode *root, size_t, level, vector<vector<int>> &result) {
        if(!root) return;

        if(level > result.size())
            result.push_back(vecor<int>());

        result[level - 1].push_back(root->val);
        traverse(root->left, level+1, result);
        traverse(root->right, level+1,result);
    }
};

//迭代版
//LeetCode, Binary Tree Level Order Traversal
//迭代版，时间复杂度O(n)，空间复杂度O(1)

class Solution{
public:
    vector<vector<int>> levelOrder(treeNode *root) {
        vector<vector<int>> result;
        queue<TreeNode *> current, next;

        if(root == nullptr) {
            return result;
        }
        else{
            current.push(root);
        }

        while(!current.empty()){
            vector<int> level; //elments is one level
            while(!current.empty()) {
                TreeNode* node = current.front();
                current.pop();
                level.push_back(node->val);
                if(node->left != nullptr) next.push(node->left);
                if(node->right != nullptr) next.push(node->right);
        }
        result.push_back(level);
        swap(next, current);
    }     
    return result;

    }
};