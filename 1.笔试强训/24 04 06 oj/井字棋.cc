class Board {
public:
    int arr[4][2][2]={
        {{0,-1},{0,1}},{{-1,0},{1,0}},{{-1,-1},{1,1}},{{-1,1},{1,-1}}
    };
    bool checkWon(vector<vector<int>> board) {
        int ret=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i][j])
                {
                    //四个方向
                    for(int t=0;t<4;t++)
                    {
                        //两个小方向
                        int sum=0;
                        for(int g=0;g<2;g++)
                        {
                            int x=i;
                            int y=j;
                            while(x<3&&y<3&&x>=0&&y>=0)
                            {
                                sum+=board[x][y];
                                x+=arr[t][g][0];
                                y+=arr[t][g][1];
                            }
                        }
                        sum-=board[i][j];
                        if(sum==3||sum==-3)ret=sum;
                    }
                }
                
            }
        }
        return ret==3;


    }
};