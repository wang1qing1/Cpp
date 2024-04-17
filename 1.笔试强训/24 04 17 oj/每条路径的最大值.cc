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
    vector<int> ret;
    void dfs(TreeNode* root,int curmax)
    {
        if(root==nullptr)return ;
        curmax=max(curmax,root->val);
        if(root->left==nullptr&&root->right==nullptr)
        {
            ret.push_back(curmax);
        }
        if(root->left)
        {
            dfs(root->left,curmax);
        }
        if(root->right)
        {
            dfs(root->right,curmax);
        }
    }
    vector<int> findMaxValues(TreeNode* root) {
        dfs(root,-0x3f3f3f3f);
        return ret;
    }
};