#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        vector<long long> arr(a);
        vector<long long> tmp(a);
        for(int i=0;i<a;i++)
        {
            cin>>tmp[i];
            arr[i]=tmp[i];
            if(i>=1)
            {
                arr[i]-=tmp[i-1];
            }
        }
        for(int i=0;i<b;i++)
        {
            int l,r,k;
            cin>>l>>r>>k;
            arr[l-1]+=k;
            if(r<a)arr[r-1+1]-=k;
        }
        for(int i=1;i<a;i++)
        {
            arr[i]=arr[i]+arr[i-1];
        }
        for(auto e:arr)cout<<e<<" ";
    }
}
// 64 位输出请用 printf("%lld")