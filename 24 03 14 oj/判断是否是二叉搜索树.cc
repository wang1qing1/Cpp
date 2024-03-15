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
    int prev=INT_MIN;
    void dfs(TreeNode* root)
    {
        if(root==nullptr)return ;
        dfs(root->left);
        if(root->val<=prev)
        {
            ret=false;
            return;
        }
        prev=root->val;
        dfs(root->right);
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        return ret;
    }
};

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
    int prev=INT_MIN;
    bool dfs(TreeNode* root)
    {
        if(root==nullptr)return true;
        if(!dfs(root->left))return false;
        if(root->val<=prev)return false;
        prev=root->val;
        if(!dfs(root->right))return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
       return dfs(root);
    }
};