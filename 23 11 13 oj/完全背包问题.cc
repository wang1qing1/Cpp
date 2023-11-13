#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n=0;int bag=0;
    cin>>n>>bag;
    vector<int> v(n+1);
    vector<int> w(n+1);
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    vector<vector<int>> dp(n+1,vector<int>(bag+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=bag;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=v[i]) dp[i][j]=max(dp[i][j],dp[i][j-v[i]]+w[i]);
        }
    }
    cout<<dp[n][bag]<<endl;
    for(int i=0;i<=bag;i++) dp[0][i]=-1;
    dp[0][0]=0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=bag;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=v[i]&&dp[i][j-v[i]]!=-1) dp[i][j]=max(dp[i][j],dp[i][j-v[i]]+w[i]);
        }
    }
    cout<<(dp[n][bag]==-1?0:dp[n][bag])<<endl;

}
// 64 位输出请用 printf("%lld")