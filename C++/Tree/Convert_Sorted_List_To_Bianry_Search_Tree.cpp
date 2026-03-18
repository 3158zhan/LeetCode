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

//LeetCode, Convert Sorted List to Binary Search Tree
//描述

    Given a singly linked list where elements are sorted in ascending order, 
convert it to a height balanced BST.


//分析

    这题与上一题类似，但是单链表不能随机访问，而自顶向下的二分法必须
需要RandomAccessIterator，因此前面的方法不适用本题。
    存在一种自底向上(bottom-up)的方法

******************************************************************/

//代码

//分治法，自顶向下
//分治法，类似于Convert Sorted Array to Binary Search Tree,自顶向下，复杂度O(nlogn)。
//LeetCode, Convert Sorted List to Binary Search Tree
//分治法，自顶向下，时间复杂度O(n^2)，空间复杂度O(logn)

class Solution{
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, listLength (head));

    }

    TreeNode* sortedListToBST(ListNode* head, int len){
        if(len == 0) return nullptr;
        if(len == 1) return new TreeNode (head->val);    
        
        TreeNode* root = new TreeNode*(nth_node(head, len / 2 + 1)->val);
        root->left = sortedListToBST(head, len / 2);
        root->right = sortedListToBST(nth_node(head, len / 2 +2),
            (len - 1) / 2);

            return root;
    }
    int listLength(ListNode* node) {
        int n = 0;
        while(node) {
            ++n;
            node = node->next;

        }
        return n;

    }

    ListNode* nth_node (ListNode* node, int n) {
        while(--n)
        node = node->next;

        return node;
    }


};

//自底向上
//LeetCode, Convert Sorted List to Binary Search Tree
//bottom-up,时间复杂度O(n)，空间复杂度O(logn)

class Solution{
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int len = 0;
        ListNode *p = head;
        while(p){
            len++;
            p = p->next;
        }
        return sortedListToBST(head, 0, len - 1);
    }
    private:
        TreeNode* sortedListToBST(ListNode*& list, int start, int end) {
            if(start > end) return nullptr;

            int mid = start + (end - start)/2;
            TreeNode *leftChild = sortedListToBST(list, start, mid - 1);
            TreeNode *parent = new TreeNode(list->val);
            parent->left = leftChild;
            list = list->next;
            parent->right = sortedListToBST(list, mid + 1, end);
            return parent;
        }

};