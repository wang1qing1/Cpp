#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<long long> arr(n+1);
        for(int i=1;i<=n;i++)cin>>arr[i];
        
        vector<long long> f(n+1,0);//f[i]不拿i位置数时的最大不相邻数和
        vector<long long> g(n+1,0);//g[i]拿i位置数时的最大不相邻数和
        
        for(int i=1;i<=n;i++)
        {
            g[i]=f[i-1]+arr[i];
            f[i]=max(g[i-1],f[i-1]);           
        }
        cout<<max(g[n],f[n])<<endl;
    }
}
// 64 位输出请用 printf("%lld")