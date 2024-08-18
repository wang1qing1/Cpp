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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode* cur=st.top();st.pop();
        int ret=cur->val;
        cur=cur->right;
        while(cur)
        {
            st.push(cur);
            cur=cur->left;
        }
        return ret;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    stack<TreeNode*> st;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */