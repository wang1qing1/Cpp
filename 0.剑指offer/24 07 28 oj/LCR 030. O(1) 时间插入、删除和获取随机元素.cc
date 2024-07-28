class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(0));

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.find(val)==map.end())
        {
            data.push_back(val);
            map[val]=data.size()-1;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(map.find(val)==map.end())
        {
            return false;
        }
        else
        {   //交换需要rmove的值和vector最后一个元素的值
            int pos=map[val];
            int num=data.back();
            swap(data[pos],data[data.size()-1]);
            //调整hash
            map[num]=pos;
            //remove
            map.erase(val);
            data.pop_back();
        }
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index=rand()%map.size();
        return data[index];
    }
    unordered_map<int,int> map;
    vector<int> data;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

