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
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    int dfs(TreeNode* root,int o1,int o2)
    {
        if(root==nullptr)return 0;
        if(root->val==o1)return o1;
        if(root->val==o2)return o2;
        int l=dfs(root->left,o1,o2);
        int r=dfs(root->right,o1,o2);
        if(l&&r)return root->val;
        else if(l)return l;
        else if(r)return r;
        else return 0;
    }
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        return dfs(root,o1,o2);    }
};