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
        ListNode*cur=head;
        int count=0;
        while(cur)
        {
            cur=cur->next;
            count++;
        }
        int erasepos=count-n;
        ListNode*newhead=new ListNode(0);
        newhead->next=head;
        ListNode* prev=newhead;
        cur=head;
        while(erasepos--)
        {
            prev=cur;
            cur=cur->next;
        }
        ListNode*curnext=cur->next;
        prev->next=curnext;
        delete cur;
        return newhead->next;

    }
};
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
        ListNode*left=head;
        ListNode*right=head;
        int i=0;
        while(i<n)
        {
            right=right->next;
            i++;
        }
        ListNode*newhead=new ListNode();
        newhead->next=head;
        ListNode*prev=newhead;
        while(right)
        {
            prev=left;
            left=left->next;
            right=right->next;
        }
        ListNode*leftnext=left->next;
        prev->next=leftnext;
        delete left;
        return newhead->next;
    }
};
};