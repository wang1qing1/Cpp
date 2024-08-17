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
    long long sum=0;
    int ret=0;
    void dfs(TreeNode* root,int targetSum)
    {
        if(root==nullptr)return ;
        sum+=root->val;
        if(sum==targetSum)
        {
            ret++;
        }
        dfs(root->left,targetSum);
        dfs(root->right,targetSum);
        sum-=root->val;

    }

    void order(TreeNode* root,int targetSum)
    {
        if(root==nullptr)return ;
        dfs(root,targetSum);
        order(root->left,targetSum);
        order(root->right,targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        order(root,targetSum);
        return ret;
    }
};