#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> arr(n);
        int sum=0;
        for(auto& e:arr)
        {   
            cin>>e;
            sum+=e;
        }
        vector<int> dpmax(n);
        vector<int> dpmin(n);
        dpmax[0]=dpmin[0]=arr[0];
        int retmax=arr[0];
        int retmin=arr[0];
        for(int i=1;i<n;i++)
        {
            dpmin[i]=min(arr[i],arr[i]+dpmin[i-1]);
            dpmax[i]=max(arr[i],arr[i]+dpmax[i-1]);
            retmax=max(retmax,dpmax[i]);
            retmin=min(retmin,dpmin[i]);
        }
        //全部都是负数
        if(retmin!=sum)cout<<(retmax>sum-retmin?retmax:sum-retmin)<<endl;
        else cout<<retmax<<endl;
    }
}
// 64 位输出请用 printf("%lld")