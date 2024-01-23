//利用完全二叉树特性
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr)return 0;
        int left=0;
        TreeNode*pleft=root->left;
        int right=0;
        TreeNode*pright=root->right;
        while(pleft||pright)
        {
            if(pleft)
            {
                left++;
                pleft=pleft->left;
            }
            if(pright)
            {
                right++;
                pright=pright->left;
            }
        }
        if(left==right)return (1<<left)+countNodes(root->right);
        return (1<<right)+countNodes(root->left);
    }
};

//递归遍历树
class Solution {
public:
    int _countNodes(TreeNode* root)
    {
        if(root==nullptr) return 0;
        return 1+_countNodes(root->left)+_countNodes(root->right);
    }
    int countNodes(TreeNode* root) {
         return _countNodes(root);
    }
};