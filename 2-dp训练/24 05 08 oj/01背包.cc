#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) { // 注意 while 处理多个 case
        vector<int> g(n);//体积
        vector<int> v(n);//价值
        for(int i=0;i<n;i++)
        {
            cin>>v[i]>>g[i];
        }
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j-v[i-1]>=0)dp[i][j]=max(dp[i][j],dp[i-1][j-v[i-1]]+g[i-1]);
            }
        }
        cout<<dp[n][m]<<endl;
        for(int i=0;i<=m;i++)dp[0][i]=-1;
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j-v[i-1]>=0&&dp[i-1][j-v[i-1]]!=-1)dp[i][j]=max(dp[i][j],dp[i-1][j-v[i-1]]+g[i-1]);
            }
        }
        cout<<(dp[n][m]==-1?0:dp[n][m])<<endl;
    }
}
// 64 位输出请用 printf("%lld")
//滚动数组优化
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) { // 注意 while 处理多个 case
        vector<int> g(n);//体积
        vector<int> v(n);//价值
        for(int i=0;i<n;i++)
        {
            cin>>v[i]>>g[i];
        }
        vector<int> dp(m+1);
        vector<int> dp1(m+1,-1);
        dp1[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=m;j>=1;j--)
            {
                if(j-v[i-1]>=0)dp[j]=max(dp[j],dp[j-v[i-1]]+g[i-1]);
                if(j-v[i-1]>=0&&dp1[j-v[i-1]]!=-1)dp1[j]=max(dp1[j],dp1[j-v[i-1]]+g[i-1]);
            }
        }
        cout<<dp[m]<<endl;
        cout<<(dp1[m]==-1?0:dp1[m])<<endl;
    }
}
// 64 位输出请用 printf("%lld")