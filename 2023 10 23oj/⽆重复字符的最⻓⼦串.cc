class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0;
        int right=-1;
        unordered_set<char> hash;
        int len=-1;
        while(right<n)
        {
            right++;
            if(hash.find(s[right])==hash.end())
            {
                hash.insert(s[right]);
            }
            else
            {
                len=max(len,right-left);
                while(s[left]!=s[right])
                {
                    hash.erase(s[left]);
                    left++;
                }
                left++;
            }
        }
        len=max(right-left,len);
        return len;
    }
};