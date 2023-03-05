#pragma once
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

namespace ikun
{
	template<class T>
	class Vector
	{

		//friend ostream& out operator <<(ostream& out, const Vector<int> v)
		//{
		//	for (auto e : v)
		//	{
		//		out << e << " ";
		//	}
		//	return out;
		//}

		typedef T* itorator;
		typedef const itorator const_itorator;
	public:
		Vector()
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{
		}

		~Vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		int capacity()
		{
			return _end_of_storage - _start;
		}
		size_t size()
		{
			return _finish - _start;
		}

		void reserve(size_t n)
		{
			itorator tmp = new T[n];
			int S = size();
			if (_start)
			{
				memcpy(tmp, _start, (size() * sizeof(T)));
				delete[] _start;
			}
			//itorator sour = tmp;
			//for (itorator Dest = _start; Dest != _finish; Dest++)
			//{
			//	*sour = *Dest;
			//	sour++;
			//}
			_start = tmp;
			_finish = tmp + S;
			_end_of_storage = tmp + n;
		}

		void push_bank(T date)
		{
			if (_finish == _end_of_storage)
			{
				capacity() == 0 ? reserve(4) : reserve(2 * capacity());
			}
			*_finish = date;
			_finish++;
		}
		bool empty()
		{
			return _start == _finish;
		}
		void pop_bank()
		{
			assert(!empty());
			_finish--;
		}
		bool empty() const
		{
			return _start == _finish;
		}
		void pop_bank() const
		{
			assert(!empty());
			_finish--;
		}

		itorator begin()
		{
			return _start;
		}
		itorator end()
		{
			return _finish;
		}
		const_itorator begin() const
		{
			return _start;
		}
		const_itorator end() const
		{
			return _finish;
		}
		void resize(size_t n, T date = 0)
		{
			if (n < size())
			{
				
				n<0?_finish=_start:_finish = _start + n;
			}
			else if (n >= size() && n <= capacity())
			{
				iterator tail = _finish;
				while (tail != _end_of_storage)
				{
					*tail = date;
					tail++;
				}
				_finish = _start + n;
			}
			else//n>end_of_storang;
			{

			}

		}
		void insert(itorator pos, T date)
		{
			assert(pos <= _finish);
			assert(pos >= _start);
			//迭代器失效
			int index = pos - _start;
			if (_finish == _end_of_storage)
			{
				capacity() == 0 ? reserve(4) : reserve(2 * capacity());
			}
			//重置迭代器
			pos = _start + index;
			//挪动数据
			itorator tail = _finish;
			while (tail != pos)
			{
				*tail = *(tail - 1);
				tail--;
			}
			_finish++;
			*pos = date;
		}

		void erase(itorator pos)
		{
			assert(pos >= _start && pos < _finish);
			//数据挪动
			memmove(pos, pos + 1, (_finish - pos - 1) * sizeof(T));
			_finish--;
		}

		T& operator[](size_t pos)
		{
			return _start[pos];
		}
		const T& operator[](size_t pos) const
		{
			return _start[pos];
		}
	private:
		itorator _start;
		itorator _finish;
		itorator _end_of_storage;
	};


}
