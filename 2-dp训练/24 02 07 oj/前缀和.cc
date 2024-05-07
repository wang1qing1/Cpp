#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(auto& e:arr)cin>>e;
    vector<long long> dp(n+1,0);
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+arr[i-1];
    }
    for(int i=0;i<m;i++) { // 注意 while 处理多个 case
        cin>>a>>b;
        cout<<dp[b]-dp[a-1]<<endl;
    }
}
// 64 位输出请用 printf("%lld")