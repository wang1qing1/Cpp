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
			cout << "String(const char* str)---��������" << endl;
			_str = new char[_capacity];
			strcpy(_str, str);
		}

		String(const String& str)
		{
			cout << "String(const String& str)---��������" << endl;
			_size = str._size;
			_capacity = str.capacity();
			_str = new char[_capacity];
			strcpy(_str, str._str);
		}

		String(String&& str)
		{
			cout << "String(String&&str)---�ƶ�����" << endl;
			swap(str);
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
		//��С�Ƚ� String ���� �� String����Ƚ�
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

		//��С�Ƚ� String���� �� �ַ��� �Ƚ�
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

		// �ƶ���ֵ
		String& operator=(String&& s)
		{
			cout << "String& operator=(string&& s) -- �ƶ�����" << endl;
			swap(s);
			return *this;
		}

		String operator+(const char* s)
		{
			String tmp(*this);
			tmp += s;
			return tmp;
		}


		//+=�����
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
			//Ų������
			//pos=0ʱ�������⵱end=-1ʱ������ʱ�޷����������ʳ�ͻ
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
			//Ų������
			//pos=0ʱ�������⵱end=-1ʱ������ʱ�޷����������ʳ�ͻ
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

		//	// Ų������
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

		//	// ��������
		//	strncpy(_str + pos, str, len);
		//	_size += len;
		//	return *this;
		//}

		//�ַ�������
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		//����
		void swap(String& str)
		{
			std::swap(_str, str._str);
			std::swap(_size, str._size);
			std::swap(_capacity, str._capacity);
		}
		//����
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

		//ɾ��ָ��λ��ָ�����ȵ��ַ�
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

