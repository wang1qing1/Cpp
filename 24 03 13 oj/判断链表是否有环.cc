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
        //判断头节点是不是null
        if(head==nullptr||head->next==nullptr)return false;
        //快慢指针
        ListNode* f=head->next->next;
        ListNode* s=head;
        //相遇时————有环，或者有一个为null结束————无环，
        while(f!=s&&f&&f->next)
        {
            f=f->next->next;
            s=s->next;
        }
        return (f==s);
    }
};