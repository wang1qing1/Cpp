class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char,int> smap;
        for(auto e:s)smap[e]++;
        unordered_map<char,int> tmap;
        for(auto e:t)tmap[e]++;
        return smap==tmap&&s!=t;
    }
};