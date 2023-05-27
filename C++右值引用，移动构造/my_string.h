#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<iostream>
using namespace std;
namespace ikun {

	class String
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		//构造函数，如果不传参，即创建的是空串
		String()
			:_size(0),
			_capacity(3)
		{
			_str = new char[_capacity];
			_str[0] = '\0';
		}

		String(const char* str)
			:_size(strlen(str)),
			_capacity(strlen(str)+1)
		{
			cout << "String(const char* str)---拷贝构造" << endl;
			_str = new char[_capacity];
			strcpy(_str, str);
		}

		String(const String& str)
		{
			cout << "String(const String& str)---拷贝构造" << endl;
			_size = str._size;
			_capacity = str.capacity();
			_str = new char[_capacity];
			strcpy(_str, str._str);
		}

		String(String&& str)
		{
			cout << "String(String&&str)---移动构造" << endl;
			swap(str);
		}
		//析构函数
		~String()
		{
			delete[] _str;
			_size = _capacity = 0;
		}
		//返回C字符串
		char* c_str() const
		{
			return _str;
		}
		char* c_str()
		{
			return _str;
		}
		size_t size()
		{
			return _size;
		}
		size_t size()const
		{
			return _size;
		}
		size_t capacity()
		{
			return _capacity;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		// [] 元素符重载
		char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}
		char& operator[](size_t pos)
		{
			return _str[pos];
		}
		
		//设置容量()
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				_capacity = n;
				char* tmp = new char[_capacity+1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
			}
		}

		//赋值重载
		String& operator=(const String& str)
		{
			if (this != &str) //避免str = str 不必要的消耗;
			{
				char* tmp = new char[str.capacity()];
				strcpy(tmp, str.c_str());
				_size = str.size();
				_capacity = str.capacity();
				delete[] _str;
				_str = tmp;
			}
			return *this;
		}

		//迭代器

		iterator begin()
		{
			return _str;
		}
		const_iterator begin() const
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
		//大小比较 String 对象 和 String对象比较
		bool operator==(const String& str)
		{
			return strcmp(_str, str.c_str())==0;
		}

		bool operator>(const String& str)
		{
			return strcmp(_str, str.c_str()) > 0;
		}

		bool operator>=(const String& str)
		{
			return *this == str || *this > str;
		}

		bool operator<(const String& str)
		{
			return !(*this >= str);
		}

		bool operator<=(const String& str)
		{
			return !(*this > str);
		}

		//大小比较 String对象 和 字符串 比较
		bool operator==(const char* str)
		{
			return strcmp(_str, str) == 0;
		}

		bool operator>(const char* str)
		{
			return strcmp(_str, str) > 0;
		}

		bool operator>=(const char* str)
		{
			return *this == str || *this > str;
		}

		bool operator<(const char* str)
		{
			return !(*this >= str);
		}
		bool operator<=(const char* str)
		{
			return !(*this > str);
		}

		// 移动赋值
		String& operator=(String&& s)
		{
			cout << "String& operator=(string&& s) -- 移动语义" << endl;
			swap(s);
			return *this;
		}

		String operator+(const char* s)
		{
			String tmp(*this);
			tmp += s;
			return tmp;
		}


		//+=运算符
		String& operator+=(const String& str)
		{
			if (_size + str.size() >= _capacity)
			{
				reserve(_size + str.size());
				//_capacity = _size + str.size()+1;
			}
			strncpy(_str+_size, str.c_str(), str.size()+1);
			_size += str.size();
			return *this;
		}

		String& operator+=(const char* str)
		{
			if (_size + strlen(str) >= _capacity)
			{
				reserve(_capacity*2);
			}
			strncpy(_str + _size, str, strlen(str) + 1);
			_size += strlen(str);
			return *this;
		}

		String& operator+=(const char ch)
		{
			if (_size + 1 >= _capacity)
			{
				reserve(_capacity*2);

			}
			_str[_size++] = ch;
			_str[_size] = '\0';
			return *this;
		}

	
		String& push_bank(const char ch)
		{
			*this += ch;
			return *this;
		}

		String& append(const char* str)
		{
			*this += str;
			return *this;
		}

		String& insert( size_t pos,const char* str)
		{
			int len = strlen(str);
			assert(pos <= _size);
			if (_size + len >=_capacity)
			{
				reserve(_capacity * 2);
			}
			//挪动数据
			//pos=0时，有问题当end=-1时，由于时无符号数，访问冲突
			//for (size_t end = _size - 1; end >= pos; end--)
			//{
			//	_str[end + len] = _str[end];
			//}
			for (size_t end = _size + len; end >= pos + len; end--)
			{
				_str[end] = _str[end - len];
			}
			strncpy(_str + pos , str, len);
			_size += len;
			return *this;
		}
		String& insert(size_t pos, const char ch)
		{
			assert(pos < _size);
			if (_size + 1 >= _capacity)
			{
				reserve(_capacity * 2);
			}
			//挪动数据
			//pos=0时，有问题当end=-1时，由于时无符号数，访问冲突
			//for (size_t end = _size; end >= pos; end--)
			//{
			//	_str[end + 1] = _str[end];
			//}
			for (size_t end = _size + 1; end >= pos + 1; end--)
			{
				_str[end] = _str[end - 1];
			}
			_str[pos] = ch;

			return *this;

		}
		//String& insert(size_t pos, const char* str)
		//{
		//	assert(pos <= _size);

		//	size_t len = strlen(str);

		//	if (_size + len > _capacity)
		//	{
		//		reserve(_size + len);
		//	}

		//	// 挪动数据
		//	size_t end = _size + len;
		//	while (end > pos + len - 1)
		//	{
		//		_str[end] = _str[end - len];
		//		--end;
		//	}

		//	/*size_t end = _size;
		//	for (size_t i = 0; i < _size + 1; ++i)
		//	{
		//		_str[end + len] = _str[end];
		//		--end;
		//	}*/

		//	// 拷贝插入
		//	strncpy(_str + pos, str, len);
		//	_size += len;
		//	return *this;
		//}

		//字符串清理
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		//交换
		void swap(String& str)
		{
			std::swap(_str, str._str);
			std::swap(_size, str._size);
			std::swap(_capacity, str._capacity);
		}
		//查找
		size_t find( const char ch,size_t pos = 0)
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
			const char* tmp = strstr(_str+pos, str);
			if (tmp == nullptr)
			{
				return npos;
			}
			return tmp - _str;
		}
		size_t find(const String&str, size_t pos = 0)
		{
			assert(pos < _size);
			const char* tmp = strstr(_str + pos, str._str);
			if (tmp == nullptr)
			{
				return npos;
			}
			return tmp - _str;
		}

		//删除指定位置指定长度的字符
		String& erase(size_t pos = 0, size_t len = npos)
		{
			if (pos + len > _size || len == pos)
			{
				_str[pos] = '\0';
				_size = 0;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size = pos-len;
			}
			return *this;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const size_t npos = -1;
	};
	ostream& operator<<(ostream& out, const String& str)
	{
		/*for (int i = 0; i < str.size(); i++)
		{
			out << str[i];
		}*/

		out << str.c_str() << endl;
		return out;
	}
	istream& operator>>(istream& in, String& str)
	{
		str.clear();
		char ch;
		ch = in.get();
		int i = 0;
		char tmp[128];
		while (ch != ' ' && ch != '\n')
		{
			tmp[i++] = ch;
			if (i == 127)
			{
				tmp[127] = '\0';
				str += tmp;
				i = 0;
			}
			ch = in.get();
		}

		if (i != 0)
		{
			tmp[i] = '\0';
			str += tmp;
		}
		return in;
	}

}

