class Solution {
public:
    vector<int> path;
    vector<vector<int>> ret;
    int sumk;
    void dfs(int n,int index)
    {   
        if(index>n)return ;
        for(int i=index;i<=n;i++)
        {
            path.push_back(i);
            if(path.size()==sumk)
            {
                ret.push_back(path);
            }
            dfs(n,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        sumk=k;
        dfs(n,1);
        return ret;

    }
};