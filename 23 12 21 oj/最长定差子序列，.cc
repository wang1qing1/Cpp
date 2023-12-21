class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();

        map<int,int> hash;//[arr[i],dp[i]]
        hash[arr[0]]=1;
        int ret=1;
        for(int i=1;i<n;i++)
        {
            hash[arr[i]]=hash[arr[i]-difference]+1;
            ret=max(ret,hash[arr[i]]);
        }
        return ret;
    }
};