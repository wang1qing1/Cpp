#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        vector<vector<int>> arr(a,vector<int>(b));
        vector<vector<int>> dp(a+1,vector<int>(b+1,0x3f3f3f3f));
        dp[a][b-1]=1;
        dp[a-1][b]=1;
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
                cin>>arr[i][j]; 
        
        for(int i=a-1;i>=0;i--)
        {
            for(int j=b-1;j>=0;j--)
            {
                dp[i][j]=min(dp[i][j+1],dp[i+1][j])-arr[i][j];
                dp[i][j]=max(1,dp[i][j]);
            }
        }
        cout<<dp[0][0]<<endl;


    }
}
