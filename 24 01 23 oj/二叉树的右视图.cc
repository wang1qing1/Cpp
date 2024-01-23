/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ret;
    //利用根，右，左，遍历方法
    void  dfs(TreeNode* root,int i)
    {
        if(root==nullptr)return ;
        if(ret.size()<i)ret.push_back(root->val);
        dfs(root->right,i+1);
        dfs(root->left,i+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,1);
        return ret;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
//利用队列层序遍历
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ret;
        if(root==nullptr)return ret;
        q.push(root);
        while(!q.empty())
        {
            int tmp=q.size();
            for(int i=0;i<tmp;i++)
            {
                TreeNode* top=q.front();
                q.pop();
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
                if(i==tmp-1)ret.push_back(top->val);
            }
        }
        return ret;
    }
};