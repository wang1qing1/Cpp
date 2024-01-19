/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)return head;
        ListNode*h=head;
        int index=1;
        ListNode* cur = new ListNode(0);
        ListNode*ret=cur;
        ListNode* node=cur;
        while(h)
        {
            if(index>=left&&index<=right)
            {
                //头插
                ListNode*nodelist=node->next;
                ListNode*hnext=h->next;
                if(index==left)cur=h;
                node->next=h;
                h->next=nodelist;
                h=hnext; 
            }
            else
            {
                //尾插
                cur->next=h;
                h=h->next;
                cur=cur->next;
                node=cur;
            }
            index++;
        }
        cur->next=nullptr;
        return ret->next;
    }
};

1  2  3