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
	//	//��֧���������󣬲�֧��������С
	//	if (capacity() < capa)
	//	{
	//		size_t sz = size();
	//		iterator tmp = new T[capa];
	//		//���嵱ǰ���Ƿ��Ѿ���������������Ѿ�����������Ҫ�ͷ�֮ǰ��������
	//		//���֮ǰû���������裬���¿��Ŀռ�ָ�����ǵ�_start.
	//		if (_start)
	//		{
	//			memcpy(tmp, _start, sizeof(T) * capacity());
	//			delete[] _start;
	//		}
	//		//ע��:�˴�����ֱ��tmp+size()�����㣬��Ϊ�ڼ���_start��ʱ���Ѿ��Ѿ��ı���_start,
	//		//Ȼ������sizeҲ�����ǣ�׼ȷ��size��
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
		//������ʧЧ����
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
			//ע��:�˴�����ֱ��tmp+size()�����㣬��Ϊ�ڼ���_start��ʱ���Ѿ��Ѿ��ı���_start,
			//Ȼ������sizeҲ�����ǣ�׼ȷ��size��
			_start = tmp;
			_finish = tmp + size();
			_end_of_storage = _start + capa;
		}
	}
private:
	iterator _start;//���ݴ洢�׵�ַ
	iterator _finish;//��Ч����β����ַ��һ����ַ��
	iterator _end_of_storage;//����β��ַ��һ����ַ
};




