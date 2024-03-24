#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int xi[]={1,-1,0,0};
int yi[]={0,0,1,-1};
int main() {
    string s;
    vector<string> vstr(10);
    int t=0;
    while(cin>>vstr[t++])
    {
        if(t==10)
        {
            queue<pair<int,int>> q;
            q.push({0,1});
            int path=0;
            int ret=0x3f3f3f3f;
            while(!q.empty())
            {
                int count=q.size();
                while(count--)
                {
                    auto [x,y]=q.front();
                    q.pop();
                    vstr[x][y]='#';
                    if(x==9&&y==8)
                    {
                        ret=min(ret,path);
                    }
                    for(int i=0;i<4;i++)
                    {
                        if(x+xi[i]>=0&&y+yi[i]>=0&&x+xi[i]<10&&y+yi[i]<10&&vstr[x+xi[i]][y+yi[i]]!='#')q.push({x+xi[i],y+yi[i]});
                    }
                }
                 path++;
            }
            cout<<ret<<endl;
            t=0;
        }

        
       
    }
        
} 
// 64 位输出请用 printf(\"%lld\")