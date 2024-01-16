class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string,vector<string>> hash;
        for(auto &str:strs)
        {
            string tmp=str;
            sort(tmp.begin(),tmp.end());
            hash[tmp].push_back(str);
        }
        for(auto&[a,vv]:hash)
        {
            ret.push_back(vv);
        }
        return ret;
    }
};