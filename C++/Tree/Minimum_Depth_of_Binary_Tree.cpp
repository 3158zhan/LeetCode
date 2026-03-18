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

//LeetCode, Minimum Depth of Binary  Tree
//描述

    Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down 
to the nearest leaf node.

//分析

    

******************************************************************/

//代码


//LeetCode, Minimum Depth of Binary  Tree
//递归法，时间复杂度O(n)，空间复杂度O(logn)

class Solution{
public:
    int minDepth(const TreeNode *root) {
        return minDepth(root, false);

    }
    private:
    static int minDepth(const TreeNode *root, bool hasbrother){
        if(!root)return hasbrother ? INT_MAX : 0;

        return 1 + min(minDepth(root->left, root->right != NULL),
            minDepth(root->right, root->left != NULL));
    }


};

//LeetCode, Minimum Depth of Binary  Tree
//迭代法，时间复杂度O(n)，空间复杂度O(logn)

class Solution{
public:
    int minDepth( TreeNode *root) {
       if(root == nullptr)
       return 0;

       int result = INT_MAX;

       stack<pair<TreeNode*, int>> s;
       s.push(make_pair(root, 1));

       while(!s.empty()){
        auto node = s.top().first;
        auto depth = s.top().second;
        s.pop();

        if(node->left == nullptr && node->right == nullptr)
            result = min(result, depth);

        if(node->left && result > depth) //深度控制，剪枝
            s.push(make_pair(node->left, depth + 1));

        if(node->right && result > depth) //深度控制，剪枝
            s.push(make_pair(node->right, depth + 1));

       }
       return result;
    }


};

