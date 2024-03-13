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
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if(pHead==nullptr)return nullptr;
        int count=0;
        ListNode* cur=pHead;
        while(cur)
        {
           cur=cur->next;
           count++; 
        }
        if(k>count)return nullptr;
        ListNode* s=pHead;
        ListNode* f=pHead;
        int path=k;
        while(path--)
        {
            if(f)f=f->next;
        }
        while(f)
        {
            f=f->next;
            s=s->next;
        }
        return  s;
    }
};