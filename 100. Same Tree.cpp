/*
 *
 *Given two binary trees, write a function to check if they are the same or not.
 *
 *Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
 *
 *Example 1:
 *
 *Input:     1         1
 *          / \       / \
 *         2   3     2   3
 *
 *        [1,2,3],   [1,2,3]
 *
 *Output: true
 *Example 2:
 *
 *Input:     1         1
 *          /           \
 *         2             2
 *
 *        [1,2],     [1,null,2]
 *
 *Output: false
 *Example 3:
 *
 *Input:     1         1
 *          / \       / \
 *         2   1     1   2
 *
 *        [1,2,1],   [1,1,2]
 *
 *Output: false
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
    //检查两颗树是否一样
    //遍历    equal

    void Print(TreeNode* t, string& str)
    {
        if(t == NULL)
        {
            str += "*";
            return ;
        }

        Print(t->left, str);
        Print(t->right, str);
        str += to_string(t->val);
    }

    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        string s1="", s2="";

        Print(p, s1);
        Print(q, s2);
        cout << s1 << endl;
        cout << s2 << endl;

        return s1 == s2;



        /*    正解如下：
         *    if (p == nullptr || q == nullptr) return q == p;
         *    return p->val == q->val and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
         *
         */
    }





};
