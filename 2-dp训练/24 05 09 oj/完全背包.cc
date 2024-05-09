#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        vector<int> v(a);
        vector<int> g(a);
        for(int i=0;i<a;i++)
        {
            cin>>v[i]>>g[i];
        }
        vector<vector<int>> dp(a+1,vector<int>(b+1,0));
        vector<vector<int>> dp1(a+1,vector<int>(b+1,-1));
        for(int i=0;i<=a;i++)dp1[i][0]=0;

        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j-v[i-1]>=0)dp[i][j]=max(dp[i-1][j],dp[i][j-v[i-1]]+g[i-1]);
                dp1[i][j]=dp1[i-1][j];
                if(j-v[i-1]>=0&&dp1[i][j-v[i-1]]!=-1)dp1[i][j]=max(dp1[i-1][j],dp1[i][j-v[i-1]]+g[i-1]);
            }
        }
        cout<<dp[a][b]<<endl;
        cout<<(dp1[a][b]==-1?0:dp1[a][b])<<endl;

    }
}
// 64 位输出请用 printf("%lld")