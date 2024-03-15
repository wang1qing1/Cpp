
//由中序和前序构建二叉树
#include <vector>
class Solution {
public:
    unordered_map<int,int> hash;
    TreeNode* dfs(vector<int>& pre,vector<int>& mid,int begin,int end,int& prepos)
    {
        if(begin>end)return nullptr;
        int num=pre[prepos];
        int numpos=hash[num];
        TreeNode* root=new TreeNode(num);
        prepos++;
        root->left=dfs(pre,mid,begin,numpos-1,prepos);
        root->right=dfs(pre,mid,numpos+1,end,prepos);
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int>& preOrder, vector<int>& vinOrder) {
            for(int i=0;i<vinOrder.size();i++)hash[vinOrder[i]]=i;
            int pos=0;
            return dfs(preOrder,vinOrder,0,preOrder.size()-1,pos);
    }
};


 */
//后续和中序构建二叉树
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
    TreeNode* dfs(vector<int>& mid, vector<int>& post,int begin,int end,int& pos)
    {
        if(begin>end)return nullptr;
        int num=post[pos];
        int numpos=hash[num];
        TreeNode* root=new TreeNode(num);
        pos--;
        //注意此处,倒着遍历二叉树后续的时候，依次访问的根，右子树，左子树
        //所以先构建右子树再构建左子树
        root->right=dfs(mid,post,numpos+1,end,pos);
        root->left=dfs(mid,post,begin,numpos-1,pos);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++) hash[inorder[i]]=i;
        int pos=inorder.size()-1;
        return dfs(inorder,postorder,0,inorder.size()-1,pos);
    }
};