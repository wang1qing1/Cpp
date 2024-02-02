class MedianFinder {
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(left.empty()||num<=left.top())
        {
            if(left.size()>right.size())
            {
                left.push(num);
                right.push(left.top());
                left.pop();
            }
            else left.push(num);
        }
        else
        {
            if(right.size()>=left.size())
            {
                right.push(num);
                left.push(right.top());
                right.pop();
            }
            else right.push(num);
            
        }
    }
    
    double findMedian() {
        double ret=0;
        if(left.size()==right.size()) ret=(left.top()+right.top())*1.0/2;
        else if(left.size()>right.size())ret= left.top();
        
        return ret;
    }
    priority_queue<int,vector<int>,less<int>> left;//大
    priority_queue<int,vector<int>,greater<int>> right;//小
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */