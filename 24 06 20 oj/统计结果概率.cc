class Solution {
public:
    vector<double> statisticsProbability(int num) {
        int n=num;
        int x=num*6;
       
        int p=pow(6,num); //一共的组合数
        //dp[n][x]代表n个色子时,点数时x的情况个数
        vector<vector<int>> dp(n+1,vector<int>(x+1));
        for(int i=1;i<=6;i++)dp[1][i]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i*6;j++)
            {
                if(j<i)dp[i][j]=0;
                else
                {
                    //dp[n][x]=dp[n-1][x-1]+dp[n-1][x-2]+dp[n-1][x-3]+dp[n-1][x-4]...dp[n-1][x-1];
                    //代表n个色子时,点数时x的情况个数，可以有n-1色子,点数为x-k,第n个色子，点数为k组合成
                    for(int k=1;k<=6;k++)
                    {
                        if(j-k>0) dp[i][j]+=dp[i-1][j-k];
                    }
                }
            }
        }
        vector<double> ret;
        for(int i=1;i<=x;i++)
        {
            if(dp[num][i])ret.push_back(dp[num][i]*1.0/p);
        }
        return ret;
    }
};