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

//LeetCode, Populating Next Right Pointers in Each Node II 
//描述

    Follow up for problem "Populating Next Right Pointers in Each Node".
    What if the given tree could be any binary tree? Would your previous solution still work?

    Note: You may only use constant extra space.

    For example,
    Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7


After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

//分析

    要处理一个节点，可能需要最右边的兄弟节点，首先想到用广搜。但广搜不是常数空间的，本题要求常数空间。
    注意，这题的代码原封不动，也可以解决 Populating Next Right Pointers in Each Node I.


******************************************************************/

//代码


//LeetCode, Populating Next Right Pointers in Each Node II
//递归版，时间复杂度O(n)，空间复杂度O(1)

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) return;

        TreeLinkNode dummy(-1);
        for (TreeLinkNode *curr = root, *prev = &dummy; 
                curr; curr = curr->next) {
            if (curr->left != nullptr){
                prev->next = curr->left;
                prev = prev->next;
            }
            if (curr->right != nullptr){
                prev->next = curr->right;
                prev = prev->next;
            }
        }
        connect(dummy.next);
    }
};

//LeetCode, Populating Next Right Pointers in Each Node II
//迭代版，时间复杂度O(n)，空间复杂度O(1)

class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode * next = nullptr; // the first node of next level
            TreeLinkNode * prev = nullptr; // previous node on the same level
            for (; root; root = root->next) {
                if (!next) next = root->left ? root->left : root->right;

                if (root->left) {
                    if (prev) prev->next = root->left;
                    prev = root->left;
                }
                if (root->right) {
                    if (prev) prev->next = root->right;
                    prev = root->right;
                }
            }
            root = next; // turn to next level
        }
    }
};
