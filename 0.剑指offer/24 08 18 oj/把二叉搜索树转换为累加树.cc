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
    TreeNode* convertBST(TreeNode* root) {
        TreeNode*node=root;
        stack<TreeNode*> st;
        int sum=0;
        while(node||!st.empty())
        {
            while(node)
            {
                st.push(node);
                node=node->right;
            }
            TreeNode* cur=st.top();st.pop();
            sum+=cur->val;
            cur->val=sum;
            node=cur->left;
        }
        return root;
    }
};