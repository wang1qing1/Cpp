class Solution {
public:
    ListNode* mergesort(ListNode* node)
    {
        //求链表中点
        if(!node || !node->next) return node;
        ListNode* slow=node;
        ListNode* fast=node;
        ListNode* b=node;
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            b=slow;
            slow=slow->next;
        }
        b->next=nullptr;
        //递归求子区间中点
        ListNode* l1=mergesort(node);
        ListNode* l2=mergesort(slow);
        //合并有序链表
        return merge(l1,l2);
    }
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        if(l1==nullptr)return l2;
        if(l2==nullptr)return l1;
        if(l1->val<l2->val)
        {
            l1->next=merge(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next=merge(l2->next,l1);
            return l2;
        }
    }
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
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
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* cur=head;
        while(cur)
        {
            v.push_back(cur->val);
            cur=cur->next;
        }
        sort(v.begin(),v.end());
        cur=head;
        int i=0;
        while(cur)
        {
            cur->val=v[i++];
            cur=cur->next;
        }
        return head;
    }
};