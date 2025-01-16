class KthLargest {
public:
    KthLargest(int _k, vector<int>& nums) {
        k=_k;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(min_pq.size()<k)
            {
                min_pq.push(nums[i]);
            }
            else
            {
                max_pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(min_pq.size()<k)
        {
            min_pq.push(val);
        }
        else if(val>=min_pq.top())
        {
            max_pq.push(min_pq.top());
            min_pq.pop();
            min_pq.push(val);
        }
        else
        {
            max_pq.push(val);
        }
        return min_pq.top();
    }
    priority_queue<int> max_pq;
    priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
    int k;

};

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        _nums=nums;
        sort(_nums.begin(),_nums.end());
        _k=k;
    }
    
    int add(int val) {
        _nums.resize(_nums.size()+1);
        int flag=1;
        for(int i=0;i<_nums.size()-1;i++)
        {
            if(val<_nums[i])
            {
                for(int j=_nums.size()-1;j>i;j--)_nums[j]=_nums[j-1];
                _nums[i]=val;
                flag=0;
                break;
            }
        }
        if(flag)_nums[_nums.size()-1]=val;
        
        return _nums[_nums.size()-_k];
    }
    vector<int> _nums;
    int _k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */