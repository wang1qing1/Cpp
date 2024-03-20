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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //双指针
        //两个指针分别从头开始走，如果一方走到头那就让他从另一个指针的头开始走
        ListNode* cur1=headA;
        ListNode* cur2=headB;
        while(cur1!=cur2)
        {
            if(cur1==nullptr)cur1=headB;
            else cur1=cur1->next;

            if(cur2==nullptr)cur2=headA;
            else cur2=cur2->next;
        }
        return cur1;
    }
};