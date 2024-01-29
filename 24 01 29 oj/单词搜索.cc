
class Solution {
public:
    string Word;
    int xi[4]={0,0,-1,1};
    int yi[4]={1,-1,0,0};
    typedef pair<int,int> PII;
    bool dfs(PII xy,vector<vector<char>>& board,int index)
    {
        if(index==Word.size())
        {
            return true;
        }
        auto [a,b]=xy;
        for(int i=0;i<4;i++)
        {
            int x=a+xi[i];
            int y=b+yi[i];
            if(x>=0&&x<board.size()&&y>=0&&y<board[0].size()&&board[x][y]==Word[index])
            {
                board[x][y]='.';
                if(dfs(PII({x,y}),board,index+1)) return true;
                board[x][y]=Word[index];
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int ret=false;
        Word=word;
        int n=board.size();
        int m=board[0].size();
        if(n*m<word.size())return false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    int tmp=board[i][j];
                    board[i][j]='.';
                    if(dfs({i,j},board,1))return true;
                    board[i][j]=tmp;
                } 
            }
        }          
        return false;
    }
};

class Solution {
public:
    typedef pair<int,int> PII;
    int x[4]={0,0,1,-1};
    int y[4]={1,-1,0,0};
    int n;
    int m;
    string path;
    vector<vector<char>> chack;
    bool dfs(vector<vector<char>>& board,PII xy,string& word,int index)
    {
        auto [a,b]=xy;
        if(path.size()==word.size()&&path==word)
        {          
            return true;
        }  
        for(int i=0;i<4;i++)
        {
            int x1=a+x[i];
            int y1=b+y[i];
            if(x1>=0&&y1>=0&&x1<n&&y1<m&&chack[x1][y1]!='.'&&word[index]==board[x1][y1]) 
            {
                chack[x1][y1]='.';
                path+=board[x1][y1];
                if(dfs(board,{x1,y1},word,index+1))return true;
                path.pop_back();
                chack[x1][y1]='*';
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string& word) {
        chack=board;
        n=board.size(); 
        m=board[0].size(); 
        if(n*m<word.size())return false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    path=board[i][j];
                    chack[i][j]='.';
                    if(dfs(board,{i,j},word,1))return true;
                    chack[i][j]='*';
                }
            }
        }
        return false;
    }
};

