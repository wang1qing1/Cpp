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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)return nullptr;
        map<int,ListNode*> hash;
        ListNode* cur=head;
        while(cur)
        {
            hash[cur->val]=cur;
            cur=cur->next;
        }
        vector<ListNode*> tmp;
        for(auto &[a,b]:hash)
        {
            tmp.push_back(b);
        }
        for(int i=0;i<tmp.size()-1;i++)
        {
            tmp[i]->next=tmp[i+1];
        }
        tmp.back()->next=nullptr;
        return tmp[0];
    }
};