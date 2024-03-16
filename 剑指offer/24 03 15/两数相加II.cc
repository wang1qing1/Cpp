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
        stack<int> st1;
        stack<int> st2;
        while(l1||l2)
        {
            if(l1)
            {
                st1.push(l1->val);
                l1=l1->next;
            }
            if(l2)
            {
                st2.push(l2->val);
                l2=l2->next;
            }
        }
        int i=0;
        ListNode* head=new ListNode(0);
        while(!st1.empty()||!st2.empty())
        {
            int num1=st1.empty()?0:st1.top();
            if(!st1.empty())st1.pop();
            int num2=st2.empty()?0:st2.top();
            if(!st2.empty())st2.pop();
            int sum=i+num1+num2;
            ListNode* headnext=head->next;
            ListNode* node=new ListNode(sum%10);
            i=sum/10;
            head->next=node;
            node->next=headnext;
        }
        if(i)
        {
            head->val=1;
            return head;
        }
        return head->next;
    }
};