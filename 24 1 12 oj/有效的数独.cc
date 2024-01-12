class Solution {
public:
    bool x[9][10]={false};//0~9某一x轴上出现了什么数字
    bool y[9][10]={false};//0~9某一y轴上出现了什么数字
    bool xy[3][3][10]={false};//[i/3,j/3]九宫格内的，出现了什么数字
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]!='.')
                {
                    int num=board[i][j]-'0';
                    if(x[i][num]||y[j][num]||xy[i/3][j/3][num])
                    {
                        return false;
                    }
                    else x[i][num]=y[j][num]=xy[i/3][j/3][num]=true;
                }
            }
        }
        return true;
    }

};