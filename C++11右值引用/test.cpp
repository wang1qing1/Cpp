#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//int main()
//{
//	// 以下的p、b、c、*p都是左值
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//	// 以下几个是对上面左值的左值引用
//	int*& rp = p;
//	int& rb = b;
//	const int& rc = c;
//	int& pvalue = *p;
//	return 0;
//}

//int fmin(int a, int b)
//{
//	return a;
//}
//int main()
//{
//	double x = 1.1, y = 2.2;
//	// 以下几个都是常见的右值
//	10;
//	x + y;
//	fmin(x, y);
//	// 以下几个都是对右值的右值引用
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//	// 这里编译会报错：error C2106: “=”: 左操作数必须为左值
//	10 = 1;
//	x + y = 1;
//	fmin(x, y) = 1;
//	return 0;
//}

//int main()
//{
//	double x = 1.1, y = 2.2;
//	int&& rr1 = 10;
//	const double&& rr2 = x + y;
//	rr1 = 20;
//	rr2 = 5.5;  // 报错
//	return 0;
//}

//int main()
//{
//	// 左值引用只能引用左值，不能引用右值。
//	int a = 10;
//	int& ra1 = a;  // ra为a的别名
//	//int& ra2 = 10;  // 编译失败，因为10是右值
//	// const左值引用既可引用左值，也可引用右值。
//	const int& ra3 = 10;
//	const int& ra4 = a;
//	return 0;
//}

//int main()
//{
//	// 右值引用只能右值，不能引用左值。
//	int&& r1 = 10;
//	// error C2440: “初始化”: 无法从“int”转换为“int &&”
//	// message : 无法将左值绑定到右值引用
//	int a = 10;
//	int&& r2 = a;
//	// 右值引用可以引用move以后的左值
//	int&& r3 = std::move(a);
//	return 0;
//}


#include<cassert>
namespace ikun
{
	class string
	{
	public:
		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			//cout << "string(char* str)构造函数" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝—拷贝构造" << endl;
			string tmp(s._str);
			swap(tmp);
		}
		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝—赋值重载" << endl;
			string tmp(s);
			swap(tmp);
			return *this;
		}
		// 移动构造
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- 移动语义—移动构造" << endl;
			swap(s);
		}
		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动语义—移动赋值" << endl;
			swap(s);
			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		// string+
		string operator+(char ch)
		{
			ikun::string str(this->c_str());
			str.push_back(ch);
			return str;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // 不包含最后做标识的\0
	};
}


//int main()
//{
//	ikun::string str("1111");
//	ikun::string str1 = str + 'A';
//
//	return 0;
//}

//int main()
//{
//	ikun::string str("123");
//	printf("str:%p\n", str.c_str());
//	//将str强制变成右值
//	ikun::string str1(move(str));
//	printf("str:%p\n", str1.c_str());
//
//	return 0;
//}
#include<list>

//int main()
//{
//	list<ikun::string> lt;
//	ikun::string s1("1111");
//	// 这里调用的是拷贝构造
//	lt.push_back(s1);
//	// 下面调用都是移动构造
//	lt.push_back("2222");
//	lt.push_back(std::move(s1));
//	return 0;
//}



//str1 = ikun::string("123");
//str = ikun::string("123");

//void Fun(int& x) { cout << "左值引用" << endl; }
//void Fun(const int& x) { cout << "const 左值引用" << endl; }
//void Fun(int&& x) { cout << "右值引用" << endl; }
//void Fun(const int&& x) { cout << "const 右值引用" << endl; }
//// 模板中的&&不代表右值引用，而是万能引用，其既能接收左值又能接收右值。
//// 模板的万能引用只是提供了能够接收同时接收左值引用和右值引用的能力，
//// 但是引用类型的唯一作用就是限制了接收的类型，后续使用中都退化成了左值，
//// 我们希望能够在传递过程中保持它的左值或者右值的属性, 就需要用我们下面学习的完美转发
//template<typename T>
//void PerfectForward(T&& t)
//{
//	Fun(t);
//}
//int main()
//{
//	PerfectForward(10); // 右值
//	int a;
//	PerfectForward(a); // 左值
//	PerfectForward(std::move(a)); // 右值
//	const int b = 8;
//	PerfectForward(b); // const 左值
//	PerfectForward(std::move(b)); // const 右值
//	return 0;
//}

//void Fun(int& x) { cout << "左值引用" << endl; }
//void Fun(const int& x) { cout << "const 左值引用" << endl; }
//void Fun(int&& x) { cout << "右值引用" << endl; }
//void Fun(const int&& x) { cout << "const 右值引用" << endl; }
//
//template<typename T>
//void PerfectForward(T&& t)
//{
//	// std::forward<T>(t)在传参的过程中保持了t的原生类型属性。
//	Fun(std::forward<T>(t));
//}
//int main()
//{
//	PerfectForward(10); // 右值
//	int a;
//	PerfectForward(a); // 左值
//	PerfectForward(std::move(a)); // 右值
//	const int b = 8;
//	PerfectForward(b); // const 左值
//	PerfectForward(std::move(b)); // const 右值
//	return 0;
//	
//}

template<class T>
struct ListNode
{
	ListNode* _next = nullptr;
	ListNode* _prev = nullptr;
	T _data;
};
template<class T>
class List
{
	typedef ListNode<T> Node;
public:
	List()
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	}
	void PushBack(T&& x)
	{
		//Insert(_head, x);
		Insert(_head, std::forward<T>(x));// 关键位置
	}
	void PushFront(T&& x)
	{
		//Insert(_head->_next, x);
		Insert(_head->_next, std::forward<T>(x));// 关键位置
	}
	void Insert(Node* pos, T&& x)
	{
		Node* prev = pos->_prev;
		Node* newnode = new Node;
		newnode->_data = std::forward<T>(x); // 关键位置
		// prev newnode pos
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = pos;
		pos->_prev = newnode;
	}
	void Insert(Node* pos, const T& x)
	{
		Node* prev = pos->_prev;
		Node* newnode = new Node;
		newnode->_data = x; // 关键位置

		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = pos;
		pos->_prev = newnode;
	}
private:
	Node* _head;
};