/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> st;
        TreeNode* node=root;
        TreeNode* prev=nullptr;
        while(node||!st.empty())
        {
            while(node)
            {
                st.push(node);
                node=node->left;
            }
            TreeNode* cur=st.top();st.pop();
            if(prev==p)
            {
                return cur;
            }
            prev=cur;
            node=cur->right;
        }
        return nullptr;
    }
};