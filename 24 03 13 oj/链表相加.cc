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
     * @param l1 ListNode类 
     * @param l2 ListNode类 
     * @return ListNode类
     */
    ListNode* ListAdd(ListNode* l1, ListNode* l2) {
        if(l1==nullptr)return l2;
        if(l2==nullptr)return l1;
        int i=0;
        ListNode* head=new ListNode(0);
        ListNode* cur=head;
        while(l1&&l2)
        {
            int sum=l1->val+l2->val+i;
            i=sum/10;
            cur->next=new ListNode(sum%10);
            l1=l1->next;
            l2=l2->next;
            cur=cur->next;
        }
        ListNode* l=l1?l1:l2;
        while(l)
        {
            int sum=l->val+i;
            i=sum/10;
            cur->next=new ListNode(sum%10);
            l=l->next;
            cur=cur->next;
        }
        if(i)cur->next=new ListNode(i);
        ListNode* ret=head->next;
        delete head;
        return ret;
    }
};