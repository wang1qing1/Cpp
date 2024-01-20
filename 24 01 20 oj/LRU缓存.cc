class LRUCache {
public:
    list<pair<int,int>> li;
    map<int,list<pair<int,int>>::iterator> hash;
    int _cap;
    int count=0;
    LRUCache(int capacity) {
        _cap=capacity;
    }
    
    int get(int key) {
        if(hash.find(key)!=hash.end())
        {
            int val=hash[key]->second;
            li.erase(hash[key]);
            li.push_front({key,val});
            hash[key]=li.begin();
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hash.find(key)!=hash.end())//存在
        {
            li.erase(hash[key]);
            li.push_front({key,value});
            hash[key]=li.begin();
        }
        else//不存在
        {
            if(count+1<=_cap)//没有超出容量
            {
                li.push_front({key,value});
                hash[key]=li.begin();
            }
            else//超出容量
            {
                int lastkey=li.back().first;
                li.pop_back();
                li.push_front({key,value});
                
                hash.erase(lastkey);
                hash[key]=li.begin();
            }
            count++;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */