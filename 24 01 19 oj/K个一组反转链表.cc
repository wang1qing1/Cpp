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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*cur=head;
        int count=0;
        while(cur)
        {
            cur=cur->next;
            count++;
        }
        cout<<count<<endl;
        int n=count/k;
        ListNode* newhead=new ListNode(0);
        ListNode*ret=newhead;
        cur=head;
        while(n--)
        {
            int i=0;
            ListNode*tmp=cur;
            while(i<k)
            {
                ListNode*newheadnext=newhead->next;
                ListNode*curnext=cur->next;
                newhead->next=cur;
                cur->next=newheadnext;
                cur=curnext;
                i++;
            }
            newhead=tmp;
        }
        newhead->next=cur;
        return ret->next;

    }
};