class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int c=nums.size()-1;
        set<vector<int>> ret;
        while(c>=2)
        {
            int a=0;
            int b=c-1;
            while(a<b)
            {
                if(nums[a]+nums[b]>-nums[c])
                {
                    int tmpb=nums[b];
                    while(a<b&&tmpb==nums[b])b--;
                }
                else if(nums[a]+nums[b]<-nums[c])
                {
                    int tmpa=nums[a];
                    while(a<b&&tmpa==nums[a])a++;
                }
                else{
                    ret.insert({nums[a],nums[b],nums[c]});
                    int tmpb=nums[b];
                    while(a<b&&tmpb==nums[b])b--;
                    int tmpa=nums[a];
                    while(a<b&&tmpa==nums[a])a++;
                }
            }
            int tmpc=nums[c];
            while(c>=2&&tmpc==nums[c])c--;
        }
        return vector<vector<int>>{ret.begin(),ret.end()};

    }
};