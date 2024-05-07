#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,m;
    while (cin >> n >> m) { // 注意 while 处理多个 case
        vector<int> arr(n);
        for(auto& e:arr)cin>>e;
        vector<vector<int>> f(n,vector<int>(m+1,-0x3f3f3f3f));
        vector<vector<int>> g(n,vector<int>(m+1,-0x3f3f3f3f));
        //f[i][j]第i天时处于可以卖出的状态,交易次数为j时的最大利润
        //g[i][j]第i天时处于可以买入的状态,交易次数为j时的最大利润
        //规定一次卖出为一次交易
        f[0][0]=-arr[0];
        g[0][0]=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                f[i][j]=max(f[i-1][j],g[i-1][j]-arr[i]);
                g[i][j]=g[i-1][j];
                if(j>=1)g[i][j]=max(g[i][j],f[i-1][j-1]+arr[i]);
            }
        }
        int ret=-1;
        for(auto e:g.back())ret=max(ret,e);
        cout<<ret<<endl;
    }   
}
// 64 位输出请用 printf("%lld")