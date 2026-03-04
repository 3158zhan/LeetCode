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

    树的遍历有两类：深度优先遍历和宽度优先遍历。深度优先遍历又可分为两种：
先根（次序）遍历和后根（次序）遍历。
    树的先根遍历是：先访问树的根结点，然后依次先根遍历根的各棵子树。树的先根
遍历的结果与对应二叉树（孩子兄弟表示法）的先序遍历的结果相同。
    树的后根遍历是：先依次后根遍历树根的各棵子树，然后访问根结点。树的后跟遍历
的结果与对应二叉树的中序遍历的结果相同。
    二叉树的先根遍历有：先序遍历 (root->left->right)，root->right->left；
后根遍历有：后序遍历 (left->right->root)，right->left->root；
    二叉树还有个一般的树没有的遍历次序，中序遍历 (left->root->right)。

//Binary Tree Preorder Traversal
//描述

    Given a binary tree, return the preorder traversal of its nodes' values.
For example:
    Given binary tree {1, #, 2,3 },
     1
      \
       2
      /
     3

return [1,2,3].
        Note: Recursive solution is trivial, could you do it iteratively?

//分析

    用栈或者Morris遍历。

******************************************************************/

//代码
//栈
//LeetCode, Binary Tree Preorder Traversal
//使用栈，时间复杂度O(n)，空间复杂度O(n)

class Solution{
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<const TreeNoded *> s;
        if(root != nullptr) s.push(root);

        while(!s.empty()) {
            const TreeNode *p = s.top();
            s.pop();
            result.push_back(p->val);

            if(p->right != nullptr) s.push(p->right);
            if(p->left != nullptr) s.push(p->left);
        }
        return result;
    }
};

//Morris先序遍历
//LeetCode, Binary Tree Preorder Traversal
//Morris先序遍历，时间复杂度O(n)，空间复杂度O(1)

class Solution{
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *cur = root, *prev = nullptr;

        while (cur != nullptr){
            if(cur->left == nullptr) {
                result.push_back(cur->val);
                prev = cur; /* cur刚刚被访问过 */
                 cur = cur->right;
            }
            else {
                /* 查找前驱 */
                TreeNode *node = cur->left;
                while(node->right != nullptr && node->right != cur)
                    node = node->right;

                if(node->right == nullptr) { /* 还没线索化，则建立线索 */
                    result.push_back(cur->val);/* 仅这一行的位置与中序不同 */
                    node->right = cur;
                    prev = cur; /* cur刚刚被访问过 */
                    cur = cur->left;

                } else { /* 已线索化，则删除线索 */
                    node->right = nullptr;
                    /* prev = cur; 不能有这句，cur已经被访问 */
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};