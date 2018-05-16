/*
 *Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 *For example:
 *Given binary tree [3,9,20,null,null,15,7],
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 *return its bottom-up level order traversal as:
 *[
 *  [15,7],
 *  [9,20],
 *  [3]
 *]
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
    //dfs || bfs?
private:
    vector<vector<int> > v;
    void dfs(TreeNode* root, int height)
    {
        if (root == NULL)
            return ;

        while (v.size() <= height)
            v.push_back(vector<int>());
        v[height].push_back(root->val);

        dfs(root->left, height+1);
        dfs(root->right, height+1);
    }
public:


    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        dfs(root, 0);
        reverse(v.begin(), v.end());
        return v;
    }
};



