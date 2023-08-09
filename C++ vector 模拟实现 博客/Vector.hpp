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

	//1.Vector<T> v(5,10);创建一个Vector并且初始化前5个值为10
	Vector(size_t n, const T& val = T())
		:_start(nullptr),
		_finish(nullptr),
		_end_of_storage(nullptr)
	{
		reserve(n);
		for (int i = 0; i < n; i++)
		{
			push_back(val);
		}
	}

	//2.迭代器初始化，[frist,lest)
	template<class InputIterator>
	Vector(InputIterator frist, InputIterator lest)
		:_start(nullptr),
		_finish(nullptr),
		_end_of_storage(nullptr)
	{
		reserve(lest - frist);
		while (frist != lest)
		{
			push_back(*frist);
			frist++;
		}
	}

	//3.防止构造函数调用冲突
	Vector(int n, const T& val = T())
		:_start(nullptr),
		_finish(nullptr),
		_end_of_storage(nullptr)
	{
		reserve(n);
		for (int i = 0; i < n; i++)
		{
			push_back(val);
		}
	}

	Vector(const Vector<T>& v)
		:_start(nullptr),
		_finish(nullptr),
		_end_of_storage(nullptr)
	{
		reserve(v.capacity());
		//这里我们将数据一个一个push进去，这样我们借助push_back底层插入的时候，
		//会使用string的赋值构造，完成深拷贝。
		for (int i = 0; i < v.size(); i++)
		{
			push_back(v[i]);
		}
	}

	Vector<T>& operator=(const Vector<T>& v)
	{
		T* tmp = new T[v.capacity()];
		if (_start)
		{
			for (int i = 0; i < v.size(); i++)
			{
				tmp[i] = _start[i];
			}
			delete[] _start;
		}
		_start = tmp;
		_finish = _start + v.size();
		_end_of_storage = _start + v.capacity();
		
		return *this;
	}
	
	//Vector(const Vector<T>& v)
	//	:_start(nullptr),
	//	_finish(nullptr),
	//	_end_of_storage(nullptr)
	//{
	//	//万万不可以直接按二进制拷贝
	//	reserve(v.capacity());
	//	memcpy(_start, v._start, sizeof(T) * v.capacity()); /*error!!!!*/
	//	_finish = _start + v.size();
	//	_end_of_storage = _start + v.capacity();
	//}

	size_t size() const
	{
		return _finish - _start;
	}

	size_t capacity() const
	{
		return _end_of_storage - _start;
	}

	void reserve(size_t capa)
	{
		//仅支持容量扩大，不支持容量减小
		if (capacity() < capa)
		{
			size_t sz = size();
			iterator tmp = new T[capa];
			//分清当前的是否已经有了容量，如果已经有了容量需要释放之前的容量，
			//如果之前没有容量仅需，将新开的空间指向我们的_start.
			if (_start)
			{
				//这里千万不能按二进制直接拷贝.
				//memcpy(tmp, _start, sizeof(T) * capacity());   /*ror ！！*/
				for (int i = 0; i < size(); i++)
				{
					tmp[i]=_start[i];
				}
				delete[] _start;
			}
			//注意:此处不能直接tmp+size()来计算，因为在计算_start的时候已经已经改变了_start,
			//然后计算的size也并非是，准确的size。
			_start = tmp;
			_finish = tmp + sz;
			_end_of_storage = _start + capa;
		}
	}

	void resize(size_t n, T val = T())
	{	
		//1.n < size;-->删除数据
		if (n < size())
		{
			_finish = _start + n;
		}
		//2.n > size
		else 
		{
			//(1)如果空间不足，需要扩容+初始化
			if (n >= capacity())
			{
				reserve(n);
			}
			//(2)空间足够，仅需要初始化剩下的空间
			while (_finish != _start + n)
			{
				*(_finish) = val;
				_finish++;
			}
		}
	}
	//穿引用返回
	T& operator[](size_t pos)
	{
		//判断位置的合法性
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
		//内置类型直接赋值,自定义类型使用赋值构造
		*(_finish) = val;
		_finish++;
	}

	bool empty() const 
	{
		return size() == 0;
	}

	void pop_back()
	{
		//判空
		assert(!empty());
		//我们仅需将维护尾部数据的指针向前挪一位。
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
		//迭代器失效问题,记录pos的相对位置
		int len = pos - _start;
		if (_finish == _end_of_storage)
		{
			capacity() == 0 ? reserve(5) : reserve(capacity() * 2);
		}
		//扩容后重新计算pos，没有发生扩容pos不变
		pos = _start + len;
		iterator end = _finish;
		//数据挪动
		while (end >= pos)
		{
			(*end) = *(end - 1);
			end--;
		}
		_finish++;
		(*pos) = val;
		return pos;
	}

	//普通迭代器
	iterator begin()
	{
		return _start;
	}
	iterator end()
	{
		return _finish;
	}

	//const 迭代器
	const_iterator begin()const 
	{
		return _start;
	}
	const_iterator end()const
	{
		return _finish;
	}

	~Vector()
	{
		delete[] _start;
		_start = _finish = _end_of_storage = nullptr;
	}
private:
	iterator _start;//数据存储首地址
	iterator _finish;//有效数据尾部地址下一个地址。
	iterator _end_of_storage;//容量尾地址下一个地址
	int tmp;
};




