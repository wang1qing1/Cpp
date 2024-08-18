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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> hash;
        stack<TreeNode*> st;
        while(root||!st.empty())
        {
            while(root)
            {
                st.push(root);
                root=root->left;
            }
            TreeNode* cur=st.top();
            st.pop();
            hash.insert(cur->val);
            root=cur->right;
        } 
        for(auto e:hash)
        {
            if(hash.find(k-e)!=hash.end()&&k-e!=e)
            {
                // cout<<e<<endl;
                return true;
            }
        }
        return false;
    }
};