#pragma once
#include<iostream>
#include<list>
#include<algorithm>
#include<cassert>

using namespace std;



template<class T>
struct _list_node
{
	_list_node( const T& val = T())
		:_val(val),
		_next(nullptr),
		_prev(nullptr)
	{
	}

	T _val;           //存储数据
	_list_node* _next;//后一个结点的指针
	_list_node* _prev;//前一个结点的指针
};

/*
List 的迭代器
迭代器有两种实现方式，具体应根据容器底层数据结构实现：
  1. 原生态指针，比如：vector
  2. 将原生态指针进行封装，因迭代器使用形式与指针完全相同，因此在自定义的类中必须实现以下方法：
	 1. 指针可以解引用，迭代器的类中必须重载operator*()
	 2. 指针可以通过->访问其所指空间成员，迭代器类中必须重载oprator->()
	 3. 指针可以++向后移动，迭代器类中必须重载operator++()与operator++(int)
		至于operator--()/operator--(int)释放需要重载，根据具体的结构来抉择，双向链表可以向前移动，所以需要重载，如果是forward_list就不需要重载--
	 4. 迭代器需要进行是否相等的比较，因此还需要重载operator==()与operator!=()
*/

//普通迭代器1.0版本
//template<class T>
//class _list_iterator
//{
//public:
//	typedef _list_node<T> node;
//	typedef _list_iterator self;
//
//	_list_iterator(node* n)
//		:_node(n)
//	{
//	}
//
//	T& operator*()
//	{
//		return _node->_val;
//	}
//
//	self operator++(int)
//	{
//		self tmp(*this);
//		_node = _node->_next;
//		return tmp;
//	}
//
//	self operator++()
//	{
//		_node = _node->_next;
//		return *this;
//	}
//
//	self operator--(int)
//	{
//		self tmp(*this);
//		_node = _node->_prev;
//		return tmp;
//	}
//
//	self operator--()
//	{
//		_node = _node->_prev;
//		return *this;
//	}
//
//	bool operator!=(const self& it)
//	{
//		return _node != it._node;
//	}
//
//	bool operator==(const self& it)
//	{
//		return _node == it._node;
//	}
//
//	T*  operator->()
//	{
//		return &_node->_val;
//	}
//private:
//	node* _node;
//};


//const迭代器1.0版本
//template<class T>
//class const_list_iterator
//{
//public:
//	typedef _list_node<T> node;
//	typedef const_list_iterator self;
//
//	const_list_iterator(node* n)
//		:_node(n)
//	{
//	}
//
//	const T& operator*()
//	{
//		return _node->_val;
//	}
//
//	self operator++(int)
//	{
//		self tmp(*this);
//		_node = _node->_next;
//		return tmp;
//	}
//
//	self operator++()
//	{
//		_node = _node->_next;
//		return *this;
//	}
//
//	self operator--(int)
//	{
//		self tmp(*this);
//		_node = _node->_prev;
//		return tmp;
//	}
//
//	self operator--()
//	{
//		_node = _node->_prev;
//		return *this;
//	}
//
//	bool operator!=(const self& it)
//	{
//		return _node != it._node;
//	}
//
//	bool operator==(const self& it)
//	{
//		return _node == it._node;
//	}
//
//	const T*  operator->()
//	{
//		return &_node->_val;
//	}
//private:
//	node* _node;
//};

//迭代器2.0版本
//T:数据类型，Ref:T&/const T&, Ptr: T*/const T*
template<class T, class Ref, class Ptr>
class _list_iterator
{
public:
	typedef _list_node<T> node;
	typedef _list_iterator<T, Ref, Ptr> self;

	_list_iterator(node* n)
		:_node(n)
	{
	}

	Ref operator*()
	{
		return _node->_val;
	}

	self operator++(int)
	{
		self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	Ptr operator->()
	{
		return &_node->_val;
	}

	bool operator!=(const self& it)
	{
		return _node != it._node;
	}

	bool operator==(const self& it)
	{
		return _node == it._node;
	}

	node* GetNodePtr()
	{
		return _node;
	}
private:
	node* _node;
};


template<class T>
class List
{
public:
	typedef _list_node<T> node;
	typedef _list_iterator<T,T&,T*> iterator;
	typedef _list_iterator<T,const T&,const T*> const_iterator;

	void emptyInit()
	{
		_head->_next = _head;
		_head->_prev = _head;
	}

	List()
		:_head(new node)
	{
		emptyInit();
	}

	template<class InputIterator>
	List(InputIterator frist, InputIterator lest)
		:_head(new node)
	{
		emptyInit();
		while (frist != lest)
		{
			push_back(*frist);
			frist++;
		}
	}

	void push_back(const T& val )
	{
		node* newnode = new node(val);

		node* tail = _head->_prev;

		tail->_next = newnode;
		newnode->_next = _head;
		_head->_prev = newnode;
		newnode->_prev = tail;
	}

	bool empty()
	{
		return _head->_next == _head;
	}

	void pop_back()
	{
		//判空
		assert(!empty());
		node* tail = _head->_prev;
		node* newtail = tail->_prev;
		//改变指向
		_head->_next = newtail;
		newtail->_prev = _head;
		//释放结点
		delete tail;
	}

	void insert(iterator pos,const T& val)
	{
		node* newnode = new node(val);
		node* posnode = pos.GetNodePtr();
		node* prevnode = posnode->_prev;

		newnode->_next = posnode;
		newnode->_prev = prevnode;
		prevnode->_next = posnode;
		posnode->_prev = newnode;
		
	}

	iterator erase(iterator pos)
	{

		node* posnode = pos.GetNodePtr();
		node* prevnode = posnode->_prev;
		node* nextnode = posnode->_next;
		prevnode->_next = nextnode;
		nextnode->_prev = prevnode;
		delete posnode;
		return iterator(nextnode);
	}

	iterator begin()
	{
		//使用哨兵位的下一个结点指针，构造begin
		return iterator(_head->_next);
	}
	iterator end()
	{
		//使用哨兵位结点指针，构造end
		return iterator(_head);
	}

	const_iterator begin()const
	{
		return const_iterator(_head->_next);
	}
	const_iterator end()const
	{
		return const_iterator(_head);
	}

	//清除数据，但是需要保留
	void clear()
	{
		iterator it = begin();
		while (it != end())
		{
			it = erase(it);
		}
	}

	~List()
	{
		//连同头节点一起释放
		clear();
		delete _head;
		_head = nullptr;
	}

private:
	node* _head;
};


