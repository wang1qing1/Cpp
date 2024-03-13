
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
#include <climits>
#include <unordered_map>
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if(pHead==nullptr)return nullptr;
        unordered_set<ListNode*> hash;
        ListNode* cur=pHead;
        while(cur)
        {
            if(hash.empty()||hash.find(cur)==hash.end())
            {
                hash.insert(cur);
                cur=cur->next;
            }
            else break;
        }
        return cur;
    }
};