
class Solution {
public:
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder,int &index,int begin,int end)
    {
        if(begin>end)return nullptr;
        TreeNode* root=new TreeNode(postorder[index]);
        root->left=nullptr;
        root->right=nullptr;
        int pos=hash[postorder[index]];
        index--;
        //后续遍历的是 左 右 根，反向遍历postorder,构建完根应该先构建右子树，在构建左子树 
        root->right=_buildTree(inorder,postorder,index,pos+1,end);
        root->left=_buildTree(inorder,postorder,index,begin,pos-1);
        
        return root;
    }
    unordered_map<int,int> hash;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)hash[inorder[i]]=i;
        int index=postorder.size()-1;
        int begin=0;
        int end=inorder.size()-1;
        return _buildTree(inorder,postorder,index,begin,end);
    }
};