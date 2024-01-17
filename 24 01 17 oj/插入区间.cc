class Solution {
public:
     vector<vector<int>> merge(vector<vector<int>>& intervals) {
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty())
        {
            intervals.push_back(newInterval);
        }
        int i=0;
        for(i=0;i<intervals.size();i++)
        {
            if(intervals[i][0]>=newInterval[0])
            {
                intervals.insert(i+intervals.begin(),newInterval);
                break;
            }
        }
        if(i==intervals.size()) intervals.push_back(newInterval);
        return merge(intervals);
    }
};