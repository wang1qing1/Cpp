#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        map<int,int> hash;
        int m=0;
        for(int i=0;i<n;i++)
        {
            int e;cin>>e;
            m=max(m,e);
            hash[e]++;
        }
        //题目分析:选取a[i]位置数据，那么a[i]+1,a[i]-1就不能选取，类似于打家劫舍问题，区别在于打家劫舍问题
        //位置相邻，这里的是数据相邻,分析模式是一样的
        vector<int> f(m+1,0);
        vector<int> g(m+1,0);
        for(int i=1;i<=m;i++)
        {
            f[i]=i*hash[i]+g[i-1];
            g[i]=max(g[i-1],f[i-1]);
        }
        cout<<max(f[m],g[m])<<endl;
    }
}
