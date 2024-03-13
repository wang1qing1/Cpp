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
 //双栈法
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==nullptr)return ret;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root);
        while(!st1.empty()||!st2.empty())
        {
            vector<int> path;
            if(!st1.empty())
            {
                int count=st1.size();
                for(int i=0;i<count;i++)
                {
                    TreeNode* tmp=st1.top();
                    st1.pop();
                    path.push_back(tmp->val);
                    if(tmp->left)st2.push(tmp->left);
                    if(tmp->right)st2.push(tmp->right);
                }
            }
            if(!path.empty())ret.push_back(path);
            path.clear();
            if(!st2.empty())
            {
                int count=st2.size();
                for(int i=0;i<count;i++)
                {
                    TreeNode* tmp=st2.top();
                    st2.pop();
                    path.push_back(tmp->val);
                    if(tmp->right)st1.push(tmp->right);
                    if(tmp->left)st1.push(tmp->left);
                }
            }
            if(!path.empty())ret.push_back(path);
            path.clear();
        }
        return ret;
    }
};