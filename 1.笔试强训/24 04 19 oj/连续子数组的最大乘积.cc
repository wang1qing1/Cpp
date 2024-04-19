#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> arr(n);
        for(auto& e:arr)cin>>e;
        vector<int> dpmin(n);
        vector<int> dpmax(n);
        dpmax[0]=dpmin[0]=arr[0];
        int ret=arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i]>=0)
            {
                dpmax[i]=max(dpmax[i-1]*arr[i],arr[i]);
                dpmin[i]=min(dpmin[i-1]*arr[i],arr[i]);
            }
            else
            {
                dpmax[i]=max(dpmin[i-1]*arr[i],arr[i]);
                dpmin[i]=min(dpmax[i-1]*arr[i],arr[i]);
            }
            ret=max(ret,dpmax[i]);
        }
        cout<<ret<<endl;
        

    }
}
// 64 位输出请用 printf("%lld")