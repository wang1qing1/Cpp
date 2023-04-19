#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<queue>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
//leetcode 606. 根据二叉树创建字符串
class Solution {
public:
    string _tree2str(TreeNode* root)
    {
        string str;
        if (root == nullptr)
        {
            str += "";
            return str;
        }

        str += to_string(root->val);
        if (root->left != nullptr && root->right == nullptr)
        {
            str += '(';
            str += _tree2str(root->left);
            str += ')';
        }
        if (root->right)
        {
            str += '(';
            str += _tree2str(root->left);
            str += ')';

            str += '(';
            str += _tree2str(root->right);
            str += ')';
        }
        return str;
    }
    string tree2str(TreeNode* root) {
        return _tree2str(root);
    }
};

//leetcode 102. 二叉树的层序遍历
class Solution1 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> vv;
        if (root)
            qu.push(root);
        int qusize = qu.size();
        int i = 0;
        while (!qu.empty())
        {
            vector<int> v;
            while (qusize--)
            {
                TreeNode* cur = qu.front();
                qu.pop();
                v.push_back(cur->val);
                if (cur->left)
                    qu.push(cur->left);
                if (cur->right)
                    qu.push(cur->right);
            }
            vv.push_back(v);
            qusize = qu.size();
        }
        return vv;
    }
};
//leetcode236. 二叉树的最近公共祖先
class Solution2 {
public:
    bool inTree(TreeNode* root, TreeNode* p)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root == p)
        {
            return true;
        }
        if (inTree(root->left, p) || inTree(root->right, p))
            return true;
        else
            return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        if (root == p || root == q)
            return root;
        bool p_left = inTree(root->left, p);
        bool q_right = inTree(root->right, q);
        bool q_left = !q_right;
        bool p_right = !p_left;
        if (p_left && q_right || q_left && p_right)
            return root;
        else if (p_left && q_left)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }
};
//leetcode236. 二叉树的最近公共祖先
class Solution3 {
public:
    bool getstnode(stack<TreeNode*>& st, TreeNode* root, TreeNode* node)
    {
        st.push(root);
        if (root == node)
        {
            return true;
        }
        if (root == nullptr)
        {
            st.pop();
            return false;
        }
        if (getstnode(st, root->left, node) || getstnode(st, root->right, node))
        {
            return true;
        }
        else
        {
            st.pop();
            return false;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        getstnode(st1, root, p);
        getstnode(st2, root, q);
        while (st1.size() != st2.size())
        {
            if (st1.size() > st2.size())
            {
                st1.pop();
            }
            else if (st1.size() < st2.size())
            {
                st2.pop();
            }
        }
        while (st1.top() != st2.top())
        {
            st1.pop();
            st2.pop();
        }
        return st1.top();
    }
};

//牛客 JZ36 二叉搜索树与双向链表
class Solution4 {
public:
    void MidOrder(TreeNode* cur, TreeNode*& prev)
    {
        if (cur == nullptr)
        {
            return;
        }
        MidOrder(cur->left, prev);
        cur->left = prev;
        if (prev != nullptr)
        {
            prev->right = cur;
        }
        prev = cur;
        MidOrder(cur->right, prev);
    }
    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode* prev = nullptr;
        MidOrder(pRootOfTree, prev);
        TreeNode* cur = pRootOfTree;
        if (cur == nullptr)
        {
            return nullptr;
        }
        while (cur->left)
        {
            cur = cur->left;
        }
        return cur;
    }
};

//leetcode106. 从中序与后序遍历序列构造二叉树
//leetcode106. 从中序与后序遍历序列构造二叉树
class Solution5 {
public:
    TreeNode* _buildTree(vector<int>& postorder, vector<int>& inorder, int& prei, int head, int tail)
    {
        if (head > tail)
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[prei]);
        int rooti = head;
        while (1)
        {
            if (inorder[rooti] == postorder[prei])
            {
                break;
            }
            rooti++;
        }
        prei--;
        root->right = _buildTree(postorder, inorder, prei, rooti + 1, tail);
        root->left = _buildTree(postorder, inorder, prei, head, rooti - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = postorder.size() - 1;
        return _buildTree(postorder, inorder, i, 0, inorder.size() - 1);
    }
};

//leetcode105. 从前序与中序遍历序列构造二叉树
class Solution6 {
public:
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& prei, int head, int tail)
    {
        if (head > tail)
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[prei]);
        int rooti = head;
        while (1)
        {
            if (inorder[rooti] == preorder[prei])
            {
                break;
            }
            rooti++;
        }
        prei++;
        root->left = _buildTree(preorder, inorder, prei, head, rooti - 1);
        root->right = _buildTree(preorder, inorder, prei, rooti + 1, tail);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        return _buildTree(preorder, inorder, i, 0, inorder.size() - 1);
    }
};

//leetcode144. 二叉树的前序遍历
class Solution7 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        stack<TreeNode*> st;
        vector<int> v;
        while (cur || !st.empty())
        {
            while (cur)
            {
                v.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* topnode = st.top();
            st.pop();
            cur = topnode->right;
        }
        return v;
    }
};





