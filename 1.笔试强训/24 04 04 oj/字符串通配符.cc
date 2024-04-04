#include <iostream>
#include <vector>
using namespace std;

int main() {
    string a,b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        int n=a.size();
        int m=b.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int i=1;i<=n;i++)
        {
            if(a[i]=='*')
            {
                dp[i][0]=true;
            }
            else break;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]=='*')
                {
                    dp[i][j]=(dp[i-1][j]||dp[i][j-1]);
                }
                else if(a[i-1]=='?'||a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1];
            }
        }
        if(dp[n][m])cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
}
// 64 位输出请用 printf("%lld")