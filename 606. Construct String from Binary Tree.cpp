
/*
 *You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.
 *
 *The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.
 *
 *Example 1:
 *Input: Binary tree: [1,2,3,4]
 *       1
 *     /   \
 *    2     3
 *   /
 *  4
 *
 *Output: "1(2(4))(3)"
 *
 *Explanation: Originallay it needs to be "1(2(4)())(3()())",
 *but you need to omit all the unnecessary empty parenthesis pairs.
 *And it will be "1(2(4))(3)".
 *Example 2:
 *Input: Binary tree: [1,2,3,null,4]
 *       1
 *     /   \
 *    2     3
 *     \
 *      4
 *
 *Output: "1(2()(4))(3)"
 *
 *Explanation: Almost the same as the first example,
 *except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
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
    //一个节点没有括号
    //3个节点的话
    //打印顺序  (    左孩子   )   (    右孩子    )
    //递归对左孩子和右孩子的打印进行处理

    //如果左孩子为空和右孩子不为空 打印一对括号

    void handler(TreeNode *t, string& str)
    {
        if (!t)
            return ;

        str += "(" + to_string(t->val);
        if(!t->left && t->right)
            str += "()";
        handler(t->left, str);
        handler(t->right, str);
        str += ")";
    }

    string tree2str(TreeNode* t)
    {
        if (!t)                     // if t== NULL return ""
            return "";

        string str = "";
        str += to_string(t->val);

        if (!t->left && t->right)
            str += "()";
        else
            handler(t->left, str);

        handler(t->right, str);
        return str;
    }



    //更优秀的解法
    string tree2str(TreeNode* t)
    {
        if (t == NULL)
            return "";
        if (!t->left && !t->right)
            return to_string(t->val);

        string left = t->left == NULL ? "()" : "(" + tree2str(t->left) + ")";
        string right = t->right == NULL ? "" : "(" + tree2str(t->right) + ")";
        return to_string(t->val) + left + right;
    }
};
