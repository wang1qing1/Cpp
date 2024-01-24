class Solution {
public:
    typedef pair<int,int> PII;
    vector<vector<char>> chack;
    int x[4]={0,0,1,-1};
    int y[4]={1,-1,0,0};
    int n;
    int m;
    void _solve(vector<vector<char>>& chack,queue<PII>& q,int a,int b)
    {
        q.push({a,b});
        chack[a][b]='X';
        while(!q.empty())
        {
            auto [i,j]=q.front();
            q.pop();
            for(int t=0;t<4;t++)
            {
                if(i+x[t]>=0&&i+x[t]<n&&j+y[t]>=0&&j+y[t]<m&&chack[i+x[t]][j+y[t]]=='O')
                {
                    q.push({i+x[t],j+y[t]});
                    chack[i+x[t]][j+y[t]]='X';
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        chack=board;
        queue<PII> q;
        for(int i=0;i<n;i++) 
        {
            if(chack[i][0]=='O')
            {
                _solve(chack,q,i,0);
            }
        }
        for(int i=0;i<n;i++) 
        {
            if(chack[i][m-1]=='O')
            {
                _solve(chack,q,i,m-1);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(chack[0][i]=='O')
            {
                _solve(chack,q,0,i);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(chack[n-1][i]=='O')
            {
                _solve(chack,q,n-1,i);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(chack[i][j]=='O')board[i][j]='X';
            }
        }
    }
};