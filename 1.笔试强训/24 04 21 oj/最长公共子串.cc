#include <iostream>
#include <vector>
using namespace std;

int main() {
    string a, b;
    int n,m;
    while (cin >> n >> m>>a>>b) { // 注意 while 处理多个 case
        //dp[i][j]:以a[i]结尾的子串，b[j]结尾的子串最长的公共子串长度
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int ret=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                ret=max(ret,dp[i][j]);
            }
        }
        cout<<ret<<endl;
    }
}
// 64 位输出请用 printf("%lld")