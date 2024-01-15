class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,set<char>> hashs;
        map<char,set<char>> hasht;
        for(int i=0;i<s.size();i++)
        {   
            hashs[s[i]].insert(t[i]);
            hasht[t[i]].insert(s[i]);
        }
        for(auto [a,b]:hasht)
        {
            if(b.size()!=1) return false;
        }
        for(auto [a,b]:hashs)
        {
            if(b.size()!=1) return false;
        }
        return true;
    }
};