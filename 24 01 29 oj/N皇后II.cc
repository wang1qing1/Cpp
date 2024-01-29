class Solution {
public:
    bool col[10]={0};
    bool xy1[20]={0};//主对角线y=-x+b;
    bool xy2[20]={0};//副对角线y=x+b;
    int ret;
    vector<string> path;
    void dfs(int row,int n)
    {
        if(row==n)
        {
            ret++;
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(!col[i]&&!xy1[i+row]&&!xy2[i-row+n])
            {
                col[i]=xy1[i+row]=xy2[i-row+n]=true;
                path[row][i]='Q';
                dfs(row+1,n);
                col[i]=xy1[i+row]=xy2[i-row+n]=false;
                path[row][i]='.';
            }
        }
    }
    int totalNQueens(int n) {
        path.resize(n,string(n,'.'));
        dfs(0,n);
        return ret;
    }
};