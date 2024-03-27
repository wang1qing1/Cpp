#include <iostream>
#include <vector>
using namespace std;
int desc[4][2][2]={
    {{0,1},{0,-1}},//横——左右
    {{1,0},{-1,0}},//竖——上下
    {{-1,-1},{1,1}},//主对角线，左上右下
    {{-1,1},{1,-1}}//副对角线，右上左下
};
bool chack(vector<string>& vstr,int x,int y,char ch)
{
    //四个大方向
    int ret=0;
    for(int i=0;i<4;i++)
    {
        int sum=0;//统计一个方向上连续的棋子数目
        //两个小方向
        for(int j=0;j<2;j++)
        {
            int nx=x;
            int ny=y;
            while(nx>=0&&nx<20&&ny>=0&&ny<20&&vstr[nx][ny]==ch)
            {
                sum++;
                nx+=desc[i][j][0];
                ny+=desc[i][j][1];
            }
        }
        ret=max(ret,sum);
    }
    return (ret-1)>=5;
}
bool HaveFive(vector<string>& vstr)
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            if(vstr[i][j]=='*'||vstr[i][j]=='+')
            {
                if(chack(vstr,i,j,vstr[i][j]))return true;
            }
        }
    }
    return false;
}
int main() {
    vector<string> vstr(20);
    int t=0;
    while (cin >>vstr[t++]) { // 注意 while 处理多个 case
       if(t==20)
       {
            if(HaveFive(vstr))cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
            t=0;
       }
    }
}
// 64 位输出请用 printf(\"%lld\")