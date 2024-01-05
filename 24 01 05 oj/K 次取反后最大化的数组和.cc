class Solution {
public:
    struct Com
    {
        bool operator()(int e1,int e2)
        {
            return e1<e2;
        }
    };

    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),Com());
        int count=0;
        int Min=0x3f3f3f3f;
        for(auto  e:nums)
        {
            if(e<0)count++;
            if(e>=0)Min=min(Min,e);
        }
        if(count>=k)
        {
            for(int i=0;i<k;i++)
            {
                nums[i]=-nums[i];
                Min=min(Min,nums[i]);
            }
            int sum=0;
            for(auto e:nums)sum+=e;
            return sum;
        }
        else
        {
            for(int i=0;i<count;i++)
            {
                nums[i]=-nums[i];
                Min=min(Min,nums[i]);
            }
            int sum=0;
            for(auto e:nums)sum+=e;
            if((k-count)%2==1)sum-=2*Min;
            return sum;
        }
    }
};