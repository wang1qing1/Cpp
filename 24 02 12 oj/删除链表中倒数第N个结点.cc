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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur=head;
        int i=0;
        while(i<n)
        {
            cur=cur->next;
            i++;
        }
        ListNode* newhead=head;
        ListNode* H=new ListNode();
        H->next=head;
        ListNode* prev=H;
        while(cur)
        {
            prev=newhead;
            cur=cur->next;
            newhead=newhead->next;
        }
        ListNode* newheadnext=newhead->next;
        prev->next=newheadnext;
        delete newhead;
        ListNode* ret=H->next;
        delete H;
        return ret;

    }
};