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
        ListNode* cur1=headA;int count1=0;
        ListNode* cur2=headB;int count2=0;
        while(cur1)
        {
            cur1=cur1->next;
            count1++;
        }
        while(cur2)
        {
            cur2=cur2->next;
            count2++;
        }
        ListNode* longcur=count1>=count2?headA:headB;
        ListNode* shortcur=count1<count2?headA:headB;
        int path=abs(count1-count2);
        while(path--) longcur=longcur->next;
        while(longcur!=shortcur)
        {
            longcur=longcur->next;
            shortcur=shortcur->next;
        }
        return shortcur; 
    }
};