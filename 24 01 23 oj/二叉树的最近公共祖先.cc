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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //一旦找到p或者q或者null其中一个直接返回
        if(root==nullptr||root==p||root==q)return root;
        //遍历左右子树
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode*r=lowestCommonAncestor(root->right,p,q);
        //由于dfs遍历当前结点左右子树找到的结果都不为空那公共祖先就是当前节点
        if(l&&r)return root;
        else if(l)return l;//将结果继续像上传
        else if(r)return r;
        else return nullptr;//两边都没有找到
    }
};