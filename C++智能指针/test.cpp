#define _CRT_SECURE_NO_WARNINGS 1
#include"smart_pointer.hpp"

//int div1(int a,int b)
//{
//	if (b == 0)
//		throw invalid_argument("除0错误");
//	return a / b;
//}
//
//void Func()
//{
//	smart_ptr<int>p1( new int);
//	smart_ptr<int>p2 (new int);
//	*p1 = 100;
//	*p2 = 0;
//	cout << div1(*p1,*p2) << endl;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}

//int main()
//{
//	smart_ptr<int> sm_ptr(new int);
//
//	
//	return 0;
//}

//struct Date
//{
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	smart_ptr<int> sp1(new int);
//	*sp1 = 10;
//	cout << *sp1 << endl;
//	smart_ptr<Date> sparray(new Date);
//	// 需要注意的是这里应该是sparray.operator->()->_year = 2018;
//	// 本来应该是sparray->->_year这里语法上为了可读性，省略了一个->
//	sparray->_year = 2018;
//	sparray->_month = 1;
//	sparray->_day = 1;
//
//	cout << sparray->_year << ":" << sparray->_month << ":" << sparray->_day << endl;
//	return 0;
//}

//int main()
//{
//	ikun::myatuo_ptr<int> pint(new int);
//	*pint = 100;
//	ikun::myatuo_ptr<int> pint1(new int);
//	pint1 = pint;// 管理权转移
//	cout << *pint1 << endl;
//	cout << *pint << endl;//指针悬空，对空指针解引用
//
//	return 0;
//}

//struct ListNode
//{
//	int _data;
//	ikun::myweak_ptr<ListNode> _prev;
//	ikun::myweak_ptr<ListNode> _next;
//	~ListNode() { cout << "~ListNode()" << endl; }
//};

//int main()
//{
//	shared_ptr<ListNode> n1(new ListNode);
//	shared_ptr<ListNode> n2(new ListNode);
//	n1->_next = n2;
//	n2->_prev = n1;
//
//	return 0;
//}

template<class T>
struct deletedate
{
	void operator()(T*ptr)
	{
		cout << "delete[] ptr" << endl;
		delete[] ptr;
	}
};

template<class T>
void deletemalloc(T* ptr)
{
	cout << "free (ptr)" << endl;
	free(ptr);
}

int main()
{
	//lambda
	ikun::myshare_ptr<FILE> ptr(fopen("test.c", "w+"), [](FILE* fptr) {fclose(fptr); cout << "fclose(fptr)" << endl; });
	//函数指针
	ikun::myshare_ptr<int> ptr1((int*)malloc(4),deletemalloc<int>);
	//仿函数
	ikun::myshare_ptr<int> ptr2(new int[10], deletedate<int>());
	//函数对象
	ikun::myshare_ptr<int> ptr3((int*)malloc(sizeof(int)*10), function<void(int*)>(deletemalloc<int>));

	return 0;
}
