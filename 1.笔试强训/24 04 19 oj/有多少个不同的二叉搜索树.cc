#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> dp(20,0);
    dp[0]=dp[1]=1;
    for(int i=2;i<=20;i++)
    {
        for(int j=0;j<=i-1;j++)
        {
            dp[i]+=(dp[j]*dp[i-1-j]);
        }
    }
    while (cin >> n) { // 注意 while 处理多个 case
        cout<<dp[n]<<endl;   
    }
}
// 64 位输出请用 printf("%lld")