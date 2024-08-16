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
    int sum=0;
    void dfs(TreeNode* root,int ret)
    {
        if(root==nullptr)return;
        if(root->left==nullptr&&root->right==nullptr)
        {  
            ret+=root->val;
            sum+=ret;
            return;
        }
        ret+=root->val;
        
        dfs(root->left,ret*10);
        dfs(root->right,ret*10);
       
    }
    int sumNumbers(TreeNode* root) {
        int ret=0;
        dfs(root,ret);
        return sum;
    }
};