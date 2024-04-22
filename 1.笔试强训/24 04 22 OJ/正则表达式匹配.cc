#include <iostream>
#include <vector>
using namespace std;

int main() {
    string a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        int n=a.size();
        int m=b.size();
        a=' '+a;
        b=' '+b;
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        //dp[0][0]:两个串都是空串，匹配成功
        //dp[i][0](i>=1):全部匹配失败
        //dp[0][i](i>=1):第一个字符不能是*,从第二个字符开始,偶数位置上是*才能匹配空串，如果出现一个不是空串，后面都无法匹配空串
        for(int i=1;i<=m;i++)
        {
            if(i%2==0)
            {
                if(b[i]=='*')dp[0][i]=true;
                else break;
            }
        }
        dp[0][0]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(b[j]!='.'&&b[j]!='*')
                {
                    if(a[i]==b[j])dp[i][j]=dp[i-1][j-1];
                    else dp[i][j]=false;
                }
                else if(b[j]=='.')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else 
                {
                    if(b[j-1]=='.')
                    {
                        dp[i][j]=dp[i][j-2]||dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j]=(dp[i-1][j]&&a[i]==b[j-1])||dp[i][j-2];
                    }
                }
            }
        }
        if(dp[n][m])cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
}
