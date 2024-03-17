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
        q.push(_root);
        //记录所有没有满的结点
        while(!q.empty())
        {
            TreeNode* tmproot=q.front();q.pop();
            if(tmproot->left==nullptr||tmproot->right==nullptr) qorder.push(tmproot);
            if(tmproot->left) q.push(tmproot->left);
            if(tmproot->right) q.push(tmproot->right);
        }
    }
    int insert(int v) {
        if(_root==nullptr)
        {
            _root=new TreeNode(v);
            qorder.push(_root);
        }
        TreeNode* tmpnode=qorder.front();
        if(tmpnode->left==nullptr)
        {
            tmpnode->left=new TreeNode(v);
            qorder.push(tmpnode->left);
        }
        else if(tmpnode->right==nullptr)
        {
            tmpnode->right=new TreeNode(v);
            qorder.pop();
            qorder.push(tmpnode->right);
        }
        return tmpnode->val;
    }
    
    TreeNode* get_root() {
        return _root;
    }
    queue<TreeNode*> q;
    queue<TreeNode*> qorder;
    TreeNode* _root;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */