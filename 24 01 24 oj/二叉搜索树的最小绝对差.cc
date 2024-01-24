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
    vector<int> v;
    void _getMininum(TreeNode* root)
    {
        if(root==nullptr)return ;
        _getMininum(root->left);
        v.push_back(root->val);
        _getMininum(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        int ret=0x3f3f3f3f;

        _getMininum(root);
        for(int i=0;i<v.size()-1;i++)ret=min(ret,abs(v[i]-v[i+1]));
        return ret;
    }
};