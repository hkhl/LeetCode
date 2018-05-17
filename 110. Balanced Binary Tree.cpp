/*
 *Given a binary tree, determine if it is height-balanced.
 *
 *For this problem, a height-balanced binary tree is defined as:
 *
 *a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 *
 *Example 1:
 *
 *Given the following tree [3,9,20,null,null,15,7]:
 *
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 *Return true.
 *
 *Example 2:
 *
 *Given the following tree [1,2,2,3,3,null,null,4,4]:
 *
 *       1
 *      / \
 *     2   2
 *    / \
 *   3   3
 *  / \
 * 4   4
 *Return false.
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


    //题意： 找出左子树和右子树的各自最大高度差不超过1 为高度平衡二叉树

    int maxlevel(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        //左子树加右子数
        return max(maxlevel(root->left), maxlevel(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root)
    {
        if(root == NULL)
            return true;

        int left = maxlevel(root->left);
        int right = maxlevel(root->right);

        /*
        if(abs(left - right) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
        */
        //等价
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        //a && b && c    不仅自己满足条件， 我的左子树和有子树都满足条件的情况下返回真。
    }
};
