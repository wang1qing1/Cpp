class LRUCache {
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(map.find(key)==map.end())
        {
            return -1;
        }
        auto it=map[key];
        int val = it->second;
        data.erase(it);
        data.push_front({key,val});
        map[key]=data.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end())
        {
            auto it=map[key];
            data.erase(it);
            data.push_front({key,value});
            map[key]=data.begin();
        }
        else
        {
            if(data.size()>=cap)
            {
                auto it=--data.end();
                map.erase(it->first);
                data.erase(it);
            }
            data.push_front({key,value});
            map[key]=data.begin();
        }
    }
    unordered_map<int,list<pair<int,int>>::iterator> map;
    list<pair<int,int>> data;//pair<K,V>
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//  
//  2 3
//  1 1
//  


