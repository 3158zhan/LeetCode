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

//LeetCode, Convert Sorted Array to Binary Search Tree
//描述

    Given an array where elements are sorted in ascending order, 
convert it to a height balanced BST.

//分析

    二分法

******************************************************************/

//代码


//LeetCode, Convert Sorted Array to Binary Search Tree
//分治法，时间复杂度O(n)，空间复杂度O(logn)

class Solution{
public:
    TreeNode* SortedArrayToBST(vector<int>& num) {
        return SortedArrayToBST(num.begin(), num.end());
    }

    template<typename RandomAccessIterator>
    TreeNode* SortedArrayToBST(RandomAccessIterator first,
        RandomAccessIterator last) {
            const auto length = distance(first, last);

            if(length <= 0) return nullptr; //终止条件

            //三方合并

            auto mid = first + length / 2;
            TreeNode* root = new TreeNode (*mid);
            root->left = SortedArrayToBST(first, mid);
            root->right = SortedArrayToBST(mid + 1, last);

            return root;
        }


};

