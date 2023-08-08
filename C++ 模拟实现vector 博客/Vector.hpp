#pragma once
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cassert>
using namespace std;

template<class T>
class Vector
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	Vector()
		:_start(nullptr),
		_finish(nullptr),
		_end_of_storage(nullptr)
	{
	}

	size_t size() const
	{
		return _finish - _start;
	}

	size_t capacity() const
	{
		return _end_of_storage - _start;
	}

	//void reserve(size_t capa)
	//{
	//	//仅支持容量扩大，不支持容量减小
	//	if (capacity() < capa)
	//	{
	//		size_t sz = size();
	//		iterator tmp = new T[capa];
	//		//分清当前的是否已经有了容量，如果已经有了容量需要释放之前的容量，
	//		//如果之前没有容量仅需，将新开的空间指向我们的_start.
	//		if (_start)
	//		{
	//			memcpy(tmp, _start, sizeof(T) * capacity());
	//			delete[] _start;
	//		}
	//		//注意:此处不能直接tmp+size()来计算，因为在计算_start的时候已经已经改变了_start,
	//		//然后计算的size也并非是，准确的size。
	//		_start = tmp;
	//		_finish = tmp + sz;
	//		_end_of_storage = _start + capa;
	//	}
	//}

	void resize(size_t n, T val = T())
	{	
		//0<n<size;
		if (n < size())
		{
			_finish = _start + n;
		}
		//size<n<capacity;
		else 
		{
			if (n >= capacity())
			{
				reserve(n);
			}
			while (_finish != _start + n)
			{
				*(_finish) = val;
				_finish++;
			}
		}
	}

	T& operator[](size_t pos)
	{
		assert(pos < size());
		return _start[pos];
	}

	const T& operator[](size_t pos) const
	{
		assert(pos < size());
		return _start[pos];
	}

	void push_back(const T& val)
	{
		if (_finish == _end_of_storage)
		{
			capacity() == 0 ? reserve(5) : reserve(capacity() * 2);
		}
		*(_finish) = val;
		_finish++;
	}

	bool empty() const 
	{
		return size() == 0;
	}

	void pop_back()
	{
		assert(!empty());
		_finish--;
	}

	iterator erase(iterator pos)
	{
		assert(pos >= _start);
		assert(pos < _finish);
		iterator end = pos ;
		while (end < _finish)
		{
			*end = *(end + 1);
			end++;
		}
		_finish--;
		return pos;
	}

	iterator insert(iterator pos,T val)
	{
		assert(pos >= _start);
		assert(pos < _finish);
		//迭代器失效问题
		int len = pos - _start;
		if (_finish == _end_of_storage)
		{
			capacity() == 0 ? reserve(5) : reserve(capacity() * 2);
		}
		pos = _start + len;
		iterator end = _finish;
		while (end >= pos)
		{
			(*end) = *(end - 1);
			end--;
		}
		_finish++;
		(*pos) = val;
		return pos;
	}

	iterator begin()
	{
		return _start;
	}
	iterator end()
	{
		return _finish;
	}

	const_iterator begin()const 
	{
		return _start;
	}
	const_iterator end()const
	{
		return _finish;
	}
	void reserve(size_t capa)
	{
		if (capacity() < capa)
		{
			iterator tmp = new T[capa];
			if (_start)
			{
				memcpy(tmp, _start, sizeof(T) * capacity());
				delete[] _start;
			}
			//注意:此处不能直接tmp+size()来计算，因为在计算_start的时候已经已经改变了_start,
			//然后计算的size也并非是，准确的size。
			_start = tmp;
			_finish = tmp + size();
			_end_of_storage = _start + capa;
		}
	}
private:
	iterator _start;//数据存储首地址
	iterator _finish;//有效数据尾部地址下一个地址。
	iterator _end_of_storage;//容量尾地址下一个地址
};




