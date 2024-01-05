class Solution {
public:
    int longestPalindrome(string& s) {
        unordered_map<char,int> hash;
        for(auto e:s)hash[e]++;
        int ret=0;
        for(auto [ch,count]:hash)
        {
            ret+=count/2*2;
        }
        return ret==s.size()?ret:ret+1;
    }
};