#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
using namespace std;

void getnum(int num,vector<int>& arr)
{
    for(int i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)
        {
            arr.push_back(i);
            if(num/i!=i)arr.push_back(num/i);
        }
    }
};

int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        vector<int> dp(b+1,0x3f3f3f3f);
        dp[a]=0;
        for(int i=a;i<=b;i++)
        {
            vector<int> arr;
            getnum(i,arr);
            for(int j=0;j<arr.size();j++)
            {
                if(i+arr[j]<=b)
                {
                    dp[arr[j]+i]=min(dp[i]+1,dp[arr[j]+i]);
                }
            }
        }
        cout<<(dp[b]==0x3f3f3f3f?-1:dp[b])<<endl;
    }
}
// 64 位输出请用 printf("%lld")