class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) {
        int left=0;
        int right=price.size()-1;
        while(left<right)
        {
            if(price[left]+price[right]>target)right--;
            else if(price[left]+price[right]<target)left++;
            else break;
        }
        return {price[left],price[right]};

    }
};