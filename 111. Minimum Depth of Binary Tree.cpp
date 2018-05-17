/*
 *Given a binary tree, find its minimum depth.
 *
 *The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 *
 *Note: A leaf is a node with no children.
 *
 *Example:
 *
 *Given binary tree [3,9,20,null,null,15,7],
 *
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 *return its minimum depth = 2.
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
    //计算某一条子树的最小深度.  如果只有左子树, 则最小深度就是左子树的最小深度
    int minDepth(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        if(root->left == NULL)
            return minDepth(root->right) + 1;
        else if(root->right == NULL)
            return minDepth(root->left) + 1;
        else
            return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
