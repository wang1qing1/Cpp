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
    ListNode* sort(vector<ListNode*>&lists,int begin,int end)
    {
        if(begin>=end) return lists[begin];
        int mid=(begin+end)/2;
        ListNode* left=sort(lists,begin,mid);
        ListNode* right=sort(lists,mid+1,end);

        ListNode* head=new ListNode(0);
        ListNode* tail=head;
        while(left&&right)
        {
            if(left->val<right->val)
            {
                tail->next=left;
                left=left->next;
            }
            else
            {
                tail->next=right;
                right=right->next;
            } 
            tail=tail->next;
        }
        if(left)tail->next=left;
        if(right)tail->next=right;
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return nullptr;
        return sort(lists,0,lists.size()-1);
    }
};