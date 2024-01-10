class Solution {
public:
    int lengthOfLongestSubstring(string& s) {
        int n=s.size();
        if(n==0)return 0;
        unordered_map<char,int> hash;
        int left=0;
        int right=0;
        size_t ret=1;
        while(right<n)
        {
            if(hash.find(s[right])==hash.end())//没有重复
            {
                hash[s[right]]=right;
                right++;
            }
            else//有重复
            {
                ret=max(ret,hash.size());//获取出现的最长无重复子串
                int pos=hash[s[right]];
                while(left<=pos) hash.erase(s[left++]);//将重复之前的字符全部删除
            }
        }
        return max(ret,hash.size());
    }
};