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

//Binary Tree Postorder Traversal
//描述

    Given a binary tree, return the postorder traversal of its nodes' values.
    Given binary tree {1, #, 2, 3},
     1
      \
       2
      /
     3

return [3,2,1].
        Note: Recursive solution is trivial, could you do it iteratively?

//分析

    用栈或者Morris遍历。

******************************************************************/

//代码
//栈
//LeetCode, Binary Tree Postorder Traversal
//使用栈，时间复杂度O(n)，空间复杂度O(n)

class Solution{
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<const TreeNode *> s;
        /* p，正在访问的结点，q，刚刚访问过的结点*/
        const TreeNode *p = root, *q = nullptr;

        do {
            while (p != nullptr) { /* 往左下走*/
                s.push(p);
                p = p->left;
            }
            q = nullptr;
            while (!s.empty()) {
                p = s.top();
                s.pop();
                /* 右孩子不存在或已被访问，访问之*/
                if (p->right == q) {
                    result.push_back(p->val);
                    q = p; /* 保存刚访问过的结点*/
                } else {
                    /* 当前结点不能访问，需第二次进栈*/
                    s.push(p);
                    /* 先处理右子树*/
                    p = p->right;
                    break;
                }
            }
        } while (!s.empty());

        return result;
    }
};

