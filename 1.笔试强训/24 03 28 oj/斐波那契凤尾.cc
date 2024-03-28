#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> dp(100001); 
    dp[1]=1;dp[2]=2;
    int flag=-1;
    for(int i=3;i<=100000;i++)
    {
        long long next=dp[i-1]+dp[i-2];
        if(flag==-1&&next>=1000000)
        {
            flag=i;
        }
        dp[i]=next%1000000;
    }
    while (cin >>n) { // 注意 while 处理多个 case
        int f=dp[n];
        if (n >= flag) {
        printf("%6d\n", f);
        } else {
        printf("%d\n", f);
        }
    }
}
// 64 位输出请用 printf(\"%lld\")