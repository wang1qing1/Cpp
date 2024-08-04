class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        win=size;
    }
    
    double next(int val) {
        if(arr.size()==win)
        {
            int top=arr.front();arr.pop();
            sum-=top;
        }
        arr.push(val);
        sum+=val;
        return sum*1.0/arr.size();
    }
    queue<int> arr;
    int sum=0;
    int win;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */