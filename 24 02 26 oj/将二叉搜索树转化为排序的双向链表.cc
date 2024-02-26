/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* prev=nullptr;
    void dfs(Node* cur)
    {
        if(cur==nullptr)return ;
        dfs(cur->left);
        if(prev==nullptr) 
        {
            prev=cur;
        }
        else
        {
            cur->left=prev;
            prev->right=cur;
            prev=cur;
        }
        dfs(cur->right);
    }
    Node* treeToDoublyList(Node* root) {
        if(root==nullptr)return nullptr;
        Node* ret=root;
        Node* tail=root;
        while(tail->right)tail=tail->right;
        while(ret->left) ret=ret->left;
        Node* cur=ret;
        dfs(root);
        ret->left=tail;
        tail->right=ret;
        return ret;
    }
};