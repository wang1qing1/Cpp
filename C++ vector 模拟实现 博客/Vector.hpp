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

	//1.Vector<T> v(5,10);����һ��Vector���ҳ�ʼ��ǰ5��ֵΪ10
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

	//2.��������ʼ����[frist,lest)
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

	//3.��ֹ���캯�����ó�ͻ
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
		//�������ǽ�����һ��һ��push��ȥ���������ǽ���push_back�ײ�����ʱ��
		//��ʹ��string�ĸ�ֵ���죬��������
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
	//	//���򲻿���ֱ�Ӱ������ƿ���
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
		//��֧���������󣬲�֧��������С
		if (capacity() < capa)
		{
			size_t sz = size();
			iterator tmp = new T[capa];
			//���嵱ǰ���Ƿ��Ѿ���������������Ѿ�����������Ҫ�ͷ�֮ǰ��������
			//���֮ǰû���������裬���¿��Ŀռ�ָ�����ǵ�_start.
			if (_start)
			{
				//����ǧ���ܰ�������ֱ�ӿ���.
				//memcpy(tmp, _start, sizeof(T) * capacity());   /*ror ����*/
				for (int i = 0; i < size(); i++)
				{
					tmp[i]=_start[i];
				}
				delete[] _start;
			}
			//ע��:�˴�����ֱ��tmp+size()�����㣬��Ϊ�ڼ���_start��ʱ���Ѿ��Ѿ��ı���_start,
			//Ȼ������sizeҲ�����ǣ�׼ȷ��size��
			_start = tmp;
			_finish = tmp + sz;
			_end_of_storage = _start + capa;
		}
	}

	void resize(size_t n, T val = T())
	{	
		//1.n < size;-->ɾ������
		if (n < size())
		{
			_finish = _start + n;
		}
		//2.n > size
		else 
		{
			//(1)����ռ䲻�㣬��Ҫ����+��ʼ��
			if (n >= capacity())
			{
				reserve(n);
			}
			//(2)�ռ��㹻������Ҫ��ʼ��ʣ�µĿռ�
			while (_finish != _start + n)
			{
				*(_finish) = val;
				_finish++;
			}
		}
	}
	//�����÷���
	T& operator[](size_t pos)
	{
		//�ж�λ�õĺϷ���
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
		//��������ֱ�Ӹ�ֵ,�Զ�������ʹ�ø�ֵ����
		*(_finish) = val;
		_finish++;
	}

	bool empty() const 
	{
		return size() == 0;
	}

	void pop_back()
	{
		//�п�
		assert(!empty());
		//���ǽ��轫ά��β�����ݵ�ָ����ǰŲһλ��
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
		//������ʧЧ����,��¼pos�����λ��
		int len = pos - _start;
		if (_finish == _end_of_storage)
		{
			capacity() == 0 ? reserve(5) : reserve(capacity() * 2);
		}
		//���ݺ����¼���pos��û�з�������pos����
		pos = _start + len;
		iterator end = _finish;
		//����Ų��
		while (end >= pos)
		{
			(*end) = *(end - 1);
			end--;
		}
		_finish++;
		(*pos) = val;
		return pos;
	}

	//��ͨ������
	iterator begin()
	{
		return _start;
	}
	iterator end()
	{
		return _finish;
	}

	//const ������
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
	iterator _start;//���ݴ洢�׵�ַ
	iterator _finish;//��Ч����β����ַ��һ����ַ��
	iterator _end_of_storage;//����β��ַ��һ����ַ
	int tmp;
};




