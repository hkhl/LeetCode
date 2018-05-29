/*
 *Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
 *
 *Example:
 *Given a binary tree
 *          1
 *         / \
 *        2   3
 *       / \
 *      4   5
 *Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
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
    //找二叉树最长的的路径

    //思路： 左孩子的最长路径加上右孩子的最长路径
    //如果最长路径包含根节点  那么长度就是   root->left + root->right
    //如果最长路径不包含根节点， 那么长度就是 两个子孩子的最长路径求最大值

    int depth(TreeNode* root)
    {
        if (!root)
            return 0;

        return 1 + max(depth(root->left), depth(root->right));
    }


    int diameterOfBinaryTree(TreeNode* root)
    {
        if (!root)
            return 0;
        int ret = depth(root->left) + depth(root->right);

        return max(ret, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }

    /*另一种解法
    public class Solution {
    int max = 0;

    public int diameterOfBinaryTree(TreeNode root) {
        maxDepth(root);
        return max;
    }

    private int maxDepth(TreeNode root) {
        if (root == null) return 0;

        int left = maxDepth(root.left);
        int right = maxDepth(root.right);

        max = Math.max(max, left + right);

        return Math.max(left, right) + 1;
    }
}
    */
};
