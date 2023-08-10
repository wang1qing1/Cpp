#pragma once
#include<iostream>
#include<list>
#include<algorithm>

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

	T _val;
	_list_node* _next;
	_list_node* _prev;

};


template<class T>
class List
{
public:

	typedef _list_node<T> node;

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


