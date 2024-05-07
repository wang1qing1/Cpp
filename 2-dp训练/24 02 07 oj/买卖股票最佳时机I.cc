#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> arr(n);
        for(auto& e:arr)cin>>e;
        // vector<int> f(n);
        // f[0]=-arr[0];
        // vector<int> g(n);
        // g[0]=0;
        // int ret=0;
        // for(int i=1;i<n;i++)
        // {
        //     g[i]=max(g[i-1],f[i-1]+arr[i]);
        //     f[i]=max(f[i-1],g[i-1]-arr[i]);
        // }
        // cout<<max(g[n-1],f[n-1])<<endl;
        int ret=0;
        int mnum=arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i]<mnum)mnum=arr[i];
            else
            {
                ret=max(ret,arr[i]-mnum);   
            }
        }
        cout<<ret<<endl;
        


    }
}
// 64 位输出请用 printf("%lld")