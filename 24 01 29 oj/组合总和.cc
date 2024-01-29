class Solution {
public:
    vector<int> path;
    long long sum = 0;
    vector<vector<int>> ret;
    //begin 作用，当从begin开始一次dfs，begin之前的不用访问，如果
    void dfs(vector<int>& candidates, int target,int begin) {
        if (sum == target) {
            ret.push_back(path);
            return;
        } else if (sum > target)
            return;
        for (int i = begin; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            dfs(candidates, target,i);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sum = 0;
        dfs(candidates, target,0);
        return ret;
    }
};


