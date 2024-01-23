/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        if(root==nullptr)return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            long long sum=0;
            for(int i=0;i<size;i++)
            {
                TreeNode* top=q.front();
                q.pop();
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
                sum+=top->val;
            }
            ret.push_back(sum*1.0/size);
        }
        return ret;
    }
};