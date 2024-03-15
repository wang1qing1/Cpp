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
     * @return int整型
     */
    int dfs(TreeNode* root)
    {
        if(root==nullptr)return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        return max(l,r)+1;

    }
    int maxDepth(TreeNode* root) {
       return dfs(root);
    }
};