/*
 *Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
 *
 *Example 1:
 *Given tree s:
 *
 *     3
 *    / \
 *   4   5
 *  / \
 * 1   2
 *Given tree t:
 *   4
 *  / \
 * 1   2
 *Return true, because t has the same structure and node values with a subtree of s.
 *Example 2:
 *Given tree s:
 *
 *     3
 *    / \
 *   4   5
 *  / \
 * 1   2
 *    /
 *   0
 *Given tree t:
 *   4
 *  / \
 * 1   2
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
    //判断t是否是s的子树，子树定义： 必要包含t的一个节点和这个节点的所有后代。  s也可以认为是自己的子树
    //
    //判断s根节点是否是等于t，不是的话 判断根节点的左子树和右子树 看是否存在相等子树

    TreeNode *c = NULL;
    void findChildNode(TreeNode *s, TreeNode *t)
    {
        if (!s)
            return;
        if (s->val == t->val)
            c = s;

        findChildNode(s->left, t);
        findChildNode(s->right, t);
    }

    bool IsSame(TreeNode *c, TreeNode *t)
    {
        if (!c && !t)
            return true;
        if (!c || !t)
            return false;
        return c->val == t->val && IsSame(c->left, t->left) && IsSame(c->right, t->right);
    }

    bool isSubtree(TreeNode* s, TreeNode* t)
    {
        return IsSame(s,t) || s->left && isSubtree(s->left, t) || s->right && isSubtree(s->right, t);

    }
};
