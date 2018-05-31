/*
 *Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
 *Example 1:
 *Input:
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 *Output: [3, 14.5, 11]
 *Explanation:
 *The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
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
    //求每一层的平均值
    //可将每一层节点保存起来。 再求平均值， 借助二维数组

    vector<vector<int>> v;

    void handler(TreeNode* root, int level)
    {
        if (!root)
            return ;

        while(v.size() <= level)
            v.push_back(vector<int>());
        v[level].push_back(root->val);

        handler(root->left, level+1);
        handler(root->right, level+1);

    }

    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double> vd;
        if (!root)
            return vd;

        handler(root, 0);
        double sum = 0;
        for(int i = 0; i < v.size(); i++)
        {
            sum = 0;
            for(int j = 0; j < v[i].size(); j++)
            {
                sum += v[i][j];
            }
            double res = sum / v[i].size();
            vd.push_back(res);
        }

        return vd;
    }
};



//其他解法, 层序遍历的时候计算出结果(for循环)

public List<Double> averageOfLevels(TreeNode root) {
    List<Double> result = new ArrayList<>();
    Queue<TreeNode> q = new LinkedList<>();

    if(root == null) return result;
    q.add(root);
    while(!q.isEmpty()) {
        int n = q.size();
        double sum = 0.0;
        for(int i = 0; i < n; i++) {
            TreeNode node = q.poll();
            sum += node.val;
            if(node.left != null) q.offer(node.left);
            if(node.right != null) q.offer(node.right);
        }
        result.add(sum / n);
    }
    return result;
