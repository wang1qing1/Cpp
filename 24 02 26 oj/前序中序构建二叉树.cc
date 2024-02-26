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
    TreeNode* dfs(vector<int>& preorder, vector<int>& postorder,int begin,int end,int& pos)
    {
        if(begin>end)
        {
            return nullptr;
        }
        TreeNode* root=new TreeNode(preorder[pos]);
        cout<<preorder[pos]<<" ";
        int index=hash[preorder[pos]];
        pos++;
        if(pos>=0)
        {
            root->left=dfs(preorder,postorder,begin,index-1,pos);
            root->right=dfs(preorder,postorder,index+1,end,pos);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)hash[inorder[i]]=i;
        int index=0;
        int begin=0;
        int end=inorder.size()-1;
        return dfs(preorder,inorder,begin,end,index);
      
    }
};

