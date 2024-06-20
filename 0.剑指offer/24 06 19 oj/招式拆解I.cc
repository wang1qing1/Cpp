class Solution {
public:
    int dismantlingAction(string arr) {
        int n=arr.size();
        unordered_set<char> hash;
        int left=0;
        int right=0;
        size_t ret=0;
        while(right<n)
        {
            if(hash.find(arr[right])==hash.end())
            {
                hash.insert(arr[right]);
                right++;
            }
            else
            {
                while(arr[left]!=arr[right])
                {
                    hash.erase(arr[left]);
                    left++;
                }
                hash.erase(arr[left++]);
            }
            ret=max(ret,hash.size());
        }
        return ret;
    }
};