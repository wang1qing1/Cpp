#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<iostream>
namespace ikun
{
	template<class T>
	struct ListNode
	{
		T date;
		ListNode<T>* next;
		ListNode<T>* prev;

		ListNode(const T& x = T())
			:date(x),
			next(nullptr),
			prev(nullptr)
		{
		}	
	};


	template<class T,class Ref,class Ptr>
	struct my_iterator
	{
		typedef my_iterator<T,Ref,Ptr> self;
		typedef ListNode<T>* node;
		node _node;

		my_iterator(node pos)
			:_node(pos)
		{
		}
		Ref operator*()
		{
			return _node->date;
		}
		self& operator++()
		{
			_node = _node->next;
			return *this;
		}

		self operator++(int)
		{
			self tmp = *this;
			_node = _node->next;
			return tmp;
		}

		self& operator--()
		{
			_node = _node->prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp = *this;
			_node = _node->prev;
			return tmp;
		}

		bool operator!=(self pos)
		{
			return _node != pos._node;
		}

		Ptr operator->()
		{
			return &(_node->date);
		}

	};
	template<class Iterator, class Ref, class Ptr>
	class my_reserve_iterator
	{
		typedef my_reserve_iterator<Iterator, Ref, Ptr> reserve_iterator;
	public:
		my_reserve_iterator(Iterator tmp)
			:cur(tmp)
		{
		}
		reserve_iterator& operator++()
		{
			cur--;
			return *this;
		}
		reserve_iterator& operator--()
		{
			cur++;
			return *this;
		}
		reserve_iterator& operator++(int)
		{
			reserve_iterator tmp = cur;
			cur--;
			return tmp;
		}
		reserve_iterator& operator--(int)
		{
			reserve_iterator tmp = cur;
			cur++;
			return tmp;
		}
		Ref operator*()
		{
			Iterator tmp = cur;
			tmp--;
			return *tmp;
		}
		Ref operator*() const
		{
			Iterator tmp = cur;
			tmp--;
			return *tmp;
		}
		bool operator!=(reserve_iterator pos)
		{
			return (* this).cur != pos.cur;
		}
	private:
		Iterator cur;
	};

	template<class T>
	class List
	{
		typedef ListNode<T> node;
	public:
		typedef my_iterator<T, const T&, const T*> const_iterator;
		typedef my_iterator<T,T&,T*> iterator;
		typedef my_reserve_iterator<iterator, T&, T*> reserve_iterator;
		typedef my_reserve_iterator<const_iterator,const T&, const T*> const_reserve_iterator;
		//typedef itorator<T,const T&> const_itorator;
	
		List()
		{
			_head = new node;
			_head->next = _head;
			_head->prev = _head;
		}

		void push_bank(T date)
		{
			node* newnode = new node;
			newnode->date = date;
			node* tail = _head->prev;
			tail->next = newnode;
			newnode->prev = tail;
			newnode->next = _head;
			_head->prev = newnode;
		}
		reserve_iterator rbegin()
		{
			return reserve_iterator(end());
		}
		reserve_iterator rend()
		{
			return reserve_iterator(begin());
		}
		const_reserve_iterator rbegin()const
		{
			return const_reserve_iterator(end());
		}
		const_reserve_iterator rend()const
		{
			return const_reserve_iterator(begin());
		}

		iterator begin()
		{
			iterator it(_head->next);
			return it;
		}

		iterator end()
		{
			iterator it(_head);
			return it;
		}
		const_iterator begin() const
		{
			const_iterator it(_head->next);
			return it;
		}

		const_iterator end() const
		{
			const_iterator it(_head);
			return it;
		}
		
		void insert(iterator pos ,const T& date)
		{
			node* newnode = new node;
			newnode->date = date;
			node* cur = pos._node;
			node* prev = cur->prev;
			prev->next = newnode;
			newnode->prev = prev;
			newnode->next = cur;
			cur->prev = newnode;
		}

		void erase(iterator pos)
		{
			assert(pos._node != _head);

			node* front = pos._node->prev;
			node* bank = pos._node->next;
			front->next = bank;
			bank->prev = front;
			delete pos._node;
		}

		void push_front(const T& date)
		{
			insert(begin(), date);
		}

		void pop_bank()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}

	private:
		node* _head;
	};






}

