#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
       vector<vector<int>> arr(n,vector<int>(n));
        int ret=-0x3f3f3f3f;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>arr[i][j];
        //从每一列开始
        for(int i=0;i<n;i++)
        {
            vector<int> sum(n,0);
            //累加后面的每一列
            for(int t=i;t<n;t++)
            {
                //累加
                for(int g=0;g<n;g++)
                {
                    sum[g]+=arr[g][t];
                }
                //dp最长子数组
                vector<int> dp(n);dp[0]=sum[0];
                ret=max(ret,dp[0]);
                for(int g=0;g<n;g++)
                {
                    dp[g]=max(dp[g-1]+sum[g],sum[g]);
                    ret=max(ret,dp[g]);
                }
            }
        }
        cout<<ret<<endl;
    }
}
// 64 位输出请用 printf("%lld")