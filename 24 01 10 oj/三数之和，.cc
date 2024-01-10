//接近超时，超内存
class Solution {
public:
    set<vector<int>> vv;
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vv.clear();
        for(int i=0;i<n;i++)
        {
            int left=i;int right=n-1;
            int tar=-nums[i];
            if(tar<nums[i]) return vector<vector<int>>(vv.begin(),vv.end());
            // if(tar<nums[i]) return vv;
            while(left<right)
            {
                if(nums[left]+nums[right]<tar)left++;
                else if(nums[left]+nums[right]>tar)right--;
                else
                {
                    
                    if(left!=i&&right!=i) vv.insert({nums[left],nums[right],nums[i]});
                    // if(left!=i&&right!=i&&nums[i]!=nums[i-1]) vv.push_back({nums[left],nums[right],nums[i]});
                    left++;
                }
            }
        }
       return vector<vector<int>>(vv.begin(),vv.end());
    }
};

//优化后
class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> vv;
        int i=0;
        while(i<n)
        {
            int left=i+1;int right=n-1;
            int tar=-nums[i];
            // if(tar<nums[i]) return vector<vector<int>>(vv.begin(),vv.end());
            if(tar<nums[i]) return vv;
            while(left<right)
            {
                if(nums[left]+nums[right]<tar)left++;
                else if(nums[left]+nums[right]>tar)right--;
                else
                {
                    // if(left!=i&&right!=i) vv.insert({nums[left],nums[right],nums[i]});
                    vv.push_back({nums[left],nums[right],nums[i]});
                    left++;right--;
                    while(left<right&&nums[left]==nums[left-1])left++;
                    while(left<right&&nums[right]==nums[right+1])right--;
                }
            }
            i++;
            while(i<n&&nums[i]==nums[i-1])i++;
        }
       return vv;
    }
};