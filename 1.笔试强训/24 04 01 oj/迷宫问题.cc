#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> PII;
int xi[4]={0,0,-1,1};
int yi[4]={-1,1,0,0};
int targetx;
int targety;
vector<PII> ret;
void dfs(vector<vector<int>>& arr,int a,int b,vector<PII>& path)
{
    if(a==targetx-1&&b==targety-1)
    {
        ret=path;
        return ;
    }
    for(int i=0;i<4;i++)
    {
        int x=a+xi[i];
        int y=b+yi[i];
        if(x>=0&&x<targetx&&y>=0&&y<targety&&arr[x][y]==0)
        {
            arr[x][y]=1;
            path.push_back({x,y});
            dfs(arr,x,y,path);
            path.pop_back();
            arr[x][y]=0;
        }
    }
}
int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        targetx=a;
        targety=b;
        vector<vector<int>> arr(a,vector<int>(b));
        for(auto& e:arr)
            for(auto& i:e)cin>>i;
        vector<PII> path;
        path.push_back({0,0});
        dfs(arr,0,0,path);
        for(auto [a,b]:ret)
        {
            printf("(%d,%d)\n",a,b);
        }
    }
}
// 64 位输出请用 printf("%lld")