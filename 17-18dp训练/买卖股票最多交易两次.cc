class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n=prices.size();
        k=min(k,n/2);
        //创建dp表
        vector<vector<int>> f(n+1,vector<int>(k+1,-0x3f3f3f3f));//买入
        vector<vector<int>> g(n+1,vector<int>(k+1,-0x3f3f3f3f));//卖出

        //初始化
        f[0][0]=-prices[0];
        g[0][0]=0;

        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<=k;j++)
            {
                f[i][j]=max(f[i-1][j],g[i-1][j]-prices[i-1]);
                g[i][j]=g[i-1][j];
                if(j-1>=0)
                {
                    g[i][j]=max(g[i][j],f[i-1][j-1]+prices[i-1]);
                }
            }
        }
        int ret=g[n][0];
       for(int i=1;i<=k;i++)
       {
           if(ret<g[n][i])
                ret=g[n][i];
       }
       return ret;
    }
};