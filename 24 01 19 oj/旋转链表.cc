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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr||k==0)return head; 
        ListNode* cur=head;
        int count=0;
        ListNode*last;
        while(cur)
        {
            count++;
            last=cur;
            cur=cur->next;
        }
        k=k%count;
        last->next=head;
        cur=head;
        int pos=count-k-1;
        while(pos--)
        {
            cur=cur->next;
        }
        ListNode* ret=cur->next;
        cur->next=nullptr;
        return ret;

    }
};