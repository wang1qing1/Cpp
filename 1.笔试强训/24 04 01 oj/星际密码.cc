#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> dp(10001);
    dp[1]=1;dp[2]=2;
    for(int i=3;i<10001;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
        if(dp[i]>=10000)dp[i]=dp[i]%10000;
    }
    while (cin >>n) { // 注意 while 处理多个 case
        for(int i=0;i<n;i++)
        {
            int pos;cin>>pos;
            printf("%04d",dp[pos]);
        }
        cout<<endl;
    }
}
