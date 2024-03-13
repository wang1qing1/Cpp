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
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* ReverseList(ListNode* head) {
        ListNode* newhead=new ListNode(0);
        ListNode* cur=head;
        while(cur)
        {
            ListNode* curnext=cur->next;
            ListNode* newheadnext=newhead->next;
            newhead->next=cur;
            cur->next=newheadnext;
            cur=curnext;
        }
        ListNode* ret=newhead->next;
        delete newhead;
        return ret;
    }
};