#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<list>
//#include"List.h"
using namespace std;
struct People
{
	string name;
	int age;
	int height;
};

struct TT
{
	TT()
	{

	}
	TT(int tmp)
		:_num(tmp)
	{

	}

	TT operator+(TT tmp)
	{
		return TT(tmp._num + _num);
	}
	int _num;
};
//int main()
//{
//	//{}初始化
//	int num1 = { 10 };
//	int num{ 100 };
//	string str{ "ckdjrhgf" };
//	string str1={ "ckdjrhgf" };
//	People pe{ "zhangsan",18,180 };
//	People pe1={ "zhangsan",18,180 };
//	int arr[]{ 1,2,3,4,5,6}; 
//	int arr1[] = { 1,2,3,4,5,6 };
//	list<int> li{ 1,2,3,4,5,6 };
//	list<int> li1={ 1,2,3,4,5,6 };
//
//	//std::initializer_list
//	auto in={ 1,2,3,4,5,6 };
//	cout << typeid(in).name()<< endl;
//	std::initializer_list<int> t;
//	//ikun::List<int> Li={ 1,2,3,4,5,6 };
//	//for (auto e : Li)
//	//{
//	//	cout << e << " ";
//	//}
//	//ikun::List<int>::itorator it = Li.begin();
//	
//
//	//关键字decltype将变量的类型声明为表达式指定的类型
//	int a = 10;
//	int b = 20;
//	decltype(a * b) c;
//	cout << typeid(c).name() << endl;
//	TT ca = 10;
//	TT cb = 20;
//	decltype(ca + cb) cc;
//	cout << typeid(cc).name() << endl;
//	
//	
//
//
//	return 0;
//}
int add(int x, int y) 
{
	return x + y;
}



//int main()
//{
//
//	//右值引用
//	//1.左值引用
//	int&& num = 10;
//	int&& num1 = num + 10;
//	int&& num2 = add(num1, num);
//
//	int a = 10;
//	int&& ya = move(a);
//
//	double x = 1.1, y = 2.2;
//	int&& rr1 = 10;
//	const double&& rr2 = x + y;
//	rr1 = 20;
//	cout << rr1 << endl;
//	int&& rr3 = move(a);
//	//rr2 = 5.5;
//
//	return 0;
//}

#include"my_string.h"
using namespace ikun;

//void _fun(const int&& a) { cout << "右值引用" << endl; }
//void _fun(int& a) { cout << "左值引用" << endl; }
//void _fun(int&& a) { cout << "右值引用" << endl; }
//void _fun(const int& a) { cout << "左值引用" << endl; }


//template<class T>
//void fun(T&& num)
//{
//	//此时的num，是一个左值
//	_fun(num);
//}

//template<class T>
//void fun(T&& num)
//{
//	//此时的num，是一个左值
//	_fun(forward<T>(num));
//}
//int main()
//{
//	String str("fsajuf");
//
//	String str1=str + "!";
//
//	int a = 10;
//	//int&& aa = a;
//	fun(10);
//	fun(a);
//	const int& cn = 1000;
//	fun(cn);
//
//
//	return 0;

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
		Insert(_head, std::forward<T>(x));
	}

	void PushFront(T&& x)
	{
		//Insert(_head->_next, x);
		Insert(_head->_next, std::forward<T>(x));
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
		// prev newnode pos
		prev->_next = newnode;
		
		newnode->_next = pos;
		pos->_prev = newnode;
	}
private:
	Node* _head;
};
int main()
{
	List<ikun::String> lt;
	lt.PushBack("1111");
	lt.PushFront("2222");
	return 0;
}