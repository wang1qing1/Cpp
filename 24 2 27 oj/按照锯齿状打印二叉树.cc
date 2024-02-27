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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==nullptr)return ret;
        queue<TreeNode*> q;
        q.push(root);
        int i=1;
        while(!q.empty())
        {
            int count=q.size();
            vector<int> tmp;
            while(count--)
            {
                TreeNode* cur=q.front();
                q.pop();
                tmp.push_back(cur->val);
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            if(i%2==0)reverse(tmp.begin(),tmp.end());
            i++;
            ret.push_back(tmp);
        }
        return ret;

    }
};