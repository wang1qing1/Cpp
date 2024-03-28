#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        vector<uint64_t> dp(b+1);
        uint64_t sum=0;
        for(int i=1;i<=b;i++)
        {
            if(i<=2)
            {
                dp[i]=1;
            }
            else
            {
                dp[i]=dp[i-1]+dp[i-2];
            } 
            if(i>=a&&i<=b)sum+=dp[i];   
        }
        cout<<sum<<endl;
    }
}
// 64 位输出请用 printf(\"%lld\")