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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        _root=root;
    }
    
    int insert(int v) {
        queue<TreeNode*> q;
        q.push(_root);
        int father;
        while(!q.empty())
        {
            TreeNode* tmproot=q.front();q.pop();
            if(tmproot->left)q.push(tmproot->left);
            else
            {
                tmproot->left=new TreeNode(v);
                return tmproot->val;
            }
            if(tmproot->right)q.push(tmproot->right);
            else{
                tmproot->right=new TreeNode(v);
                return tmproot->val;
            }
        }
        return 0;
    }
    
    TreeNode* get_root() {
        return _root;
    }
    TreeNode* _root;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */