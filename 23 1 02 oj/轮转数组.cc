class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp=nums;
        for(auto e:nums)tmp.push_back(e);
        nums=vector<int>(tmp.begin()+(nums.size()-k%nums.size()),tmp.begin()-k%nums.size()+2*nums.size());
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) { 
        int left=nums.size()-k%nums.size();
        reverse(nums.begin(),nums.begin()+left);
        reverse(nums.begin()+left,nums.begin()+left+k%nums.size());
        reverse(nums.begin(),nums.end());
    }
};