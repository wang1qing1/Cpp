#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> arr(n);
        for(auto& e:arr)cin>>e;
        vector<int> f(n); //f[i]标识第i天结束的时候处于可以卖出的状态时，多获得的最大收益
        vector<int> g(n); //f[i]标识第i天结束的时候处于可以买入的状态时，多获得的最大收益
        g[0]=0;
        f[0]=-arr[0];
        int ret=0;
        for(int i=1;i<n;i++)
        {
            g[i]=max(g[i-1],f[i-1]+arr[i]);
            f[i]=max(f[i-1],g[i-1]-arr[i]);
        }
        cout<<max(g[n-1],f[n-1])<<endl;
    }
}
// 64 位输出请用 printf("%lld")