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
    
    int ret=0;
    int prev=0;
    void dfs(TreeNode* root,long long targetSum,long long sum)
    {
        if(root==nullptr)return ;
        sum+=root->val;
        if(sum==targetSum)ret++;
        dfs(root->left,targetSum,sum);
        dfs(root->right,targetSum,sum);
        sum-=root->val;
    }
    void _pathSum(TreeNode* root, int targetSum) 
    {
        if(root==nullptr)return ;
        dfs(root,targetSum,0);
        _pathSum(root->left,targetSum);
        _pathSum(root->right,targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        _pathSum(root,targetSum);
        return  ret;
    }

};