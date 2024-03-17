/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //双指针
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        bool iscycle=false;
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
            {
                iscycle=true;
                break;
            }
        }
        if(!iscycle)return nullptr;
        
		slow=head;
        while(slow!=fast)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//哈希表
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> hash;
        ListNode* cur=head;
        while(cur)
        {
            if(hash.find(cur)==hash.end())
            {
                hash.insert(cur);
                cur=cur->next;
            }
            else
            {
                return cur;
            }
        }
        return NULL;
    }
};
