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
    bool _isSameTree(TreeNode* p,TreeNode* q)
    {
        if(p==nullptr&&q==nullptr)return true;
        if(p==nullptr&&q!=nullptr)return false;
        if(p!=nullptr&&q==nullptr)return false;
        if(p->val!=q->val)return false;
        return p->val==q->val&&_isSameTree(p->left,q->left)&&_isSameTree(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {

        return _isSameTree(p,q);
    }
};