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
    bool _isSymmetric(TreeNode* Lroot,TreeNode*Rroot)
    {
        if(Lroot==nullptr&&Rroot==nullptr)return true;
        if(Lroot==nullptr||Rroot==nullptr)return false;
        return Lroot->val==Rroot->val&&_isSymmetric(Lroot->left,Rroot->right)&&_isSymmetric(Lroot->right,Rroot->left);
    }
    bool isSymmetric(TreeNode* root) {
        return _isSymmetric(root->left,root->right);
    }
};