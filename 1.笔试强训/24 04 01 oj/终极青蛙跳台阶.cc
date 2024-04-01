

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:

    long long GetSum(vector<long long>& dp,int begin,int end)
    {
        long long sum=0;
        for(int i=begin;i<=end;i++)sum+=dp[i];
        return sum+1;
    }
    //dp[i]=1+dp[i-1]+dp[i-2]+dp[i-3].....dp[1];
    int jumpFloorII(int number) {
		    int n=number;
            if(n==2)return 2;
        vector<long long> dp(21);
        dp[1]=1;dp[2]=2;dp[3]=4;
        for(int i=4;i<21;i++)
        {
            dp[i]=GetSum(dp,1,i-1);
        }	
        return dp[n];
    }
};







// 64 位输出请用 printf(\"%lld\")