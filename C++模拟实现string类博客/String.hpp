#pragma once
#include<cstring>
#include<iostream>
#include<cassert>
using namespace std;
class String
{
public:

	//String()
	//	:_str(new char[1]),_size(0),_capacity(0)
	//{
	//	_str[0] = '\0';
	//}

	//String(const char* str)
	//	:_size(strlen(str))
	//{
	//	_capacity = _size == 0 ? 3 : _size;
	//	_str = new char[_capacity + 1];//��ʵ�ʿ��ٿռ��ʱ�򣬶࿪һ���ֽڣ����ڴ洢��\0��
	//	strcpy(_str, str);
	//}


	//����Ĭ�Ϲ��죬���ܽ��ճ����ַ�������
	String(const char* str = "")
		:_size(strlen(str))
	{
		_capacity = _size == 0 ? 3 : _size;
		_str = new char[_capacity+1];//��ʵ�ʿ��ٿռ��ʱ�򣬶࿪һ���ֽڣ����ڴ洢��\0��
		//��str���ݿ�����_str��
		strcpy(_str, str);
	}

	//��������:ʹ��һ���Ѿ��е�String��������ʼ����һ��String����
	//1.ע�����
	String(const String& s)
	{
		_capacity = s._capacity;
		_size = s._size;
		_str = new char[_capacity+1];
		strcpy(_str, s._str);
	}

	//operator[]��ͨ�������
	char& operator[](const int index)
	{
		assert(index >= 0 && index < _size);
		return _str[index];
	}
	//operator[] const �������,�Ҳ������޸�
	const char& operator[](const int index) const
	{
		assert(index >= 0 && index < _size);
		return _str[index];
	}
	
	// operator=���ظ�ֵ�����
	String& operator=(const String& s)
	{
		//ע�⣺���ﲻ����ʹ��realloc�����ݣ���Ϊ����ʹ��new�����ٵĿռ䣬ֱ��new�µĿռ���п�����
		//ϸ�ڣ�����Ҫ�����Ƚ����ݿ�������ʱ��tmp��ٽ�_str�ͷŵ������ʹ�����Ƚ�_str�ͷ��ˣ�
		//�����new�Ľ�����ֲ�����ǳ����쳣������ԭ���ݶ�ʧ��
		char* tmp = new char[s.capacity() + 1];
		_size = s.size();
		_capacity = s.capacity();
		strcpy(tmp, s._str);
		delete[] _str;
		_str = tmp;
		return *this;
	}




	const int size() 
	{
		return _size;
	}

	const int size() const
	{
		return _size;
	}

	const int capacity() const
	{
		return _capacity;
	}

	const int capacity() 
	{
		return _capacity;
	}

	const char* c_str()
	{
		return _str;
	}

	~String()
	{
		delete[] _str;
		_size = _capacity = 0;
 	}



private:
	char* _str;
	int _size;
	int _capacity;

	static size_t npos;
};

static size_t npos = -1;

