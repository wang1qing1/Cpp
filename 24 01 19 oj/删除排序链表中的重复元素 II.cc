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

    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> hash;
        ListNode*cur=head;
        while(cur)
        {
            hash[cur->val]++;
            cur=cur->next;
        }
        ListNode* newhead=new ListNode(0);
        ListNode*ret=newhead;
        cur=head;
        while(cur)
        {
            if(hash[cur->val]==1)
            {
                cout<<cur->val<<" ";
                newhead->next=cur;
                newhead=newhead->next;
            }
            cur=cur->next;
        }
        newhead->next=nullptr;
        return ret->next;
    }
};