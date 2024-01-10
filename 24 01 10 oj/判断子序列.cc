class Solution {
public:
    bool isSubsequence(string s, string t) {
        int is=0;
        for(auto e:t)
        {
            if(e==s[is])is++;
        }
        return is==s.size();
    }
};