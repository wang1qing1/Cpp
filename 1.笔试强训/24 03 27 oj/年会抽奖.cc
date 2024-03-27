#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<long long> dp(n+1);
        dp[1]=0;dp[2]=1;
        vector<long long> f(n+1);
        f[0]=1;
        f[1]=1;
        f[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
            f[i]=i*f[i-1];
        }
        printf("%.2f%\n",dp[n]*100.0/f[n]);
    }
}
