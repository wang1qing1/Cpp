#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int xi[4]={0,0,-1,1};
int yi[4]={-1,1,0,0};
typedef pair<int,int> PII; 
int n;int m;
vector<vector<int>> arr;
 vector<vector<int>> dp;
//从[x,y]做能到达的最大深度
int dfs(int x,int y,int prev)
{
    //走到边界
    if(x<0||y<0||x>=n||y>=m)return 0;
    //严格递增
    if(prev<=arr[x][y])return 0;
    //已经有了结果，记忆化搜索
    if(dp[x][y])return dp[x][y];
    int tmp=-1;
    for(int t=0;t<4;t++)
    {
        int i=xi[t]+x;
        int j=yi[t]+y;
        tmp=max(tmp,dfs(i,j,arr[x][y]));
    }
    dp[x][y]=tmp+1;
    return dp[x][y];
}

int main() {
    while (cin >> n >> m) { // 注意 while 处理多个 case
        arr.resize(n,vector<int>(m));
        dp.resize(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)cin>>arr[i][j];
        }
        //dp[i][j]所能到达的最长路径长度 
        int ret=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)ret=max(ret,dfs(i,j,0x3f3f3f3f));
        }
        cout<<ret<<endl;
    }
}
// 64 位输出请用 printf("%lld")