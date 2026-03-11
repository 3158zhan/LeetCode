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

//LeetCode, Symmetric Tree 
//描述

    Given two binary trees, write a function to check if they are equal or not.
    Two binary trees are considered equal if they are structurally identical and the nodes have 
the same value.



//分析

    无


******************************************************************/

//代码


//递归法
//LeetCode, Symmetric Tree
//递归版，时间复杂度O(n)，空间复杂度O(logn)

class Solution{
public:
    bool isSymmetric(TreeNode *root){
        if(root == nullptr) return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode *p,TreeNode *q){
        if(p == nullptr && q == nullptr) return true;//终止条件
        if(p == nuppltr || q == nullptr) return false; //终止条件
            return p->val == q->val  //三方合并
                    && isSymmetric(p->left, q->right)
                    && isSymmetric(p->right, q->left);
    }
};





//LeetCode，Symmetric Tree
//迭代版，时间复杂度O(n),空间复杂度O(logn)

class Solution {
public:
    bool Symmetric(TreeNode * root){
        if(!root) return true;

        stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);

        while(!s.empty()) {
            auto p = s.top(); s.pop();
            auto q = s.top(); s.pop();

            if(!p && !q) continue;
            if(!p || !q) return false;
            if(p->val != q->val) return false;

            s.push(p->left);
            s.push(q->right);

            s.push(p->right);
            s.push(q->left);
        }

        return true;
    } 
};

