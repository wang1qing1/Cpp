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
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        vector<ListNode*> arr1;
        vector<ListNode*> arr2;
        while(l1||l2)
        {
            if(l1)
            {
                arr1.push_back(l1);
                l1=l1->next;
            }
            if(l2)
            {
                arr2.push_back(l2);
                l2=l2->next; 
            } 
        }
        reverse(arr2.begin(),arr2.end());
        int n1=0;int n2=0;
        ListNode* head=new ListNode(0);
        ListNode* tail=head;
        while(n1<arr1.size()&&n2<arr2.size())
        {
            if(arr1[n1]->val<arr2[n2]->val)
            {
                tail->next=arr1[n1++];
                tail=tail->next;
            }
            else {
                tail->next=arr2[n2++];
                tail=tail->next;
            }
        }
        while(n1<arr1.size())
        {
            tail->next=arr1[n1++];
            tail=tail->next;
        }
        while(n2<arr2.size())
        {
            tail->next=arr2[n2++];
            tail=tail->next;
        }
        tail->next=nullptr;
        return head->next;
    }
};