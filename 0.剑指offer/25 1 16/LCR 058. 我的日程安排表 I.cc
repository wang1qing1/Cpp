class MyCalendar {
public:
    MyCalendar() {
        vpair.push_back({-1,-1});
    }
    
    bool book(int start, int end) {
        
        for(int i=1;i<vpair.size();i++)
        {
            auto [a1,b1]=vpair[i-1];
            auto [a2,b2]=vpair[i];
            if(start<=a2)
            {
                if(start<b1||end>a2)
                {
                    return false;
                }
                vpair.resize(vpair.size()+1);
                for(int j=vpair.size()-1;j>i;j--)
                {
                    vpair[j]=vpair[j-1];
                }
                vpair[i]={start,end};
                return true;
            }
        }
        auto [a3,b3]=vpair.back();
        if(start<b3)
        {
            return false;
        }
        vpair.push_back({start,end});
        return true;
    }
    vector<pair<int,int>> vpair;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */