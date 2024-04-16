/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return bool布尔型
     */
    bool ret=true;
    int heigh(TreeNode* root)
    {
        if(root==nullptr)return 0;
        int l=heigh(root->left);
        int r=heigh(root->right);
        if(abs(l-r)>1)ret=false;
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        heigh(root);
        return ret;
    }
};