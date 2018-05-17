/*
 *Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 *
 *For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 *
 *Example:
 *
 *Given the sorted array: [-10,-3,0,5,9],
 *
 *One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
 *
 *      0
 *     / \
 *   -3   9
 *   /   /
 * -10  5
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
    //采用分治思想， 左部分都是左子树，右半部分都在右子树，当前根是中间节点， 递归下去。


    TreeNode* sortedArrayToBSTCore(vector<int>& nums)
    {
        //只有一个元素的数组直接返回
        if(nums.size() == 1)
        {
            TreeNode* node = new TreeNode(nums[0]);
            return node;
        }
        //数组为空 返回null
        if(nums.size() == 0)
            return nullptr;

        //取中值为root
        int mid = nums.size() / 2;
        TreeNode *root = new TreeNode(nums[mid]);

        //划分左数组 右数组
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid + 1, nums.end());

        //左递归， 右递归
        root->left = sortedArrayToBSTCore(left);
        root->right = sortedArrayToBSTCore(right);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return sortedArrayToBSTCore(nums);
    }


};
