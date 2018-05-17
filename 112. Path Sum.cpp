/*
 *Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 *
 *Note: A leaf is a node with no children.
 *
 *Example:
 *
 *Given the below binary tree and sum = 22,
 *
 *      5
 *     / \
 *    4   8
 *   /   / \
 *  11  13  4
 * /  \      \
 *7    2      1
 *return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    //求是否存在某一条路径的和等于sum
    bool hasPathSum(TreeNode* root, int sum)
    {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL && root->val == sum)  //左右都无子树了（叶子节点特性） 且val等与sum
            return true;

        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);  //左子树或者右子树中存在一条路路径
    }
};
