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
		const int capacity()const
		{
			return _end_of_storage - _start;
		}
		const size_t size()const
		{
			return _finish - _start;
		}

		void reserve(size_t n)
		{
			itorator tmp = new T[n];
			int S = size();
			if (_start)
			{
				//当我们vector的每个元素不是内置类型时，这种拷贝试浅拷贝，会释放两次
				/*memcpy(tmp, _start, (size() * sizeof(T)));*/
				for (int i = 0; i < size(); i++)
				{
					tmp[i] = _start[i];
				}
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

		Vector(const Vector<T>& date)
		{
			reserve(date.capacity());
			//当我们vector的每个元素不是内置类型时，这种拷贝试浅拷贝，会两次释放
			//memcpy(_start, date._start, sizeof(T) * date.size());
			// 问题？
			//for (const_itorator it = date.begin(); it != date.end(); it++)
			//{
			//	push_bank(*it);
			//}
			for (int i = 0; i < date.size(); i++)
			{
				/*_start[i] = date._start[i];*/
				push_bank(date[i]);
			}
			/*_finish = _start + date.size();
			_end_of_storage = _start + date.capacity();*/
		}

		template<class InputIterator>
		Vector(InputIterator frist, InputIterator last)
		{
			//reserve(last - frist);
			while (frist != last)
			{
				push_bank(*frist);
				frist++;
			}
		}

		void resize(size_t n, const T date =T())
		{
			if (n < size())
			{
				n<0?_finish=_start:_finish = _start + n;
			}
			else if (n >= size() && n <= capacity())
			{
				itorator tail = _finish;
				while (tail != _end_of_storage)
				{
					*tail = date;
					tail++;
				}
				_finish = _start + n;
			}
			else//n>end_of_storang;
			{
				reserve(n);
				itorator tail = _finish;
				while (tail != _end_of_storage)
				{
					*tail = date;
					tail++;
				}
				_finish = _start + n;
			}
		}

		itorator insert(itorator pos, T date)
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
			return pos;
		}

		itorator erase(itorator pos)
		{
			assert(pos >= _start && pos < _finish);
			//数据挪动
			memmove(pos, pos + 1, (_finish - pos - 1) * sizeof(T));
			_finish--;
			return pos;
		}

		 

		T& operator[](size_t pos)
		{
			assert(pos >= 0 && pos < (_finish - _start));
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos >= 0 && pos < (_finish - _start));
			return _start[pos];
		}



	private:
		itorator _start = nullptr;
		itorator _finish = nullptr;
		itorator _end_of_storage = nullptr;
	};


}
