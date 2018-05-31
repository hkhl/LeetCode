/*
 *Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
 *
 *Example 1:
 *Input:
 *    5
 *   / \
 *  3   6
 * / \   \
 *2   4   7
 *
 *Target = 9
 *
 *Output: True
 *Example 2:
 *Input:
 *    5
 *   / \
 *  3   6
 * / \   \
 *2   4   7
 *
 *Target = 28
 *
 *Output: False
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //中序遍历有序数组， 判断是否存在和等于目标值的两个元素

    //set.count(value)返回set对象内元素值为value的元素个数

    bool handler(TreeNode *root, unordered_set<int>& s, int k)
    {
        if (!root)
            return false;
        if (s.count(k-root->val))
            return true;

        s.insert(root->val);
        return handler(root->left, s, k) || handler(root->right, s, k);
    }

    bool findTarget(TreeNode* root, int k)
    {
        unordered_set<int> s;

        return handler(root, s, k);
    }
};
