class Solution {
public:
    bool wordPattern(string& pattern, string& s) {
        stringstream sstr(s);
        vector<string> vv;
        string str;
        while(sstr>>str)
        {
            vv.push_back(str);
        }
        if(pattern.size()!=vv.size())return false;
        map<char,set<string>> hash;
        map<string,set<char>> hash2;
        for(int i=0;i<pattern.size();i++)
        {
            hash[pattern[i]].insert(vv[i]);
            hash2[vv[i]].insert(pattern[i]);
        }
        for(auto &[a,b]:hash)
        {
            if(b.size()!=1)return false;
        }
        for(auto &[a,b]:hash2)
        {
            if(b.size()!=1)return false;
        }
        return true;
    }
};