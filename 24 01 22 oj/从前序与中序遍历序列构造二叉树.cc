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
    TreeNode* _buildTree(vector<int>& preorder,vector<int>& inorder,int& index,int begin,int end)
    {
        if(begin>end)return nullptr;
        TreeNode* root=new TreeNode(preorder[index]);
        int pos=hash[preorder[index]];
        index++;
        if(index<preorder.size())
        {
            root->left=_buildTree(preorder,inorder,index,begin,pos-1);
            root->right=_buildTree(preorder,inorder,index,pos+1,end);
        }  
        return root;     
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)hash[inorder[i]]=i;
        int index=0;
        int begin=0;
        int end=inorder.size()-1;
        return _buildTree(preorder,inorder,index,begin,end);
      
    }
};

