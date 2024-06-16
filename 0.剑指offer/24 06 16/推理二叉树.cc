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
    unordered_map<int,int> hash;
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,int l,int r,int& i)
    {
        if(l>r)return nullptr;
        TreeNode* root=new TreeNode(preorder[i]);
        int index=hash[preorder[i]];
        i++;
        root->left=dfs(preorder,inorder,l,index-1,i);
        root->right=dfs(preorder,inorder,index+1,r,i);
        return root;
    }
    TreeNode* deduceTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)hash[inorder[i]]=i;
        int i=0;
        return dfs(preorder,inorder,0,inorder.size()-1,i);
    }
};