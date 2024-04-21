#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string astr;
    string bstr;
    while(cin>>astr>>bstr)
    {
        int n=astr.size();
        int m=bstr.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<=m;i++)dp[0][i]=i;
        for(int i=0;i<=n;i++)dp[i][0]=i;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(astr[i-1]==bstr[j-1])
                {
                    //dp[i-1][j-1]代表不加入astr[i],bstr[i]时的最短编辑距离,由于astr[i]==bstr[j],所以dp[i][j]=dp[i-1][j-1]
                    //dp[i-1][j]代表删除astr[i],时的最短编辑距离，dp[i][j]=dp[i-1][j]加上删除的一次操作
                    //dp[i][j-1]代表删除bstr[i],时的最短编辑距离，dp[i][j]=dp[i][j-1]加上删除的一次操作
                    dp[i][j]=min(dp[i-1][j-1],dp[i-1][j]+1);
                    dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                }
                else 
                {
                    //dp[i-1][j-1]代表不加入astr[i],bstr[i]时的最短编辑路基,dp[i][j]=dp[i-1][j-1]加上一次字符改变操作
                    //dp[i-1][j]代表删除astr[i],时的最短编辑距离，dp[i][j]=dp[i-1][j]加上删除的一次操作
                    //dp[i][j-1]代表删除bstr[i],时的最短编辑距离，dp[i][j]=dp[i][j-1]加上删除的一次操作
                    dp[i][j]=min(dp[i-1][j-1]+1,dp[i-1][j]+1);
                    dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                }
            }
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}