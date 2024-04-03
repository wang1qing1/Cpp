#include <iostream>
#include <vector>
using namespace std;

int main() {
    string a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        if(a.size()>b.size())
        {
            swap(a,b);
        }
        int n=a.size();
        int m=b.size();
        //n是较短字符串，较长字符串
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int ret=0;
        int end=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else 
                {
                    dp[i][j]=0;
                }
                if(dp[i][j]>ret)
                {
                    ret=dp[i][j];
                    end=i;
                }                
            }
        }
        cout<<string(a.begin()+end-ret,a.begin()+end)<<endl;
    }
}
// 64 位输出请用 printf("%lld")