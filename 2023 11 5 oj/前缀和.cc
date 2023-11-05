#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;int q;

    cin>>n>>q;
    vector<int> arr(n);
    for(auto &e:arr) cin>>e;
    vector<long long> dp(n+1,0);
    for(int i=1;i<=n;i++) dp[i]=dp[i-1]+(long long)arr[i-1];
    while(q--)
    {
        int left;
        int right;
        cin>>left>>right;
        cout<<dp[right]-dp[left-1]<<endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")