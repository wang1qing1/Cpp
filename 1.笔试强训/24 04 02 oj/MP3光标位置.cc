#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> arr(n+1);
        for(int i=1;i<=n;i++)arr[i]=i;
        int begin=1;int end=(n>=4?4:n);
        int index=1;
        char op;
        while(cin>>op)
        {
            if(op=='U')
            {
                index--;
                if(index==0&&begin==1)
                {
                    index=n;
                    begin=n-3>=1?n-3:1;
                    end=n;
                }
                else if(index<begin)
                {
                    begin--;
                    end--;
                }
            }
            else
            {
                index++;
                if(index==n+1&&end==n)
                {
                    index=1;
                    begin=1;
                    end=(n>=4?4:n);
                }
                else if(index>end)
                {
                    begin++;
                    end++;
                }
            }
        }
        for(int i=begin;i<=end;i++)cout<<i<<" ";
        cout<<endl;
        cout<<index<<endl;
    }
}
// 64 位输出请用 printf("%lld")
// 64 位输出请用 printf("%lld")