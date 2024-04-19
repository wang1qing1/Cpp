#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> arr(n);
        for(auto& e:arr)cin>>e;
        vector<int> dp(n);
        dp[0]=arr[0];
        int ret=dp[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=max(dp[i-1]+arr[i],arr[i]);
            ret=max(ret,dp[i]);
        }
        cout<<ret<<endl;
    }
}
// 64 位输出请用 printf("%lld")