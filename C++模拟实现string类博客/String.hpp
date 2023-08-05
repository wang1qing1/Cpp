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
	//	_str = new char[_capacity + 1];//在实际开辟空间的时候，多开一个字节，用于存储‘\0’
	//	strcpy(_str, str);
	//}


	//既是默认构造，又能接收常量字符串构造
	String(const char* str = "")
		:_size(strlen(str))
	{
		_capacity = _size == 0 ? 3 : _size;
		_str = new char[_capacity+1];//在实际开辟空间的时候，多开一个字节，用于存储‘\0’
		//将str数据拷贝到_str里
		strcpy(_str, str);
	}

	//拷贝构造:使用一个已经有的String对象来初始化另一个String对象。
	//1.注意深拷贝
	String(const String& s)
	{
		_capacity = s._capacity;
		_size = s._size;
		_str = new char[_capacity+1];
		strcpy(_str, s._str);
	}

	//operator[]普通对象调用
	char& operator[](const int index)
	{
		assert(index >= 0 && index < _size);
		return _str[index];
	}
	//operator[] const 对象调用,且不允许修改
	const char& operator[](const int index) const
	{
		assert(index >= 0 && index < _size);
		return _str[index];
	}
	
	// operator=重载赋值运算符
	String& operator=(const String& s)
	{
		//注意：这里不可以使用realloc来扩容，因为我们使用new来开辟的空间，直接new新的空间进行拷贝。
		//细节：我们要尽量先将数据拷贝到临时的tmp里，再将_str释放掉，如果使用首先将_str释放了，
		//如果在new的结果出现差错，就是出发异常，导致原数据丢失。
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

