#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
       vector<vector<int>> arr(a,vector<int>(b));
       vector<vector<int>> dp(a+1,vector<int>(b+1,0x3f3f3f3f));
       dp[0][1]=0;
       for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
                cin>>arr[i][j]; 

        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+arr[i-1][j-1];
            }
        }  
        cout<<dp[a][b]<<endl;
    }
}
