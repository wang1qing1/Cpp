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
    bool hasCycle(ListNode *head) {
        ListNode* l1=head;
        ListNode* l2=head;
        int flag=0;
        while(l1&&l2)
        {
            if(l1==l2&&flag)
            {
                return true;
            }
            flag=1;
            if(l2->next)l2=l2->next->next;
            else return false;
            l1=l1->next;
        }
        return false;
    }
};