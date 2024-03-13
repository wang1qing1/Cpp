/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param lists ListNode类vector 
     * @return ListNode类
     */

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return nullptr;
        return _sort(lists,0,lists.size()-1);
    }

    ListNode* _sort(vector<ListNode*> lists,int begin,int end)
    {
        
        if(begin==end)return lists[begin];
        int mid=(begin+end)/2;
        ListNode* l1= _sort(lists,begin,mid);
        ListNode* l2=_sort(lists,mid+1,end);
        ListNode* cur=new ListNode(1);
        ListNode* head=cur;
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                cur->next=l1;
                l1=l1->next;
            }
            else 
            {
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        if(l1)cur->next=l1;
        if(l2)cur->next=l2;
        ListNode* ret=head->next;
        delete head;
        return ret;
    }

};