#pragma once
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

namespace ikun1
{
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
			return (*this).cur != pos.cur;
		}
	private:
		Iterator cur;
	};
	template<class T>
	class Vector
	{
		typedef T* iterator;
		typedef const iterator const_iterator;
		typedef my_reserve_iterator<iterator, T&, T*> reserve_iterator;
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
		reserve_iterator rbegin()
		{
			return reserve_iterator(end());
		}
		reserve_iterator rend()
		{
			return reserve_iterator(begin());
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
			iterator tmp = new T[n];
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

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}


		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
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
				reserve(n);
				iterator tail = _finish;
				while (tail != _end_of_storage)
				{
					*tail = date;
					tail++;
				}
				_finish = _start + n;
			}
		}

		iterator insert(iterator pos, T date)
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
			iterator tail = _finish;
			while (tail != pos)
			{
				*tail = *(tail - 1);
				tail--;
			}
			_finish++;
			*pos = date;
			return pos;
		}

		iterator erase(iterator pos)
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
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};


}
