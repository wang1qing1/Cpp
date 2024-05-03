#include <iostream>
#include <vector>
using namespace std;

//dp:超时
//dp[i]:到达i位置的最小跳数
// int main() {
//     int n;
//     while (cin >> n) { // 注意 while 处理多个 case
//         vector<int> arr(n);
//         for(auto &e:arr)cin>>e;
//         vector<int> dp(n);
//         dp[0]=0;
//         for(int i=1;i<n;i++)
//         {
//             int tmp=0x3f3f3f3f;
//             for(int j=i-1;j>=0;j--)
//             {
//                 if(dp[j]!=0x3f3f3f3f&&arr[j]+j>=i)
//                 {
//                     tmp=min(tmp,dp[j]);
//                 }
//             }
//             if(tmp!=0x3f3f3f3f)dp[i]=tmp+1;
//             else dp[i]=0x3f3f3f3f;
//         }
//         if(dp[n-1]==0x3f3f3f3f)cout<<-1<<endl;
//         else cout<<dp[n-1]<<endl;
//     }
// }
// 64 位输出请用 printf("%lld")

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> arr(n);
        for(auto &e:arr)cin>>e;
        int ret=0;
        int left=0,right=0;
        while(left<=right)
        {
            if(right>=n-1)break;
            int tmp=0;
            //寻找下一跳能够到达的最远距离
            for(int i=left;i<=right;i++)
            {
                tmp=max(tmp,arr[i]+i);
            }
            //下一跳到达的最近距离
            left=right+1;
            right=tmp;
            ret++;
        }  
        if(left>right)cout<<-1<<endl;
        else cout<<ret<<endl;

    }
}
