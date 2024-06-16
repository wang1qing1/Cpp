class Solution {
public:
    set<string> ret;
    string path;
    map<char,int>std;
    map<char,int>hash;
    void dfs(const string& str)
    {
        if(path.size()==str.size())
        {
            ret.insert(path);
            return;
        }
        for(auto e:str)
        {
            if(hash[e]<std[e])
            {
                path+=e;
                hash[e]++;
                dfs(str);
                hash[e]--;
                if(hash[e]==0)hash.erase(e);
                path.pop_back();
            }
        }
    }
    vector<string> goodsOrder(string goods) {
        for(auto e:goods)std[e]++;
        dfs(goods);
        return vector<string>(ret.begin(),ret.end());
    }
};

// abcde
class Solution {
public:
    vector<string> ret;
    string path;
    unordered_map<char,int>std;
    unordered_map<char,int>hash;
    void dfs(const string& str)
    {
        if(path.size()==str.size())
        {
            ret.push_back(path);
            return;
        }
        for(int i=0;i<str.size();i++)
        {
            char e=str[i];
            if(hash[e]<std[e]&&(i==0||str[i]!=str[i-1]))
            {
                path+=e;
                hash[e]++;
                dfs(str);
                hash[e]--;
                path.pop_back();
            }
        }
    }
    vector<string> goodsOrder(string goods) {
        for(auto e:goods)std[e]++;
        sort(goods.begin(),goods.end());
        dfs(goods);
        return ret;
    }
};

// aabcd  a
// aabcd  a
// aabcd  b
// aabcd  
// aabcd