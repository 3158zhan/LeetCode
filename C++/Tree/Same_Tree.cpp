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

//LeetCode, Same Tree 
//描述

    Given two binary trees, write a function to check if they are equal or not.
    Two binary trees are considered equal if they are structurally identical and 
the nodes have the same value.


//分析

    无


******************************************************************/

//代码


//递归法
//LeetCode, Same Tree
//递归版，时间复杂度O(n)，空间复杂度O(logn)

class Solution{
public:
    bool isSameTree(TreeNode *p, TreeNode *q){
        if(!p && !q) return true;  //终止条件
        if(!p || !q) return false; //剪枝
        return p->val == q->val    //三方合并
            && isSameTree(p->left, q->left)
            && isSameTree(p-right, q.right);
    }
};



//LeetCode，Same Tree
//迭代版，时间复杂度O(n),空间复杂度O(logn)

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        stack<TreeNode*> s;
        s.push(p);
        s.push(q);

        while(!s.empty()) {
            p = s.top(); s.pop();
            q = s.top(); s.pop();

            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;

            s.push(p->left);
            s.push(q->left);

            s.push(p->right);
            s.push(q->right);
        }
        return true;
    }
};