#pragma once

#include<iostream>
#include<vector>
#include<string.h>
#include<deque>
using namespace std;

namespace ikun 
{
	template <class T>
	struct _less
	{
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	template <class T>
	struct greater
	{
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};

	template<class T, class container = vector<T>, class _comp = _less<T>>
	class Priority_Queue
	{
	public:
		Priority_Queue()
		{
		}

		Priority_Queue(vector<int>::iterator itbegin, vector<int>::iterator itend)
		{
			while (itbegin != itend)
			{
				push_back(*itbegin);
				itbegin++;
			}
		}
		//Priority_Queue(container::iterator itbegin, container::iterator itend)
		//{
		//	while (itbegin != itend)
		//	{
		//		push_back(*itbegin);
		//		itbegin++;
		//	}
		//}

		void adject_up(int child)
		{
			_comp com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void adject_down(int parent)
		{
			_comp com;
			int maxchild = parent * 2 + 1;
			while (maxchild < _con.size())
			{
				if (maxchild + 1 < _con.size() && com(_con[maxchild], _con[maxchild + 1]))
				{
					maxchild++;
				}
				if (com(_con[parent], _con[maxchild]))
				{
					swap(_con[maxchild], _con[parent]);
					parent = maxchild;
					maxchild = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void push_back(const T& date)
		{
			_con.push_back(date);
			adject_up(_con.size() - 1);
		}

		const T top()
		{
			return _con.front();
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adject_down(0);
		}
		bool empty()
		{
			return _con.empty();
		}

	private:
		container _con;
	};


}
