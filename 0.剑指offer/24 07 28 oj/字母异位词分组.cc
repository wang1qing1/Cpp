class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<string,vector<int>> hash;
        for(int i=0;i<strs.size();i++)
        {
            string str=strs[i];
            sort(str.begin(),str.end());
            hash[str].push_back(i);
        }
        for(auto &[str,num]:hash)
        {
            vector<string> tmp;
            for(auto i:num)tmp.push_back(strs[i]);
            ret.push_back(tmp);
        }
        return ret;
        
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<map<char,int>,vector<int>> hash;
        int index=0;
        for(int i=0;i<strs.size();i++)
        {
            map<char,int> strmap;
            for(auto e:strs[i]) strmap[e]++;
            hash[strmap].push_back(i);
        }
        for(auto &[mapv,v]:hash)
        {
            vector<string> tmp;
            for(auto e:v)tmp.push_back(strs[e]);
            ret.push_back(tmp);
        }
        return ret;
    }
};