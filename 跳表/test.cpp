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
        //�տ�ʼ�����ͷ��û�����ݵ�
        _head = new Node(-1, 1);
    }

    
    bool search(int target) 
    {
        Node* cur = _head;
        int level = _head->_next.size() - 1;
        while (level>=0)
        {
            //Ŀ��ֵ������һ���ڵ�ֵ��cur�����ƶ�
            if (cur->_next[level] &&target > cur->_next[level]->_val)
            {
                cur = cur->_next[level];
            }
            //Ŀ��ֵС����һ���ڵ�ֵ��������һ��ֵ���ǿգ�cur�����ƶ�
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
        //��¼·��
        vector<Node*> path(level+1,_head);

        while (level >= 0)
        {
            //Ŀ��ֵ������һ���ڵ�ֵ��cur�����ƶ�
            if (cur->_next[level] && target > cur->_next[level]->_val)
            {
                cur = cur->_next[level];
            }
            //Ŀ��ֵС����һ���ڵ�ֵ��������һ��ֻ���ǿգ�cur�����ƶ�
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
        //�����½ڵ�
        int level = RandomLevel();
        Node* newnode = new Node(num, level);

        //����µĽڵ�Ĳ�������ͷ���Ĳ���������Ҫ��ͷ�ڵ�Ĳ�������
        if (level > _head->_next.size())
        {
            _head->_next.resize(level, nullptr);
            path.resize(level, _head);
        }

        //����ǰ��ڵ�
        for (int i = 0; i < level; i++)
        {
            newnode->_next[i] = path[i]->_next[i];
            path[i]->_next[i] = newnode;
        }
    }
    


    bool erase(int num) {

        vector<Node*> path = FindPrevPath(num);
        //����ǰ��ڵ�

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
    double _p = 0.5;//����һ��ĸ���
    int _maxlevel = 32;//��߲�

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