#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity)
        :_capacity(capacity)
    {}

    bool isfull()
    {
        return _LRUmap.size() == _capacity;
    }

    int get(int key) {
        if (_LRUmap.find(key) == _LRUmap.end())return -1;
        else
        {
            int ret = _LRUmap[key]->second;
            //更改数据位置

            //删除+头插
            _LRUlist.erase(_LRUmap[key]);
            _LRUlist.push_front(pair<int, int>(key, ret));
            _LRUmap[key] = _LRUlist.begin();

            return ret;
        }
    }

    void put(int key, int value)
    {
        if (_LRUmap.find(key) == _LRUmap.end())//增加数据
        {
            if (!isfull())//未满
            {
                _LRUlist.push_front(pair<int, int>(key, value));
                _LRUmap[key] = _LRUlist.begin();
            }
            else//满
            {
                int k = _LRUlist.back().first;
                _LRUmap.erase(k);
                _LRUlist.pop_back();
                _LRUlist.push_front(pair<int, int>(key, value));
                _LRUmap[key] = _LRUlist.begin();
            }
        }
        else//更新数据
        {
            //删除+头插
            _LRUlist.erase(_LRUmap[key]);
            _LRUlist.push_front(pair<int, int>(key, value));
            _LRUmap[key] = _LRUlist.begin();
        }

    }
private:
    typedef list<pair<int, int>>::iterator LTiter;
    unordered_map<int, LTiter> _LRUmap;
    list<pair<int, int>> _LRUlist;
    size_t _capacity;

};


//["LRUCache","get","put","get","put","put","get","get"]
//[[2],       [2],   [2,6], [1], [1,5],[1,2], [1],  [2]]
int main()
{
    LRUCache cache(2);
    cache.get(2);
    cache.put(2, 6);
    cache.get(1);
    cache.put(1, 5);
    cache.put(1, 2);


    return 0;

}