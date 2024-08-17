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
    int maxsum=-0x3f3f3f3f;

    int order(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int l=order(root->left);
        int r=order(root->right);
        maxsum=max(max(max(l+root->val,r+root->val),max(l+r+root->val,root->val)),maxsum);
        return max(max(l,r)+root->val,root->val);
    }
    int maxPathSum(TreeNode* root) {
         order(root);
        return maxsum;
    }
};