#include <iostream>
#include <vector>
using namespace std;

int main() {
    string str;
    while (cin >> str) { // 注意 while 处理多个 case
        int n=str.size();
        str=" "+str;
        //dp[i][j]:str[i,j]是否是一个回文串
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        int ret=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j>=1;j--)
            {
                if(i==j)dp[i][j]=1;
                else if(i-j==1)
                {
                    if(str[i]==str[j])dp[i][j]=2;
                    else dp[i][j]=1;
                }
                else if(i-j>1)
                {
                    if(str[i]==str[j])dp[i][j]=dp[i-1][j+1]+2;
                    else dp[i][j]=max(dp[i][j+1],dp[i-1][j]);
                }
                ret=max(dp[i][j],ret);
            }
        }
        cout<<ret<<endl;
    }
}
