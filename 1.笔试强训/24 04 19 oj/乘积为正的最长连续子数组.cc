#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> arr(n);
        for(auto& e:arr)cin>>e;
        vector<int> f(n,0);//大于0
        vector<int> g(n,0);//小于0
        if(arr[0]>0)f[0]=1;
        else if(arr[0]<0) g[0]=1;
        int ret=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>0)
            {
                if(f[i-1]>=0)f[i]=f[i-1]+1;
                if(g[i-1]>0)g[i]=g[i-1]+1;
            }
            else if(arr[i]<0)
            {
                if(g[i-1]>0)f[i]=g[i-1]+1;
                if(g[i-1]==0)g[i]=g[i-1]+1;
                if(f[i-1]>0)g[i]=max(g[i],f[i-1]+1);
            }
            else f[i]=g[i]=0;
            ret=max(ret,f[i]);
        } 
        cout<<ret<<endl;
    }
}
