#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string astr;
    string bstr;
    cin>>astr>>bstr;
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
                //该位置字符相同
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                dp[i][j]=min(dp[i-1][j-1],dp[i][j]);
            }
            else
            {
                //该位置字符不同，查看dp[i-1][j-1]+1,加上的一次是修改的一次操作
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                dp[i][j]=min(dp[i-1][j-1]+1,dp[i][j]);
            }  
        }
    }
    cout<<dp[n][m]<<endl;
    
    
    return 0;
}