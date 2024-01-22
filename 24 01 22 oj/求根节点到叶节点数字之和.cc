-/**
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
    int dfs(TreeNode* root,int num)
    {
        int ret=num*10+root->val;
        if(root->left==nullptr&&root->right==nullptr)return ret;
        int tmp=0;
        if(root->left) tmp+=dfs(root->left,ret);
        if(root->right) tmp+=dfs(root->right,ret);
        return tmp;
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};


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
    int _sumNumber(TreeNode* root,string str)
    {

        if(root->left==nullptr&&root->right==nullptr)
        {
            str+=to_string(root->val);
            return atoi(str.c_str());
        }
        int numleft=0;
        if(root->left)numleft=_sumNumber(root->left,str+to_string(root->val));
        int numright=0;
        if(root->right)numright=_sumNumber(root->right,str+to_string(root->val));
        return numleft+numright;
    }
    int sumNumbers(TreeNode* root) {
        string str;
        return _sumNumber(root,str);
    }
};