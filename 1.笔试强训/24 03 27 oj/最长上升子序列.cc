#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >>n) { // 注意 while 处理多个 case
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        vector<int> dp(n);
        dp[0]=1;
        int ret=1;
        for(int i=1;i<arr.size();i++)
        {
            int maxnum=0;
            for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j])
                {
                    maxnum=max(maxnum,dp[j]);
                }
            }
            dp[i]=maxnum+1;
            ret=max(ret,dp[i]);
        }
        cout<<ret<<endl;
    }
}
// 64 位输出请用 printf(\"%lld\")