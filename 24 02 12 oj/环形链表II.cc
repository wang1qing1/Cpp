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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* cur1;
        ListNode* cur2;
        while(slow&&fast)
        {
            slow=slow->next;
            if(fast->next)fast=fast->next->next;
            else return NULL;
            if(slow==fast)
            {
                cur1=slow;
                cur2=head;
                while(cur1!=cur2)
                {
                    cur1=cur1->next;
                    cur2=cur2->next;
                }
                return cur1;
            }
        }
        return NULL;
    }
};