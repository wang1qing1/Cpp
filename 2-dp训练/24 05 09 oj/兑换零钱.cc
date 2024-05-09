#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) { // 注意 while 处理多个 case
        vector<int> arr(n);
        for(auto& e:arr)cin>>e;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0x3f3f3f3f));
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j-arr[i-1]>=0&&dp[i][j-arr[i-1]]!=0x3f3f3f3f)dp[i][j]=min(dp[i][j],dp[i][j-arr[i-1]]+1);
            }
        }
        cout<<(dp[n][m]==0x3f3f3f3f?-1:dp[n][m])<<endl;
        
    }
}
// 64 位输出请用 printf("%lld")