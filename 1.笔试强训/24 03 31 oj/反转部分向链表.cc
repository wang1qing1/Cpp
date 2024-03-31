#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v)
    :val(v),next(nullptr)
    {}
};

    ListNode* ReverseListK(ListNode* head,int left,int right,int len)
    {
        ListNode* newhead=new ListNode(0);
        ListNode*tail=newhead;
        ListNode*inserthead=newhead;
        ListNode* headcur=head;
        for(int i=0;i<len;i++)
        {
            if(i>=left-1&&i<=right-1)
            {
                ListNode*headnext=headcur->next;
                ListNode* insertnext=inserthead->next;
                inserthead->next=headcur;
                headcur->next=insertnext;
                if(i==left-1)
                {
                    tail=headcur;
                    tail->next=nullptr;
                }
                headcur=headnext;
                
            }
            else
            {   
                tail->next=headcur;
                headcur=headcur->next;
                tail=tail->next;
                inserthead=tail;
            }
        }
        return newhead->next;
    }

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        ListNode*head=new ListNode(0);
        ListNode* tail=head;
        for(int i=0;i<n;i++)
        {
            int num;cin>>num;
            tail->next=new ListNode(num);
            tail=tail->next;
        }
        int left,right;
        cin>>left>>right;
        ListNode* ret=ReverseListK(head->next,left,right,n);
        while(ret)
        {
            cout<<ret->val<<" ";
            ret=ret->next;
        }
    }
}
// 64 位输出请用 printf(\"%lld\")