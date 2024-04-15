class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numFruits int整型 
     * @param prerequisites int整型vector<vector<>> 
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> ret;
    vector<int> path;
    set<int> pathhash;
    void Find(vector<int>& r,map<int,set<int>>& hash,int tar)
    {
        for(auto &[a,b]:hash)
        {
            if(b.find(tar)!=b.end())
            {
                r.push_back(a);
            }
        }
    }
    void dfs(map<int,set<int>>& hash,int n,int begin)
    {
        if(path.size()==n)
        {
            ret.push_back(path);
        }
        if(begin>=n)return;
        for(int i=0;i<n;i++)
        {
            if(pathhash.find(i)==pathhash.end()&&hash[i].size()==0)
            {
                path.push_back(i);pathhash.insert(i);
                vector<int>r;
                Find(r,hash,i);
                for(auto e:r)hash[e].erase(i);
                dfs(hash,n,begin+1);
                path.pop_back();pathhash.erase(i);
                for(auto e:r)hash[e].insert(i);
            }
        }
    }
    vector<vector<int> > findFruitOrder(int n, vector<vector<int> >& pre) {
        map<int,set<int>> hash;
        for(auto &v:pre)
        {
            hash[v[0]].insert(v[1]);
        }
        dfs(hash,n,0);
        return ret;


    }
};