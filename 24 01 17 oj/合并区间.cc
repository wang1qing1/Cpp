class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int left=intervals[0][0];
        int right=intervals[0][1];
        int cur=1;
        vector<vector<int>> ret;
        while(cur<intervals.size())
        {
            if(intervals[cur][0]<=right)//有重合
            {
                right=max(intervals[cur][1],right);
            }
            else
            {
                ret.push_back({left,right});
                left=intervals[cur][0];
                right=intervals[cur][1];
            }
            cur++;
        }
        ret.push_back({left,right});
        return ret;
    }
};