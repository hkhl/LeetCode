/*
 *Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
 *
 *Note: The length of path between two nodes is represented by the number of edges between them.
 *
 *Example 1:
 *
 *Input:
 *
 *              5
 *             / \
 *            4   5
 *           / \   \
 *          1   1   5
 *Output:
 *
 *2
 *Example 2:
 *
 *Input:
 *
 *              1
 *             / \
 *            4   5
 *           / \   \
 *          4   4   5
 *Output:
 *
 *2
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
    //效率较低的一个版本 On2
    /*
    int handler(TreeNode* root, int val)
    {
        if (!root || root->val != val)
            return 0;
        return 1 + max(handler(root->left, val), handler(root->right, val));
    }
    int longestUnivaluePath(TreeNode* root)
    {
        if (!root)
            return 0;
        //return max(max(longestUnivaluePath(root->left), longestUnivaluePath(root->right)), handler(root->left, root->val)+handler(root->right, root->val));
        int ans = max(longestUnivaluePath(root->left), longestUnivaluePath(root->right));
        return max(ans, handler(root->left, root->val)+handler(root->right, root->val));

    }*/


    //另一个版本

    int dfs(TreeNode* root, int& lup)
    {
        int l = root->left ? dfs(root->left, lup) : 0;
        int r = root->right ? dfs(root->right, lup) : 0;
        int resl = root->left && root->val == root->left->val ? l+1 : 0;
        int resr = root->right && root->val == root->right->val ? r+1 : 0;

        lup = max(lup, resl+resr);
        return max(resl, resr);
    }

    int longestUnivaluePath(TreeNode* root)
    {
        int lup = 0;
        if (root)
            dfs(root, lup);
        return lup;
    }

};
