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
    bool findNode(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root==nullptr)return false;
        if(root==p||root==q)return true;
        bool l=findNode(root->left,p,q);
        bool r=findNode(root->right,p,q);
        return l||r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p||root==q||root==nullptr)return root;
        bool l=findNode(root->left,p,q);
        bool r=findNode(root->right,p,q);
        if(l&&r)return root;
        else if(r)return lowestCommonAncestor(root->right,p,q);
        else if(l)return lowestCommonAncestor(root->left,p,q);
        else return nullptr;
    }
};


class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }

    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==q||root==p||root==nullptr)return root;
        if(q->val>root->val&&p->val>root->val)return dfs(root->right,p,q);
        else if(q->val<root->val&&p->val<root->val)return dfs(root->left,p,q);
        else return root;
    }
};


class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p||root==q||root==nullptr)return root;
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode* r=lowestCommonAncestor(root->right,p,q);
        if(l&&r)return root;
        else if(r) return r;
        else if(l) return l;
        else return nullptr;
    }
};