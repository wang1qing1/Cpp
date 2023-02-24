#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<iostream>
using namespace std;
namespace ikun {

	class String
	{
	public:
		//���캯������������Σ����������ǿմ�
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
			_str = new char[_capacity];
			strcpy(_str, str);
		}

		String(const String& str)
		{
			_size = str._size;
			_capacity = str.capacity();
			_str = new char[_capacity];
			strcpy(_str, str._str);
		}
		//��������
		~String()
		{
			delete[] _str;
			_size = _capacity = 0;
		}
		//����C�ַ���
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
		// [] Ԫ�ط�����
		char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}
		char& operator[](size_t pos)
		{
			return _str[pos];
		}
		
		//��������()
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

		//��ֵ����
		String& operator=(const String& str)
		{
			if (this != &str) //����str = str ����Ҫ������;
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

		//������


		//+=�����
		String& operator+=(const String& str)
		{
			if (_size + str.size() >= _capacity)
			{
				reserve(_size + str.size());
				_size += str.size();
				_capacity = _size + str.size()+1;
			}
			strncpy(_str+_size, str.c_str(), str.size());
			return *this;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const int mpos = -1;
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
}

