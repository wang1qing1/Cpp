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
    bool isPalindrome(ListNode* head) {
        ListNode*cur=head;
        int count=0;
        while(cur)
        {
            count++;
            cur=cur->next;
        }
        if(count==0||count==1)return  true;
        ListNode* newhead= new ListNode();
        cur=head;
        int i=0;
        while(i<count/2)
        {
            ListNode* curnext=cur->next;
            ListNode* newheadnext=newhead->next;
            newhead->next=cur;
            cur->next=newheadnext;
            cur=curnext;
            i++;
        }
        if(count%2)cur=cur->next;
        ListNode* l1=cur;
        ListNode* l2=newhead->next;
        while(l1&&l2)
        {
            if(l1->val!=l2->val)return false;
            l1=l1->next;
            l2=l2->next;
        }
        return true;
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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vv;
        ListNode* cur=head;
        while(cur)
        {
            vv.push_back(cur->val);
            cur=cur->next;
        }
        int left=0;
        int right=vv.size()-1;
        if(right<=0)return true;
        while(left<right)
        {
            if(vv[left]!=vv[right])return false;
            left++;
            right--;
        }
        return true;
    }
};