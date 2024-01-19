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
    ListNode* partition(ListNode* head, int x) {
        ListNode*head1=new ListNode(0);
        ListNode*ret1=head1;
        ListNode*head2=new ListNode(0);
        ListNode*ret2=head2;

        ListNode* cur=head;
        while(cur)
        {
            ListNode* curnext=cur->next;
            if(cur->val<x)
            {
                head1->next=cur;
                head1=head1->next;
            }
            else
            {
                head2->next=cur;
                head2=head2->next;
            }
            cur=curnext;
        }
         head2->next=nullptr;
        head1->next=ret2->next;
        return ret1->next;
    }
};