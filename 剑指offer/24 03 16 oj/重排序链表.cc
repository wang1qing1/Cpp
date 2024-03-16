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
    void reorderList(ListNode* head) {
        if(head==nullptr)return;
        ListNode* cur1=head;
        ListNode* cur2=head;
        ListNode* prev=nullptr;
        //分割前后链表
        while(cur2&&cur2->next)
        {
            prev=cur1;
            cur1=cur1->next;
            cur2=cur2->next->next;
        }
        ListNode* head1;
        ListNode* head2;
        if(cur2)
        {
            head1=head;
            head2=cur1->next;
            cur1->next=nullptr;
        }
        else
        {
            head1=head;
            head2=cur1;
            prev->next=nullptr;
        }

        //反转后半段链表
        ListNode* tmphead=new ListNode(0);
        while(head2)
        {
            ListNode* tmpheadnext=tmphead->next;
            ListNode* head2next=head2->next;
            tmphead->next=head2;
            head2->next=tmpheadnext;
            head2=head2next;
        }
 
        //交叉合并链表
        head2=tmphead->next;
        tmphead->next=nullptr;
        ListNode* tail=tmphead;
        while(head1&&head2)
        {
            ListNode* head1next=head1->next;
            tail->next=head1;
            tail=tail->next;
            tail->next=head2;
            tail=tail->next;;
            head1=head1next;
            head2=head2->next;
        }

        if(head1)tail->next=head1;        
        if(head2)tail->next=head2;        
       

    }
};