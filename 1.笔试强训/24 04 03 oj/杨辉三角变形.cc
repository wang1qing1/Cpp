#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int pos;
        if(n==1||n==2){
            pos =-1;
        }else if(n%2==1){
            pos=2;
        }else if(n%4==0){
            pos=3;
        }else if(n%4==2){
            pos = 4;
        }
        printf("%d\n",pos);
        
    }
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> f(8,0);
    vector<int> g(8,0);
    f[2]=1;
    int index=2;
    for(int j=2;j<=10000;j++)
    {
        if(index%2==0)
        {
            for(int i=2;i<=6;i++)
            {
                g[i]=f[i]+f[i-1]+f[i-2];
            }
        }
        else
        {
            for(int i=2;i<=6;i++)
            {
                f[i]=g[i]+g[i-1]+g[i-2];
            }
        }
        index++;
    }

    while (cin >> n) { // 注意 while 处理多个 case
        int ret=-1;
        vector<int>& tmp=(n%2==0?g:f);
        for(int i=2;i<=6;i++)
        {
            if(tmp[i]%2==0)
            {
                ret=i;
                break;
            }
        }
        if(n==1||n==2)cout<<-1<<endl;
        else cout<<ret-1<<endl;
    }
}
// 64 位输出请用 printf("%lld")
// 64 位输出请用 printf("%lld")