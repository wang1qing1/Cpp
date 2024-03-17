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
        ListNode*prev=nullptr;
        ListNode* fast=head;
        ListNode* slow=head;
        int path=n;
        while(path--)fast=fast->next;
        while(fast)
        {
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
        ListNode* slownext=slow->next;
        //如果删除的就是根节点
        if(prev) prev->next=slownext;
        if(slow==head)
        {
            head=slownext;
        }
        delete slow;
        return head;
    }
};