#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<random>


using namespace std;
class Skiplist {
    struct SkiplistNode
    {
        int _val;
        vector<SkiplistNode*> _next;

        SkiplistNode(int val,int level)
            :_val(val),_next(level,nullptr)
        {}
    };
    typedef SkiplistNode Node;
public:
    
    Skiplist() {
        srand(time(0));
        //刚开始跳表的头是没有数据的
        _head = new Node(-1, 1);
    }

    
    bool search(int target) 
    {
        Node* cur = _head;
        int level = _head->_next.size() - 1;
        while (level>=0)
        {
            //目标值大于下一个节点值，cur向右移动
            if (cur->_next[level] &&target > cur->_next[level]->_val)
            {
                cur = cur->_next[level];
            }
            //目标值小于下一个节点值，或者下一个值就是空，cur向下移动
            else if(cur->_next[level]==nullptr ||target < cur->_next[level]->_val)
            {
                level--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    vector<Node*>  FindPrevPath(int target)
    {
        Node* cur = _head;
        int level = _head->_next.size() - 1;
        //记录路径
        vector<Node*> path(level+1,_head);

        while (level >= 0)
        {
            //目标值大于下一个节点值，cur向右移动
            if (cur->_next[level] && target > cur->_next[level]->_val)
            {
                cur = cur->_next[level];
            }
            //目标值小于下一个节点值，或者下一个只就是空，cur向下移动
            else if (cur->_next[level] == nullptr || target <= cur->_next[level]->_val)
            {
                path[level] = cur;
                level--;
            }
        }
        return path;

    }

    int RandomLevel()
    {
        size_t level = 1;
        while (rand() < RAND_MAX * _p && level < _maxlevel)level++;
        return level;
    }

    //
    void add(int num) {
        vector<Node*> path = FindPrevPath(num);
        //创建新节点
        int level = RandomLevel();
        Node* newnode = new Node(num, level);

        //如果新的节点的层数大于头结点的层数，就需要给头节点的层数增高
        if (level > _head->_next.size())
        {
            _head->_next.resize(level, nullptr);
            path.resize(level, _head);
        }

        //连接前后节点
        for (int i = 0; i < level; i++)
        {
            newnode->_next[i] = path[i]->_next[i];
            path[i]->_next[i] = newnode;
        }
    }
    


    bool erase(int num) {

        vector<Node*> path = FindPrevPath(num);
        //连接前后节点

        if (path[0]->_next[0] == nullptr || path[0]->_next[0]->_val != num)
        {
            return false;
        }
        else
        {
            Node* del = path[0]->_next[0];
            for (int i = 0; i < del->_next.size(); i++)
            {
                path[i]->_next[i] = del->_next[i];
            }
        }
        

    }
private:
    Node* _head;
    double _p = 0.5;//增加一层的概率
    int _maxlevel = 32;//最高层

};

int main()
{
    Skiplist slist;
    slist.add(4);
    slist.add(5);
    slist.add(6);
    slist.add(7);
    slist.add(8);
    slist.add(9);

    return 0;
}