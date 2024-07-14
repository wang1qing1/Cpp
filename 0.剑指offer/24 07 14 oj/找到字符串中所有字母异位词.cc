class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int left=0;
        int right=p.size();
        unordered_map<char,int> hashp;
        for(auto e:p)hashp[e]++;
        unordered_map<char,int> hashs;
        for(int i=0;i<p.size();i++)hashs[s[i]]++;
        while(right<s.size())
        {
            if(hashp==hashs)ret.push_back(left);
            hashs[s[left]]--;
            if(hashs[s[left]]==0)hashs.erase(s[left]);
            left++;
            hashs[s[right]]++;
            right++;
        }
        if(hashp==hashs)ret.push_back(left);
        return ret;
    }
};