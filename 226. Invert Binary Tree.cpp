/*
 *Invert a binary tree.
 *
 *Example:
 *
 *Input:
 *
 *     4
 *   /   \
 *  2     7
 * / \   / \
 *1   3 6   9
 *Output:
 *
 *     4
 *   /   \
 *  7     2
 * / \   / \
 *9   6 3   1
 *Trivia:
 *This problem was inspired by this original tweet by Max Howell:
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
    //根节点不动， 左右对称交换节点
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == NULL)
            return root;
        //解法1  从上到下解决问题
/*
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        root->left = invertTree(r);
        root->right = invertTree(l);
*/
        //解法2 从下到上解决问题
/*
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->left = right;
        root->right = left;
 */

        //解法3 交换解决问题
/*
        TreeNode *temp = NULL;
        temp = root->left;
        root->left = root->right;
        root->right = temp;

        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
*/
        return root;
    }
};
