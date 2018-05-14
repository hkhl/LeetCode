
/*
 *Given a binary tree, find its maximum depth.
 *
 *The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
 *return its depth = 3.
 *
 */


（1）如果一颗树只有一个节点，它的深度是1；
（2）如果根节点只有左子树而没有右子树，那么二叉树的深度应该是其左子树的深度加1；
（3）如果根节点只有右子树而没有左子树，那么二叉树的深度应该是其右树的深度加1；
（4）如果根节点既有左子树又有右子树，那么二叉树的深度应该是其左右子树的深度较大值加1；
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
    int maxDepth(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
