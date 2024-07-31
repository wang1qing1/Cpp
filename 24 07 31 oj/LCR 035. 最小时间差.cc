class Solution {
public:
    int findMinDifference(vector<string>& timePoints) { 
        vector<int> time;
        time.reserve(timePoints.size());
        for(auto& str:timePoints)
        {
            int h;
            string strh=string(str.begin(),str.begin()+2);
            string strm=string(str.begin()+3,str.begin()+5);
            h=stoi(strh);
            int m=stoi(strm);
            time.push_back(h*60+m);
        }
        int ret=0x3f3f3f3f;
        sort(time.begin(),time.end());
        for(int i=0;i<time.size()-1;i++)
        {
            ret=min(time[i+1]-time[i],ret);
        }
        ret=min(time[0]+60*24-time.back(),ret);
        return ret;
    }
};

