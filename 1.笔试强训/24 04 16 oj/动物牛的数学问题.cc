class Solution {
public:
    typedef  pair<int,int> PII;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<PII> index;
        for(int i=0;i<nums.size();i++)index.push_back({nums[i],i});    

        sort(index.begin(),index.end(),[](const PII& e1,const PII& e2){
            return e1.first<e2.first;
        });
        int left=0;int right=index.size()-1;
        vector<int> ret;
        while(left<right)
        {
            auto [a1,b1]=index[left];
            auto [a2,b2]=index[right];
            if(a1+a2<target)
            {
                left++;
            }
            else if(a1+a2>target)
            {
                right--;
            }
            else {
                 ret.push_back(b1);
                 ret.push_back(b2);
                 break;
            }
        }
        return ret;
    }
};