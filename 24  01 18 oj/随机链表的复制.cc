/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*newhead=new Node(0);
        Node*ret=newhead;
        Node*lastret=ret;
        Node*Head=head;
        Node* cur=head;
        unordered_map<Node*,int> hash;
        vector<Node*> copy;
        int pos=0;
        while(cur)
        {
            hash[cur]=pos++;
            newhead->next= new Node(cur->val);
            newhead=newhead->next;
            copy.push_back(newhead);
            cur=cur->next;
        }
        Node*newheadsecond=ret->next;
        while(newheadsecond)
        {
            newheadsecond->random=(Head->random==nullptr?nullptr:copy[hash[Head->random]]);
            Head=Head->next;
            newheadsecond=newheadsecond->next;
        }
        return lastret->next;
    }
};