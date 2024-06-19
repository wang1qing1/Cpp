class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        int n=array.size();
        vector<int> dp(n);
        dp[0]=array[0];
        int ret=array[0];
        int l=0;int r=0;
        int b=0;int e=0;
        for(int i=1;i<n;i++)
        {
            r=i;
            if(array[i]>array[i]+dp[i-1])
            {
                dp[i]=array[i];
                l=i;
            }
            else
            {
                dp[i]=array[i]+dp[i-1];
            }
            if(dp[i]>ret||(dp[i]==ret)&&(r-l)>(e-b))
            {
                ret=dp[i];
                b=l;
                e=r;
            }
        }
        return vector<int>(array.begin()+b,array.begin()+e+1); 
    }
};