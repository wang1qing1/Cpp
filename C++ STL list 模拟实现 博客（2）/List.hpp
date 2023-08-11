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

	T _val;           //�洢����
	_list_node* _next;//��һ������ָ��
	_list_node* _prev;//ǰһ������ָ��
};

//template<class T>
//struct _list_node
//{
//	_list_node(const T& val = T())
//		:_val(val),
//		_next(nullptr),
//		_prev(nullptr)
//	{
//	}
//
//	T _val;           //�洢����
//	struct _list_node* _next;//��һ������ָ��
//	struct _list_node* _prev;//ǰһ������ָ��
//};


template<class T,class Ref,class Ptr>
class _list_iterator
{
public:
	typedef _list_node<T> node;
	typedef _list_iterator<T,Ref,Ptr> self;

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

	bool operator!=(const self& it )
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
//
//private:
//	node* _node;
//};

/*
List �ĵ�����
������������ʵ�ַ�ʽ������Ӧ���������ײ����ݽṹʵ�֣�
  1. ԭ��ָ̬�룬���磺vector
  2. ��ԭ��ָ̬����з�װ���������ʹ����ʽ��ָ����ȫ��ͬ��������Զ�������б���ʵ�����·�����
	 1. ָ����Խ����ã������������б�������operator*()
	 2. ָ�����ͨ��->��������ָ�ռ��Ա�����������б�������oprator->()
	 3. ָ�����++����ƶ������������б�������operator++()��operator++(int)
		����operator--()/operator--(int)�ͷ���Ҫ���أ����ݾ���Ľṹ������˫�����������ǰ�ƶ���������Ҫ���أ������forward_list�Ͳ���Ҫ����--
	 4. ��������Ҫ�����Ƿ���ȵıȽϣ���˻���Ҫ����operator==()��operator!=()
*/



template<class T>
class List
{
public:

	typedef _list_node<T> node;
	typedef _list_iterator<T,T&,T*> iterator;
	typedef _list_iterator<T,const T&,const T*> const_iterator;

	List()
		:_head(new node)
	{
		_head->_next = _head;
		_head->_prev = _head;
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
		//�п�
		assert(!empty());
		node* tail = _head->_prev;
		node* newtail = tail->_prev;
		//�ı�ָ��
		_head->_next = newtail;
		newtail->_prev = _head;
		//�ͷŽ��
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

	void ersse(iterator pos)
	{

		node* posnode = pos.GetNodePtr();
		node* prevnode = posnode->_prev;
		node* nextnode = posnode->_next;
		prevnode->_next = nextnode;
		nextnode->_prev = prevnode;
		delete posnode;
	}

	iterator begin()
	{
		return iterator(_head->_next);
	}
	iterator end()
	{
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



	void print()
	{
		node* frist = _head->_next;
		while (frist != _head)
		{
			cout << frist->_val << " ";
			frist = frist->_next;
		}
	}

private:
	node* _head;
};


