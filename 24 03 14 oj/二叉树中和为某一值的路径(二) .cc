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
     * @param target int整型 
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> ret;
    vector<int> path;
    int pathsum=0;
    void dfs(TreeNode* root,int target)
    {
        if(root==nullptr)return ;
        path.push_back(root->val);
        pathsum+=root->val;
        if(pathsum==target&&root->left==nullptr&&root->right==nullptr)
        {
            ret.push_back(path);
        }
		//如果left孩子是空那么代表没有path没有push也就不用pop
        dfs(root->left,target);
        if(root->left)
        {
            pathsum-=path.back();
            path.pop_back();
        }
        dfs(root->right,target);
        if(root->right)
        {
            pathsum-=path.back();
            path.pop_back();
        }

    }
    vector<vector<int>> FindPath(TreeNode* root, int target) {
            dfs(root,target);
            return ret;
       }
};
};