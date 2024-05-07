#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> arr(n);
        for(auto& e:arr)cin>>e;
        vector<vector<int>> f(n,vector<int>(3,-0x3f3f3f3f));
        vector<vector<int>> g(n,vector<int>(3,-0x3f3f3f3f));
        //f[i][j]第i天时处于可以卖出的状态,交易次数为j时的最大利润
        //g[i][j]第i天时处于可以买入的状态,交易次数为j时的最大利润
        f[0][0]=-arr[0];
        g[0][0]=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=2;j++)
            {
                //交易次数为0时
                if(j==0)
                {
                    //前面可以由买入,第i天结束以后处于可卖出的状态
                    //首先在第i-1天可买入的状态下,第i天买入
                    //或者是第i-1天处于可卖出的状态,第i天不买不卖
                    f[i][j]=max(f[i-1][j],g[i-1][j]-arr[i]);
                    //但是前面不能有卖出的情况,第i天之后买入的情况只能由第i-1天时买入的，第i天不买不卖
                    g[i][j]=g[i-1][j];
                }
                else
                {
                    //前面可以由买入,第i天结束以后处于可卖出的状态
                    //首先在第i-1天可买入的状态下,第i天买入
                    //或者是第i-1天处于可卖出的状态,第i天不买不卖
                    f[i][j]=max(f[i-1][j],g[i-1][j]-arr[i]);
                    //由于交易次数大于1,代表存在交易j-1
                    g[i][j]=g[i-1][j];
                    g[i][j]=max(g[i][j],f[i-1][j-1]+arr[i]);
                }
            }
        }
        cout<<max(g[n-1][0],max(g[n-1][1],g[n-1][2]));
        

    }
}
// 64 位输出请用 printf("%lld")