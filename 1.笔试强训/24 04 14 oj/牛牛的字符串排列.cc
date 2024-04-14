class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @param k int整型 
     * @return string字符串vector
     */
    set<string> ret;
    string path;
    map<char,int> hash;
    map<char,int> chick;
    void dfs(string &s)
    {
        if(path.size()==s.size())
        {
            ret.insert(path);
        }
        if(path.size()==s.size())return;
        for(int i=0;i<s.size();i++)
        {
            if(hash[s[i]]<chick[s[i]])
            {
                path+=s[i];
                hash[s[i]]++;
                dfs(s);
                path.pop_back();
                hash[s[i]]--;
            }
       }

    }
    vector<string> getPermutation(string s, int k) {
        for(auto e:s)chick[e]++;
        int n=s.size();
        dfs(s);
        vector<string> vv;
        int i=0;
        for(auto &str:ret)
        {
            vv.push_back(str);i++;
            if(i==k)break;
        }
        hash.clear();path.clear();
        return vv;
    }
};