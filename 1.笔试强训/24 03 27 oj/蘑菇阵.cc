#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    while (cin >> n >> m >> k) {
        vector<vector<char>> map(n, vector<char>(m, '.'));
        for (int i = 0; i < k; i++) {
            int a;
            int b;
            cin >> a >> b;
            map[a - 1][b - 1] = 'm';
        }
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i==1&&j==1)dp[i][j]=1;
                else if(map[i-1][j-1]=='m')dp[i][j]=0;
                else dp[i][j] = dp[i-1][j]*(j==m?1:0.5) + dp[i][j-1]*(i==n?1:0.5);
            }
        }        
        printf("%.2f\n",dp[n][m]);
    }
}
