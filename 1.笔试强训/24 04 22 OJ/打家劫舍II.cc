#include <iostream>
#include <vector>
using namespace std;

long long GetMax(const vector<long long>& arr,int n)
{
        vector<long long> f(n+1,0);//f[i]不拿i位置数时的最大不相邻数和
        vector<long long> g(n+1,0);//g[i]拿i位置数时的最大不相邻数和
        
        for(int i=1;i<=n;i++)
        {
            g[i]=f[i-1]+arr[i-1];
            f[i]=max(g[i-1],f[i-1]);           
        }
        return max(g[n],f[n]);
}

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
    vector<long long> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int ret1=GetMax(vector<long long>(arr.begin(),arr.end()-1),n-1);
    int ret2=GetMax(vector<long long>(arr.begin()+1,arr.end()),n-1);
    cout<<max(ret1,ret2)<<endl;
    }
}
// 64 位输出请用 printf("%lld")