/*
 *Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.
 *
 *Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
 *
 *If no such second minimum value exists, output -1 instead.
 *
 *Example 1:
 *Input:
 *    2
 *   / \
 *  2   5
 *     / \
 *    5   7
 *
 *Output: 5
 *Explanation: The smallest value is 2, the second smallest value is 5.
 *Example 2:
 *Input:
 *    2
 *   / \
 *  2   2
 *
 *Output: -1
 *Explanation: The smallest value is 2, but there isn't any second smallest value.
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
    //第一种方法
    //根节点是孩子节点的最小的值， 输出第二最小值
    //因为是二叉搜索树， 根节点一定是左子树的左叶子（如果存在）
    //所以可以通过找到所有叶子节点中 大于根节点的最小的叶子节点
    /*
    int sec = INT_MAX;
    int minVal;
    void handler(TreeNode *root)
    {
        if (!root)
            return ;
        if (!root->left || !root->right)
        {
            if (root->val > minVal)
                sec = min(root->val, sec);
        }
        handler(root->left);
        handler(root->right);
    }

    int findSecondMinimumValue(TreeNode* root)
    {
        if (!root)
            return -1;
        minVal = root->val;
        handler(root);
        return sec == INT_MAX ? -1 : sec;
    }
    */

    //第二种方法  左子树返回-1  右子树返回当前节点找最小的值
    int helper(TreeNode *root, int val)
    {
        if (root == NULL)     //左子树都返回了-1
            return -1;
        if (root->val > val)  //右子树都返回了当前节点
            return root->val;

        int left = helper(root->left, val);
        int right = helper(root->right, val);

        if (left == -1 || right == -1)   //左子树返回 或者右子树为空
            return left == -1 ? right : left;
        else
            return min(left, right);
    }

    int findSecondMinimumValue(TreeNode* root)
    {
        if (!root)
            return -1;
        return helper(root, root->val);
    }

};
