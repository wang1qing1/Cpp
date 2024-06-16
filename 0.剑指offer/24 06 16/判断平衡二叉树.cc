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
    int ret=true;
    int dfs(TreeNode* root)
    {
        if(root==nullptr)return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        if(abs(l-r)>1)ret=false;
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ret;
    }
};