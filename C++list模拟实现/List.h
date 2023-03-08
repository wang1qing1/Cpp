#pragma once
#include<assert.h>
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
	struct my_itorator
	{
		typedef my_itorator<T,Ref,Ptr> self;
		typedef ListNode<T>* node;
		node _node;

		my_itorator(node pos)
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

	/*template<class T>
	struct const_itorator
	{
		typedef const_itorator<T> con_self;
		typedef ListNode<T>* node;
		node _node;

		const_itorator(node pos)
			:_node(pos)
		{
		}
		con_self& operator++(int)  
		{
			_node = _node->next;
			return *this;
		}

		con_self operator++()
		{
			con_self tmp = *this;
			_node = _node->next;
			return tmp;
		}
		con_self& operator--(int)
		{
			_node = _node->prev;
			return *this;
		}

		con_self operator--()
		{
			con_self tmp = *this;
			_node = _node->prev;
			return tmp;
		}

		const T& operator*()
		{
			return _node->date;
		}

		bool operator!=(con_self pos)
		{
			return _node != pos._node;
		}
	};*/

	template<class T>
	class List
	{
		typedef ListNode<T> node;
	public:
		typedef my_itorator<T, const T&, const T*> const_itorator;
		typedef my_itorator<T,T&,T*> itorator;
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

		itorator begin()
		{
			itorator it(_head->next);
			return it;
		}

		itorator end()
		{
			itorator it(_head);
			return it;
		}
		const_itorator begin() const
		{
			const_itorator it(_head->next);
			return it;
		}

		const_itorator end() const
		{
			const_itorator it(_head);
			return it;
		}
		
		void insert(itorator pos ,const T& date)
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

		void erase(itorator pos)
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

