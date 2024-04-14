/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
#include <iomanip>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @param targetSum int整型 
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> ret;
    vector<int> path;
    int sum=0;
    int tar;
    void dfs(TreeNode*root)
    {
        //结点加上
        if(root==nullptr)return;
        path.push_back(root->val);
        sum+=root->val;
        //判断是否是叶子节点，和目标值
        if(root->left==nullptr&&root->right==nullptr&&tar==sum)
        {
            ret.push_back(path);
        }
        dfs(root->left); 
        if(root->left)
        {
            sum-=path.back();
            path.pop_back();
        }     
        dfs(root->right);
        if(root->right)
        {
            sum-=path.back();
            path.pop_back();
        }    
    }
    vector<vector<int> > findPaths(TreeNode* root, int targetSum) {
       tar=targetSum;
       dfs(root);
       return ret;
    }
};