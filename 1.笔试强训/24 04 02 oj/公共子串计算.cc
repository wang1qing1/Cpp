#include <iostream>
#include <vector>
using namespace std;

int main() {
    string str1,str2;
    while (cin >> str1 >> str2) { // 注意 while 处理多个 case
        int n=str1.size();int m=str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int ret=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else 
                {
                    dp[i][j]=0;
                }
                ret=max(ret,dp[i][j]);
            }
        }
        cout<<ret<<endl;
        
        
    }
}
