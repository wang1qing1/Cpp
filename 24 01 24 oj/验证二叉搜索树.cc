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
    bool ret=true;
    long long prevnode=-0xffffffffff;
    void  dfs(TreeNode* root)
    {
        if(root==nullptr)return ;
        dfs(root->left);
        if(prevnode>=root->val)
        {
            ret=false;
        }
        prevnode=root->val;
        dfs(root->right);
    }
    bool isValidBST(TreeNode* root) {
        ret=true;
        dfs(root);
        return ret;
    }
};
