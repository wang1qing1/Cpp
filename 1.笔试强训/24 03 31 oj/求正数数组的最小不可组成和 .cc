#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
    public:
    int getFirstUnFormedNum(vector<int> arr, int len) {  
        int minum=0x3f3f3f3f;
        int sum=0;
        for(auto e:arr)
        {
            minum=min(minum,e);
            sum+=e;
        }
        //dp[i][j]前i个物品容量位j的时候最多可以装多少
        vector<vector<int>> dp(len+1,vector<int>(sum+1,0));
        for(int i=1;i<=len;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j-arr[i-1]>=0)
                {
                    dp[i][j]=dp[i-1][j-arr[i-1]]+arr[i-1];
                }
                dp[i][j]=max(dp[i-1][j],dp[i][j]);
            }
        }
        int ret=-1;
        for(int i=minum;i<=sum;i++)
        {
            if(dp[len][i]!=i)
            {
                ret=i;
                break;
            }
        }
        if(ret==-1)ret=sum+1;
        return ret;
    }
};
