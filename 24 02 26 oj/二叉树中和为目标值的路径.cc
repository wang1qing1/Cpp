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
    vector<vector<int>> ret;
    vector<int> path;
    int sum=0; 
    void dfs(TreeNode* root,int target)
    {
        if(root==nullptr)return ;
        path.push_back(root->val);
        sum+=root->val;
        if(sum==target&&(root->left==nullptr&&root->right==nullptr))
        {
            ret.push_back(path);
        }
        dfs(root->left,target);
        if(root->left)
        {
            sum-=path.back();
            path.pop_back();
        }
        dfs(root->right,target);
        if(root->right)
        {
            sum-=path.back();
            path.pop_back();
        }
    }
    vector<vector<int>> pathTarget(TreeNode* root, int target) {
        dfs(root,target);
        return ret;
    }
};