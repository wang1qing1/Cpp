#include <iostream>
#include <vector>
using namespace std;

int main() {
    int v, b;
    while (cin >> v >> b) { // 注意 while 处理多个 case
        vector<int> arr(b);
        for(auto& e:arr)cin>>e;
        vector<vector<int>> dp(b+1,vector<int>(v+1));
        for(int i=1;i<=b;i++)
        {
            for(int j=1;j<=v;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j-arr[i-1]>=0)dp[i][j]=max(dp[i][j],dp[i-1][j-arr[i-1]]+arr[i-1]);
            }
        }
        cout<<v-dp[b][v];
    }
}
// 64 位输出请用 printf("%lld")