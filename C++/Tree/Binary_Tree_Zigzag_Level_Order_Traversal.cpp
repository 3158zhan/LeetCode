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

//LeetCode, Binary Tree Zigzag  Level Order Traversal 
//描述

    Given a binary tree, return the bottom-up level order traversal of 
its nodes' values. (ie, from left to right, level by level from leaf to root).
    For example: Given binary tree {3, 9, 20, #, #, 15, 7}
        3
       / \
      9  20
        /  \
       15   7

return its zigzag level order traversal as:
    [
      [3],
      [20,9],
      [15,7]
    ]

//分析

    广度优先遍历，用一个bool记录是从左到右还是从右到左，每一层结束就翻转一下。


******************************************************************/

//代码
//递归法
//LeetCode, Binary Tree Zigzag  Level Order Traversal
//时间复杂度O(n)，空间复杂度O(n)

class Solution{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root){
        vector<vector<int>> result;
        traverse(root, 1, result, true);
        return result;
    }

    void traverse(TreeNode *root,size_t level, vector<vector<int>> &result,
    bool left_to_right){
        if(!root) return;

        if(level > result.size())
            result.push_back(vector<int>());

        if(left_to_right)
            result[level-1],push_back(root->val);
        else
            result[level-1].insert(result[level-1].begin(), root->val);

        traverse(root->left, level+1, result, !left_to_right);
        tracerse(root->right, level+1, result, !left_to_right);
    }
};

//迭代版
//LeetCode, Binary Tree Zigzag  Level Order Traversal
//广度优先遍历，用一个bool记录是从左到右还是从右到左，每一层结束就翻转一下。
//迭代版，时间复杂度O(n)，空间复杂度O(n)

class Solution{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root){
        vector<vector<int>> result;
        queue<TreeNode*> current, next;
        bool left_to_right = ture;

        if(root == nullptr){
            return result;
        }    else{
            current.push(root);
        }
        while(!current.empty()){
            vector<int> level; //elments in one level
            while(!current.empty()){
                TreeNode* node = current.front();
                current.pop();
                level.push_back(node->val);
                if(node->left != nullptr) next.push(node->left);
                if(node->right != nullptr) next.push(node->right);
            
            }
            if(!letf_to_right) reverse(level.begin(), level.end());
            result.push_back(level);
            left_to_right = !left_to_right;
            swap(next, current);
        }
        return result;
        
    }
};