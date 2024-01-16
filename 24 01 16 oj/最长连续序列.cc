class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        set<int> hash(nums.begin(),nums.end());
        int count=1;
        int ret=1;
        auto it=hash.begin();
        auto itend=--hash.end();
        while(it!=itend)
        {
            int a=*it;
            cout<<a<<" ";
            int b=*(++it);
            cout<<b<<" ";
            if(a+1==b)count++;
            else
            {
                ret=max(ret,count);
                count=1;
            }
        }
        return max(ret,count);
    }
};