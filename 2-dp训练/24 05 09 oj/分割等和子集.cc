#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> arr(n);
        int sum=0;
        for(auto &e:arr)
        {
            cin>>e;
            sum+=e;
        }
        if(sum%2==1)
        {
            cout<<"false"<<endl;
            return 0;
        }
        int m=sum/2;
        vector<bool> dp(m+1,true);
        for(int i=1;i<=n;i++)
        {
            for(int j=m;j>=1;j--)
            {
                if(j-arr[i]>=0)dp[j]=dp[j]||dp[j-arr[i-1]];
            }
        }
        if(dp[m])cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
}
// 64 位输出请用 printf("%lld")