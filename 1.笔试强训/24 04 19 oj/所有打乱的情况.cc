class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param original int整型vector 
     * @return int整型vector<vector<>>
     */
    set<vector<int>> ret;
    vector<int> path;
    set<int> hash;
    void dfs(vector<int>& original,int begin)
    {
        if(path.size()==original.size())
        {
            ret.insert(path);
        }
        if(begin>=original.size())return;
        for(int i=0;i<original.size();i++)
        {
            if(hash.find(original[i])==hash.end())
            {
                path.push_back(original[i]);
                hash.insert(original[i]);
                dfs(original,begin+1);
                hash.erase(path.back());
                path.pop_back();
            }
        }
    }
    vector<vector<int>> getAllShuffles(vector<int>& original) {
       dfs(original,0);
       return vector<vector<int>>(ret.begin(),ret.end());
    }
};