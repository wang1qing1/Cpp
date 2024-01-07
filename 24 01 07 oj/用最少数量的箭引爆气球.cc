class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        int minback=points[0].back();
        int ret=1;
        for(int i=1;i<n;i++)
        {
            if(points[i][0]<=minback)//有重叠
            {
                minback=min(minback,points[i][1]);
            }
            else
            {
                minback=points[i][1];
                ret++;
            }
        }
        return ret;
    }
};