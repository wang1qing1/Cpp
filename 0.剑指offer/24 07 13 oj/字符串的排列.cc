class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        unordered_map<char,int> hashs1;
        for(auto e:s1)hashs1[e]++;
        int left=0;
        int right=s1.size()-1;
        unordered_map<char,int> hashs2;
        for(int i=0;i<s1.size();i++)hashs2[s2[i]]++;
        //[left,right]都是闭区间
        while(right<s2.size())
        {
            if(hashs1==hashs2)return true;
            hashs2[s2[left]]--;
            if(hashs2[s2[left]]==0)hashs2.erase(s2[left]);
            left++;
            right++;
            hashs2[s2[right]]++;
        }
        if(hashs1==hashs2)return true;
        return false;
    }
};