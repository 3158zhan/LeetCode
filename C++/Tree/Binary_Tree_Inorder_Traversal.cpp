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

//Binary Tree Inorder Traversal
//描述

    Given a binary tree, return the inorder traversal of its nodes' values.
For example:
    Given binary tree {1, #, 2, 3},
     1
      \
       2
      /
     3

return [1,3,2].
        Note: Recursive solution is trivial, could you do it iteratively?

//分析

    用栈或者Morris遍历。

******************************************************************/

//代码
//栈
//LeetCode, Binary Tree Inorder Traversal
//使用栈，时间复杂度O(n)，空间复杂度O(n)

class Solution{
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<const TreeNoded *> s;
        const TreeNode *p = root;

        while (!s.empty() || p != nullptr) {
            if(p != nullptr) {
                s.push(p);
                p = p->left;
            }
            else{
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            }  
        }
        return result;
    }
};

//Morris中序遍历
//LeetCode, Binary Tree Inorder Traversal
//Morris中序遍历，时间复杂度O(n)，空间复杂度O(1)

class Solution{
public:
    vector<int> inorderTraversal(TreeNode *root) {
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
                    node->right = cur;
                    /* prev = cur; 不能有这句，cur还没有被访问 */
                    
                    cur = cur->left;

                } else { /* 已线索化，则访问节点，并删除线索 */
                    result.push_back(cur->val);
                    node->right = nullptr;
                    prev = cur;
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};