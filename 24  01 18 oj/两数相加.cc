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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1=l1;
        ListNode*h2=l2;
        ListNode *ret=new ListNode(0);
        ListNode*head=ret;
        int tmp=0;
        while(h1&&h2)
        {
            int num1=h1->val;
            int num2=h2->val;
            int num=num1+num2+tmp;
            tmp=num/10;
            ret->next=new ListNode(num%10);
            ret=ret->next;
            h1=h1->next;
            h2=h2->next;
        }
        ListNode*h=h1==nullptr?h2:h1;
        while(h)
        {
            int num=h->val;
            int sum=num+tmp;
            tmp=sum/10;
            ret->next= new ListNode(sum%10);
            ret=ret->next; 
            h=h->next;           
        }
        if(tmp)
            ret->next=new ListNode(tmp);
        return head->next;
    }
};