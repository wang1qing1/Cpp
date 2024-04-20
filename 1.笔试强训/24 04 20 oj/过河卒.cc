#include <iostream>
#include <vector>
using namespace std;
int x[9]={-2,-1,1,2,2,1,-2,-1};
int y[9]={-1,-2,-2,-1,1,2,1,2};
int main() {
    int a, b;
    int n,m;
    while (cin >> a >> b>>n>>m) { // 注意 while 处理多个 case
        vector<vector<int>> arr(a+1,vector<int>(b+1,1));
        for(int i=0;i<=8;i++)
        {
            int xi=x[i]+n;
            int yi=y[i]+m;
            if(xi>=0&&yi>=0&&xi<=a&&yi<=b) arr[xi][yi]=0;
        }
        vector<vector<long long>> dp(a+2,vector<long long>(b+2,0));
        dp[1][0]=1;
        for(int i=1;i<=a+1;i++)
        {
            for(int j=1;j<=b+1;j++)
            {
                if(arr[i-1][j-1]==1)
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        cout<<dp[a+1][b+1]<<endl; 
    }
}


