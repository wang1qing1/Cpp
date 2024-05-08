#include <iostream>
#include <sys/types.h>
#include <vector>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        vector<u_int64_t> arr(a);
        for(auto& e:arr)cin>>e;
        vector<vector<u_int64_t>> dp(a,vector<u_int64_t>(b,0));
        dp[0][arr[0]%b]=arr[0];
        for(int i=1;i<a;i++)
        {
            int x=arr[i]%b;
            for(int j=0;j<b;j++)
            {
                if(j<x)
                {
                    int tmp=dp[i-1][j+b-x];
                    if(tmp==0)dp[i][j]=0;
                    else dp[i][j]=tmp+arr[i];
                    dp[i][j]=max(dp[i][j],dp[i-1][j]);
                }
                else if(j>x)
                {
                    int tmp=dp[i-1][j-x];
                    if(tmp==0)dp[i][j]=0;
                    else dp[i][j]=tmp+arr[i];
                    dp[i][j]=max(dp[i][j],dp[i-1][j]);
                }
                else
                {
                    int tmp=dp[i-1][0];
                    if(tmp==0)dp[i][j]=0;
                    else dp[i][j]=tmp+arr[i];
                    dp[i][j]=max(dp[i][j],dp[i-1][j]);
                    dp[i][j]=max(dp[i][j],(u_int64_t)arr[i]);
                }
            }
        }
        cout<<(dp[a-1][0]!=0?dp[a-1][0]:-1)<<endl;
    }
}
// 64 位输出请用 printf("%lld")