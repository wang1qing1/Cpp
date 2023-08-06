#pragma once
#include<cstring>
#include<iostream>
#include<cassert>
using namespace std;
class String
{
public:
	typedef char* iterator;
	typedef const char* const_iterator;
	iterator begin()
	{
		return _str;
	}
	iterator end()
	{
		return _str + _size;
	}
	const_iterator begin()const
	{
		return _str;
	}
	const_iterator end()const
	{
		return _str + _size;
	}

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
	char& operator[](const size_t index)
	{
		assert(index >= 0 && index < _size);
		return _str[index];
	}
	//operator[] const 对象调用,且不允许修改
	const char& operator[](const size_t index) const
	{
		assert(index >= 0 && index < _size);
		return _str[index];
	}
	
	// operator=重载赋值运算符
	String& operator=(const String& s)
	{
		if (this != &s)//str=str时无需多余的运算
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
	}
	//重新设置容量
	void reserve(size_t capacity)
	{
		if (capacity > _capacity)//不允许容量的缩减
		{
			char* tmp = new char[capacity + 1];
			_capacity = capacity;
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
		}
	}

	void push_back(char ch)
	{
		//容量不足时
		if (_size + 1 >= _capacity)
		{
			reserve(_capacity * 2);
		}
		_str[_size++] = ch;
		_str[_size] = '\0';
	}

	void append(const char* s)
	{
		int len = strlen(s);
		if (len + _size >= _capacity)
		{
			reserve(_capacity + len);
		}
		strcpy(_str + _size, s);
		_size += len;
	}

	String& operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}

	String& operator+=(const char* s)
	{
		append(s);
		return *this;
	}

	String& operator+=(const String& s )
	{
		append(s._str);
		return *this;
	}

	void insert(size_t index, char ch)
	{
		//判断位置是否合法
		assert(index >= 0 && index < _size);
		//判断是否需要扩容
		if (_size + 1 >= _capacity)
		{
			reserve(_capacity * 2);
		}
		//挪动数据
		int end = _size+1;
		//注意:这里的end时int，index是size_t类型，进行比较的时候
		//会发生类型提升，int --> size_t,当index=0，循环结束的条件是end为-1，
		// 但是由于类型提升，end实际在比较的时候的值是一个很大的数。因此仍会进入循环。
		//int end = _size;
		//while (end >= index)
		//{
		//	_str[end + 1] = _str[end];
		//}
		//如果我们代码这样写就会避免当index=0时，end的结束条件是-1。
		while (end >= index+1)
		{
			_str[end] = _str[end - 1];
			end--;
		}
		//插入数据ch	
		_str[index] = ch;
		_size++;
	}

	void insert(size_t index, const char* str)
	{
		//判断位置是否合法
		assert(index >= 0 && index < _size);
		int len = strlen(str);
		if (len + _size >= _capacity)
		{
			reserve(_capacity + len);
		}
		//挪动数据
		int end = _size+len;
		while (end >= index + len)
		{
			_str[end] = _str[end-len];
			end--;
		} 
		//插入数据
		int j = 0;
		for (int i = index; i < index + len; i++)
		{
			_str[i] = str[j++];
		}
		_size += len;
		
	}

	//删除pos位置之后的len个字符
	void erase(size_t pos, size_t len = npos)
	{

		assert(pos >= 0 && pos < _size);
		if (pos + len > _size || len == npos)
		{
			_str[pos] = '\0';
			_size = pos ;
			return;
		}
		//1.挪动数据
		strcpy(_str + pos, _str + pos + len);
		//2.挪动数据
		//int index = pos;
		//while (index + len < _size)
		//{
		//	_str[index] = _str[index + len];
		//	index++;
		//}
		_size -= len;
	}

	void swap(String &str)
	{
		std::swap(_size, str._size);
		std::swap(_capacity, str._capacity);
		std::swap(_str, str._str);
	}

	size_t find( const char ch, size_t pos = 0)
	{
		assert(pos < _size);
		for (int i = pos; i < _size; i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return npos;
	}

	size_t find(const char* str, size_t pos = 0)
	{
		assert(pos < _size);
		char* pindex = strstr(_str + pos, str);
		if (pindex == nullptr)
		{
			return npos;
		}
		else
		{
			return pindex - _str;
		}
	}

	void clear()
	{
		_str[0] = '\0';
		_size = 0;
	}


	//相等
	bool operator==(const String& s)const
	{
		return strcmp(_str, s._str)==0;
	}
	//小于
	bool operator<(const String& s)const
	{
		return  strcmp(_str, s._str) < 0;
	}
	//不等于
	bool operator!=(const String& s)const
	{
		return !(*this == s);
	}
	//小于等于
	bool operator<=(const String& s)const
	{
		return  *this == s || *this < s;
	}
	//大于
	bool operator>(const String& s)const
	{
		return  !( * this == s || *this < s);
	}
	//大于等于
	bool operator>=(const String& s)const
	{
		return  *this == s || *this > s;
	}

	const size_t size() 
	{
		return _size;
	}

	const size_t size() const
	{
		return _size;
	}

	const size_t capacity() const
	{
		return _capacity;
	}

	const size_t capacity()
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
	size_t _size;
	size_t _capacity;
	static const size_t npos = -1;
};

//重载流输出
ostream& operator<<(ostream& out,const String& str)
{
	for (auto e : str)
	{
		cout << e;
	}
	return out;
}

////1.重载流输入
//istream& operator>>(istream& in, String& str)
//{
//	str.clear();
//	char ch = in.get();
//	while (ch != ' ' && ch != '\n')
//	{
//		str.push_back(ch);
//		ch = in.get();
//	}
//
//	return in;
//}
//2.重载流输入
istream& operator>>(istream& in, String& str)
{
	str.clear();
	char buffer[128];
	char ch = in.get();
	int i = 0;
	while (ch != ' ' && ch != '\n')
	{
		buffer[i++] = ch;
		if (i == 127)
		{
			buffer[i] = '\0';
			str += buffer;
			i = 0;
		}
		ch = in.get();
	}
	if (i != 0)
	{
		buffer[i] = '\0';
		str += buffer;
	}

	return in;
}



//std提供的交换函数
template<class T>
void swap(T& e1,T& e2)
{
	T tmp = e1;
	e1 = e2;
	e2 = tmp;
}



