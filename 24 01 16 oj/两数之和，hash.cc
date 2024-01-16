class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int>> hash;//<num,index>
        for (int i = 0; i < nums.size(); i++)hash[nums[i]].push_back(i);
        sort(nums.begin(), nums.end());
        int left = 0; int right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] > target)right--;
            else if (nums[left] + nums[right] < target)left++;
            else break;
        }
        int a = nums[left];
        int b = nums[right];
        if (a != b)
        {
            return { hash[a][0],hash[b][0] };
        }
        else
        {
            return { hash[a][0],hash[b][1] };
        }
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret(2);
        unordered_map<int,int> hash;
        //边遍历边利用hash表查询 target-cur ,避免之重复
        for(int i=0;i<nums.size();i++)
        {
            int cur=nums[i];
            if(hash.find(target-cur)!=hash.end())//第一次找到
            {
                ret[0]=hash[target-cur];
                ret[1]=i;
                break;
            }
            hash[cur]=i;
        } 
        return ret;
    }
};