class KthLargest {
    priority_queue<int, vector<int>, greater<int>> heap;
    int _k;
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (auto e : nums)
        {
            heap.push(e);
            if (heap.size() > k) heap.pop();
        }
    }

    int add(int val) {
        //Ð¡¶Ñ
        heap.push(val);
        if (heap.size() > _k) heap.pop();
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */