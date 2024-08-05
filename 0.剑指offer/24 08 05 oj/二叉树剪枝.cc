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
    bool dfs(TreeNode* root)
    {
        if(root==nullptr)return true;
        bool l=dfs(root->left);
        if(l)
        {
            if(root->left)delete root->left;
            root->left=nullptr;
        }
        bool r=dfs(root->right);
        if(r)
        {
            if(root->right)delete root->right;
            root->right=nullptr;
        }
        if(root->val==0&&l&&r)
        {
            return  true;
        }
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool ret=dfs(root);
        if(ret)
        {
            return nullptr;
        }
        return root;
    }
};