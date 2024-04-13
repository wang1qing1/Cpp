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
     * @return int整型vector
     */
    void dfs(TreeNode*root,vector<int>& ret)
    {
        if(root==nullptr)return;
        dfs(root->left,ret);
        dfs(root->right,ret);
        ret.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        dfs(root,ret);
        return ret;
    }
};