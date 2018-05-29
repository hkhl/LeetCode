/*
 *Given a binary tree, return the tilt of the whole tree.
 *
 *The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.
 *
 *The tilt of the whole tree is defined as the sum of all nodes' tilt.
 *
 *Example:
 *Input:
 *         1
 *       /   \
 *      2     3
 *Output: 1
 *Explanation:
 *Tilt of node 2 : 0
 *Tilt of node 3 : 0
 *Tilt of node 1 : |2-3| = 1
 *Tilt of binary tree : 0 + 0 + 1 = 1
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

    //求出树的倾斜度
    //倾斜度等于绝对值 左子树求和 与 右子树求和 的差
    //将所有的子树倾斜度求出求和返回
    /*
    void resSum(TreeNode *root, int &sum)
    {
        if (!root)
            return ;
        sum = sum + root->val;
        resSum(root->left, sum);
        resSum(root->right, sum);
    }*/

    int Sum(TreeNode *root)        //求子树的和
    {
        if (!root)
            return 0;
        //左子树的和 + 右子树的和
        return root->val + Sum(root->left) + Sum(root->right);
    }

    int findTilt(TreeNode* root)
    {
        if (!root)
            return 0;
        int leftsum = Sum(root->left);
        int rightsum = Sum(root->right);

        return abs(leftsum - rightsum) + findTilt(root->left) + findTilt(root->right);
    }

    /*或者计算的过程中把所有的倾斜度都计算出来

    public class Solution {
    int result = 0;

    public int findTilt(TreeNode root) {
        postOrder(root);
        return result;
    }

    private int postOrder(TreeNode root) {
        if (root == null) return 0;

        int left = postOrder(root.left);
        int right = postOrder(root.right);

        result += Math.abs(left - right);

        return left + right + root.val;
    }
}
    */
};



