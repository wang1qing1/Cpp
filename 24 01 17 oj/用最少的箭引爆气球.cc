class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty())return 0;
        sort(points.begin(),points.end());
        int left=points[0][0];
        int right=points[0][1];
        int cur=1;
        int ret=1;
        while(cur<points.size())
        {
            if(points[cur][0]<=right)
            {
                left=max(left,points[cur][0]);
                right=min(right,points[cur][1]);
            }
            else
            {
                ret++;
                left=points[cur][0];
                right=points[cur][1];
            }
            cur++;
        }
        return ret;
    }
};