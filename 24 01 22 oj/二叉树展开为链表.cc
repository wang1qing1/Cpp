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
    TreeNode* Prev=nullptr;
    void _flatten(TreeNode* root)
    {
        if(root==nullptr)return ;
        TreeNode*r=root->right;
        TreeNode*l=root->left;
        if(Prev==nullptr)Prev=root;
        else
        {
            Prev->right=root;
            Prev->left=nullptr;
            Prev=root;
        }
        cout<<root->val<<" ";
        _flatten(l);
        _flatten(r);
    }
    void flatten(TreeNode* root) {
        _flatten(root);
    }
};