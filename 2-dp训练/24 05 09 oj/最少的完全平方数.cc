#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    int a;
    while (cin >> a) { // 注意 while 处理多个 case
        int n=sqrt(a)+1;
        vector<vector<int>> dp(n+1,vector<int>(a+1,0x3f3f3f3f));
        for(int i=0;i<n;i++)dp[i][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=a;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j-i*i>=0&&dp[i][j-i*i]!=0x3f3f3f3f)dp[i][j]=min(dp[i][j],dp[i][j-i*i]+1);
            }
        }
        cout<<dp[n][a];

    }
}
// 64 位输出请用 printf("%lld")