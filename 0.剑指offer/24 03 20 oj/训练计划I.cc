class Solution {
public:
    vector<int> trainingPlan(vector<int>& actions) {
        int left=0;
        int right=actions.size()-1;
        while(left<right)
        {
            while(left<right&&actions[left]%2!=0)left++;
            while(left<right&&actions[right]%2!=1)right--;
            if(left<right)swap(actions[left],actions[right]);
        }
        return actions;
    }
};