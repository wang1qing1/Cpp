/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur1=l1;
        ListNode* cur2=l2;
        int i=0;
        ListNode* newhead=new ListNode();
        ListNode* tail=newhead;
        while(l1&&l2)
        {
            int sum=l1->val+l2->val+i;
            i=sum/10;
            tail->next=new ListNode(sum%10);
            tail=tail->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            int sum=l1->val+i;
            i=sum/10;
            tail->next=new ListNode(sum%10);
            tail=tail->next;
            l1=l1->next;
        }
        while(l2)
        {
            int sum=l2->val+i;
            i=sum/10;
            tail->next=new ListNode(sum%10);
            tail=tail->next;
            l2=l2->next;

        }
        if(i)tail->next=new ListNode(1);
        ListNode* ret=newhead->next;

        delete newhead;
        return ret;
    }
};