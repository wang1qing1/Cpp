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
        queue<TreeNode*> q;
        if(root) q.push(root);
        int j=1;
        while(!q.empty())
        {
            int size=q.size();
            vector<int> vtmp;
            for(int i=0;i<size;i++)
            {
                TreeNode* top=q.front();
                vtmp.push_back(top->val);
                q.pop();
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
            if(j%2==0)reverse(vtmp.begin(),vtmp.end());
            ret.push_back(vtmp);
            j++;
        }
        return ret;
    }
};