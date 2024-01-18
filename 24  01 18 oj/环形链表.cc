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
        ListNode* f=head;
        ListNode* s=head;
        bool flag=0;
        while(f&&s)
        {
            if(flag&&f==s)//相遇
            {
                return true;
            }
            flag=1;
            if(f->next)f=f->next->next;
            else return false;

            s=s->next;
        }
        return false;

    }
};