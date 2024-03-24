//利用双链表设计最大队列,链表头部存储当前队列的最大值
class Checkout {
public:
    Checkout() {

    }
    
    int get_max() {
        if(q.empty())return -1;
        return maxslist.front();
    }
    
    void add(int value) {
        q.push(value);
        //  添加数据以后维护最大值,最大值就是队头元素
        //  如果队尾有比当前值小的就将队尾出去
        while(!maxslist.empty()&&maxslist.back()<value)
        {
            maxslist.pop_back();
        }
        maxslist.push_back(value);
    }
    
    int remove() {
        if(q.empty())return -1;
        int front=q.front();
        q.pop();
        //移除的数据数据如果市当前的最大值，就需要更新最大值
        if(front==maxslist.front())
        {
            maxslist.pop_front();
        }
        return front;
    }
    //双向链表头插头删尾插尾删都是O(1)
    list<int> maxslist;
    queue<int> q;

};

/**
 * Your Checkout object will be instantiated and called as such:
 * Checkout* obj = new Checkout();
 * int param_1 = obj->get_max();
 * obj->add(value);
 * int param_3 = obj->remove();
 */