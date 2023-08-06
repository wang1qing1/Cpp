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
	char& operator[](const size_t index)
	{
		assert(index >= 0 && index < _size);
		return _str[index];
	}
	//operator[] const �������,�Ҳ������޸�
	const char& operator[](const size_t index) const
	{
		assert(index >= 0 && index < _size);
		return _str[index];
	}
	
	// operator=���ظ�ֵ�����
	String& operator=(const String& s)
	{
		if (this != &s)//str=strʱ������������
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
	}
	//������������
	void reserve(size_t capacity)
	{
		if (capacity > _capacity)//����������������
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
		//��������ʱ
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
		//�ж�λ���Ƿ�Ϸ�
		assert(index >= 0 && index < _size);
		//�ж��Ƿ���Ҫ����
		if (_size + 1 >= _capacity)
		{
			reserve(_capacity * 2);
		}
		//Ų������
		int end = _size+1;
		//ע��:�����endʱint��index��size_t���ͣ����бȽϵ�ʱ��
		//�ᷢ������������int --> size_t,��index=0��ѭ��������������endΪ-1��
		// ������������������endʵ���ڱȽϵ�ʱ���ֵ��һ���ܴ����������Ի����ѭ����
		//int end = _size;
		//while (end >= index)
		//{
		//	_str[end + 1] = _str[end];
		//}
		//������Ǵ�������д�ͻ���⵱index=0ʱ��end�Ľ���������-1��
		while (end >= index+1)
		{
			_str[end] = _str[end - 1];
			end--;
		}
		//��������ch	
		_str[index] = ch;
		_size++;
	}

	void insert(size_t index, const char* str)
	{
		//�ж�λ���Ƿ�Ϸ�
		assert(index >= 0 && index < _size);
		int len = strlen(str);
		if (len + _size >= _capacity)
		{
			reserve(_capacity + len);
		}
		//Ų������
		int end = _size+len;
		while (end >= index + len)
		{
			_str[end] = _str[end-len];
			end--;
		} 
		//��������
		int j = 0;
		for (int i = index; i < index + len; i++)
		{
			_str[i] = str[j++];
		}
		_size += len;
		
	}

	//ɾ��posλ��֮���len���ַ�
	void erase(size_t pos, size_t len = npos)
	{

		assert(pos >= 0 && pos < _size);
		if (pos + len > _size || len == npos)
		{
			_str[pos] = '\0';
			_size = pos ;
			return;
		}
		//1.Ų������
		strcpy(_str + pos, _str + pos + len);
		//2.Ų������
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


	//���
	bool operator==(const String& s)const
	{
		return strcmp(_str, s._str)==0;
	}
	//С��
	bool operator<(const String& s)const
	{
		return  strcmp(_str, s._str) < 0;
	}
	//������
	bool operator!=(const String& s)const
	{
		return !(*this == s);
	}
	//С�ڵ���
	bool operator<=(const String& s)const
	{
		return  *this == s || *this < s;
	}
	//����
	bool operator>(const String& s)const
	{
		return  !( * this == s || *this < s);
	}
	//���ڵ���
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

//���������
ostream& operator<<(ostream& out,const String& str)
{
	for (auto e : str)
	{
		cout << e;
	}
	return out;
}

////1.����������
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
//2.����������
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



//std�ṩ�Ľ�������
template<class T>
void swap(T& e1,T& e2)
{
	T tmp = e1;
	e1 = e2;
	e2 = tmp;
}



