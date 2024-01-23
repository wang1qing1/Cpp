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
    int _maxPathSum(TreeNode* root,int&ret)
    {
        if(root==nullptr)return 0;
        int l=_maxPathSum(root->left,ret);
        int r=_maxPathSum(root->right,ret);
        ret=max(max(ret,root->val+l+r),max(root->val,max(root->val+l,root->val+r)));
        return max(root->val,max(root->val+l,root->val+r));
    }
    int maxPathSum(TreeNode* root) {
        int ret=-0x3f3f3f3f;
       _maxPathSum(root,ret);
        return ret;
    }
};