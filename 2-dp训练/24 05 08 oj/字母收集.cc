#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map<int,int> hash;
    int a, b;
    hash['l']=4;
    hash['o']=3;
    hash['v']=2;
    hash['e']=1;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        vector<vector<char>> arr(a,vector<char>(b));
        vector<vector<long long>> dp(a+1,vector<long long>(b+1,0));
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                cin>>arr[i][j];
            }
        }
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j])+hash[arr[i-1][j-1]];
            }
        }
        cout<<dp[a][b]<<endl;


    }
}
// 64 位输出请用 printf("%lld")