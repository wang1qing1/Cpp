class Solution {
public:
	void inorder(TreeNode*root,TreeNode*&prev)
	{
		if(root==nullptr)
		{
			return ;
		}
		inorder(root->left, prev);
		root->left=prev;
		if(prev!=nullptr)
		{
			prev->right=root;
		}
		prev=root;
		inorder(root->right,prev);
		
	}

    TreeNode* Convert(TreeNode* pRootOfTree) {
		if(pRootOfTree==nullptr)
		{
			return nullptr;
		}
		TreeNode* prev=nullptr;
		inorder(pRootOfTree, prev);
		TreeNode*cur=pRootOfTree;
		while(cur->left)
		{
			cur=cur->left;
		}
		return cur;
    }
};
