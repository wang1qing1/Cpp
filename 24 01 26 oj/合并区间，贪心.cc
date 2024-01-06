class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(),intervals.end());
        int left=0;
        int right=0;
        int maxback=intervals[0].back();
        while(right<intervals.size())
        {
            int l=intervals[right][0];
            int r=intervals[right][1];
            if(intervals[right].front()<=maxback)//注意这里maxback此时便合并，边记录的最大边界
            {
                maxback=max(maxback,r);
                right++;
            }
            else
            {
                ret.push_back({intervals[left].front(),maxback});
                left=right;
                maxback=intervals[left].back();
            }
        }
        ret.push_back({intervals[left].front(),maxback});
        return ret;
    }
};


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(),intervals.end());
        int left=0;
        int right=0;
        int maxback=intervals[0].back();
        while(right<intervals.size())
        {
            if(intervals[right].front()<=intervals[left].back())
            {
                maxback=max(maxback,intervals[right].back());
                right++;
            }
            else
            {
                intervals.erase(intervals.begin()+left+1,intervals.begin()+right);
                intervals[left]=vector<int>{intervals[left].front(),maxback};             
                if(right-left==1)
                {
                    left++;
                }
                else
                {
                    right=left;
                    maxback=intervals[left].back();
                }
            }
        }
        intervals.erase(intervals.begin()+left+1,intervals.begin()+right);
        intervals[left]=vector<int>{intervals[left].front(),maxback};
        return intervals;
    }
};