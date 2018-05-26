/*
 *Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 *
 *According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
 *
 *Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
 *
 *        _______6______
 *       /              \
 *    ___2__          ___8__
 *   /      \        /      \
 *   0      _4       7       9
 *         /  \
 *         3   5
 *Example 1:
 *
 *Input: root, p = 2, q = 8
 *Output: 6
 *Explanation: The LCA of nodes 2 and 8 is 6.
 *Example 2:
 *
 *Input: root, p = 2, q = 4
 *Output: 2
 *Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself
 *             according to the LCA definition.
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
    //找两个节点的共同父节点， 包含自身

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root || !p || !q)
            return NULL;
        if (p->val > q->val)
            return lca(root, q, p);
        else
            return lca(root, p, q);
    }
    TreeNode* lca(TreeNode *root, TreeNode *left, TreeNode *right)
    {
        if (!root)
            return root;
        if (root->val >= left->val && root->val <= right->val)
            return root;
        else if (root->val >= right->val)
            return lca(root->left, left, right);
        else if (root->val <= left->val)
            return lca(root->right, left, right);
    }
};
