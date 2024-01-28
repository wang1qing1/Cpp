class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
    int N;
    void dfs(int i,int k)
    {
        if(path.size()==k)
        {
            ret.push_back(path);
            return ;
        }
        for(int j=i;j<=N;j++)
        {
            path.push_back(j);
            dfs(j+1,k);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        N=n;
        dfs(1,k);
        return ret;
    }
};
};