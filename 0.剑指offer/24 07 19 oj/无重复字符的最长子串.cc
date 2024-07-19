class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        unordered_map<char,int> hash;//对应字符和下标
        int ret=0;
        while(right<s.size())
        {
            if(hash.find(s[right])==hash.end())
            {
                hash[s[right]]=right;
                right++;
            }
            else
            {
                int index=hash[s[right]];
                for(int i=left;i<=index;i++)
                {
                    hash.erase(s[i]);
                }
                hash[s[right]]=right;
                right++;
                left=index+1;
            }
            ret=max(ret,(int)hash.size());
        }
        return ret;
    }
};