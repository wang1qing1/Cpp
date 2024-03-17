/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        //链表为null，创建结点返回
        if(head==nullptr)
        {
            Node* node=new Node(insertVal);
            node->next=node;
            return node;
        }
        Node* cur=head->next;
        Node* prev=head;
        //链表只有一个结点，直接插入
        if(cur==prev)
        {
            Node* node=new Node(insertVal);
            cur->next=node;
            node->next=cur;
        }
        else
        {
            //链表节点数多
            while(cur!=head)
            {
                //情况三：car->val<insertval<prev->val
                if(cur->val>=insertVal&&prev->val<=insertVal)
                {
                    break;
                }
                //情况四：insertval>=max(val) || insertval<=min(val)
                //prev为最大数据，cur为最小，此时来到了链表的首尾连接处
                if(prev->val>cur->val)
                {
                    if(insertVal<=cur->val||insertVal>=prev->val)
                    {
                        break;
                    }
                }
                cur=cur->next;
                prev=prev->next;
            }

        }
        //插入结点
        Node* newnode=new Node(insertVal);
        prev->next=newnode;
        newnode->next=cur;
        return head;
    }
};