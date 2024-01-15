class Solution {
public:
    int getnum(vector<vector<int>>& dp,int i,int j)
    {
        int ret=0;
        if(i-1>=0&&dp[i-1][j])ret++;
        if(j-1>=0&&dp[i][j-1])ret++;
        if(i-1>=0&&j-1>=0&&dp[i-1][j-1])ret++;
        if(i+1<dp.size()&&dp[i+1][j])ret++;
        if(j+1<dp[0].size()&&dp[i][j+1])ret++;
        if(i+1<dp.size()&&j+1<dp[0].size()&&dp[i+1][j+1])ret++;
        if(i-1>=0&&j+1<dp[0].size()&&dp[i-1][j+1])ret++;
        if(i+1<dp.size()&&j-1>=0&&dp[i+1][j-1])ret++;
        return ret;
    }
    void gameOfLife(vector<vector<int>>& board) 
    {
        
        int n=board.size();
        int m=board[0].size();
        auto vv=board;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int num=getnum(vv,i,j);
                if(num<2||num>3)
                {
                    board[i][j]=0;
                }
                else if(num==3)
                {
                    board[i][j]=1;
                }
            }
        }

    }
};