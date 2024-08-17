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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* prev=nullptr;
        TreeNode* ret=nullptr;
        stack<TreeNode*> st;
        TreeNode* node=root;
        while(node||!st.empty())
        {
            while(node)
            {
                st.push(node);
                node=node->left;
            }
            TreeNode* cur=st.top();
            if(prev==nullptr)
            {
                prev=cur;
                prev->left=nullptr;
                ret=prev;
            }
            else
            {
               prev->right=cur;
               prev->left=nullptr;
               prev=cur;
            }
            st.pop();
            node=cur->right;
        }
        TreeNode* tail=prev;
        tail->right=tail->left=nullptr;
        return ret;
    }
};