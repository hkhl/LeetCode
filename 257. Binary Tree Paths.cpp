/*
 *Given a binary tree, return all root-to-leaf paths.
 *
 *Note: A leaf is a node with no children.
 *
 *Example:
 *
 *Input:
 *
 *   1
 * /   \
 *2     3
 * \
 *  5
 *
 *Output: ["1->2->5", "1->3"]
 *
 *Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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

    vector<string> vs;
    vector<string> binaryTreePaths(TreeNode* root)
    {
        if (!root)
            return vs;
        string str;
        handler(root, str);

        return vs;

    }
    void handler(TreeNode* root, string str)
    {
        if (!root)
            return;
        str += to_string(root->val);
        if (!root->left && !root->right)   //叶子节点
        {
            vs.push_back(str);
            return;
        }

        str += "->";
        handler(root->left, str);
        handler(root->right, str);
    }
};
