#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> arr(n);
        for(auto &e:arr)cin>>e;
        vector<int> dp(n,1);
        int ret=1;
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(arr[i]>arr[j])
                {
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
            ret=max(dp[i],ret);
        }
        cout<<ret<<endl;
    }
}
// 64 位输出请用 printf("%lld")