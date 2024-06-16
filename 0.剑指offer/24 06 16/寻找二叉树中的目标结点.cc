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
    struct com{
        bool operator()(int a,int b)
        {
            return a>b;
        }  
    };
    priority_queue<int,vector<int>,com> q;
    void dfs(TreeNode* root,int cnt)
    {
        if(root==nullptr)return ;
        if(q.size()==cnt)
        {
            if(root->val>q.top())
            {
                q.pop();
                q.push(root->val);
            }
        }
        else q.push(root->val);
        dfs(root->left,cnt);
        dfs(root->right,cnt);
    }
    int findTargetNode(TreeNode* root, int cnt) {
        dfs(root,cnt);
        return q.top();
    }
};