/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* dfs(Node*cur)
    {
        Node* last=nullptr;
        while(cur)
        {
            if(cur->child)
            {
                Node* curnext=cur->next;
                Node* childtail=dfs(cur->child);
                if(curnext)curnext->prev=childtail;
                childtail->next=curnext;
                cur->child->prev=cur;
                cur->next=cur->child;
                cur->child=nullptr;
            }
            last=cur;
            cur=cur->next;
        }
        return last;
    }
    Node* flatten(Node* head) {
        if(head==nullptr)return nullptr;
        dfs(head);
        return head;
    }
};