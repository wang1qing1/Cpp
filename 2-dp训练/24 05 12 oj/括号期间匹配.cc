#include <iostream>
#include <vector>
using namespace std;

int main() {
    string str;
    while (cin >> str) { // 注意 while 处理多个 case
        int n=str.size();
        str=' '+str;
        vector<vector<int>> dp(n+1,vector<int>(n+1,1));
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j>=1;j--)
            {
                if(i==j)dp[i][j]=1;
                else if(i-j==1)
                {
                    dp[i][j]=(str[i]==')'&&str[j]=='(')||(str[i]==']'&&str[j]=='[')?0:2;
                }
                else if(i-j>1)
                {
                    int tmp=0x3f3f3f3f;
                    //1.最左右两端的括号不匹配,将字符串划分为两部分
                    //[j,k] [k+1,i]
                    for(int k=j;k<i;k++)
                    {
                        tmp=min(tmp,dp[k][j]+dp[i][k+1]);
                    }
                    //2.如果最左右两端的括号匹配,[j+1,i-1]
                    //上述两种结果都取最小值
                    dp[i][j]=tmp;
                    if((str[i]==')'&&str[j]=='(')||(str[i]==']'&&str[j]=='['))
                    {
                        dp[i][j]=min(dp[i-1][j+1],tmp);
                    }
                }
            }
        }
        cout<<dp[n][1]<<endl;
    }
}
// 64 位输出请用 printf("%lld")