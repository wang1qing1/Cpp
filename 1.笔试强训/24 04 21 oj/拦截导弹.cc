#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> arr(n);
        for(auto& e:arr)cin>>e;
        // Q1：dp最长递增子序列
         //Q2:最少递减子序列个数等于递增子序列的长度
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        int ret1=1;
        int ret2=1;
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(arr[i]<=arr[j]) dp1[i]=max(dp1[j]+1,dp1[i]);
                if(arr[i]>arr[j]) dp2[i]=max(dp2[j]+1,dp2[i]);
            }
            ret1=max(ret1,dp1[i]);
            ret2=max(ret2,dp2[i]);
        }
       cout<<ret1<<endl<<ret2<<endl;
    }
}
