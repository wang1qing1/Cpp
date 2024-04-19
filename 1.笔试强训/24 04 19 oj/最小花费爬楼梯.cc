#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> cost(n);
        for(auto& e:cost)cin>>e;
        vector<int> dp(n+1,0);
        for(int i=2;i<=n;i++)
        {
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        cout<<dp[n]<<endl;
    }
}
