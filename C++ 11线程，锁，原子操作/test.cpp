#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<thread>
#include<string>
using namespace std;

//void func1(string str)
//{
//	cout << str << endl;
//}
//struct func2
//{
//	void operator()(string str)
//	{
//		cout << str << endl;
//	}
//};
//
//int main()
//{
//	std::thread t1(func1, "函数指针");
//	std::thread t2(func2(), "仿函数");
//	std::thread t3([](string str){cout << str << endl; }, "lambda");
//	t1.join();
//	t2.join();
//	t3.join();
//	return 0;
//}

//#include <thread>
//void ThreadFunc1(int& x)
//{
//	x += 10;
//}
//void ThreadFunc2(int* x)
//{
//	*x += 10;
//}
//int main()
//{
//	int a = 10;
//	int b = 10;
//	// 如果想要通过形参改变外部实参时，必须借助std::ref()函数
//	thread t2(ThreadFunc1, std::ref(a));
//	t2.join();
//	cout << a << endl;
//	 //地址的拷贝
//	thread t3(ThreadFunc2, &b);
//	t3.join();
//	cout << b << endl;
//	return 0;
//}


//#include <iostream>
//#include <thread>
//#include<atomic>
//using namespace std;
////unsigned long sum = 0;
//atomic_int sum = 0;
//
//
//class Test
//{
//public:
//	Test(int a)
//		:_a(a)
//	{}
//
//	int operator++(int)
//	{
//		return _a++;
//
//	}
//
//private:
//	int _a;
//};
//atomic<Test> t(0);
//void fun(atomic<Test>* t)
//{
//	for (size_t i = 0; i < 1000000; ++i)
//		(*t).load()++;
//}
//int main()
//{
//	cout << "Before joining,sum = " << t.load()++ << std::endl;
//	thread t1(fun, &t);
//	thread t2(fun, &t);
//	t1.join();
//	t2.join();
//	cout << "After joining,sum = " << t.load()++ << std::endl;
//	return 0;
//}





#include <thread>
#include <mutex>
int number = 0;
mutex g_lock;
int ThreadProc1()
{
	for (int i = 0; i < 100; i++)
	{
		lock_guard<mutex> lock(g_lock);//调用构造加锁，出作用域自动解锁
		++number;
		cout << "thread 1 :" << number << endl;
		
	}
	return 0;
}
int ThreadProc2()
{
	for (int i = 0; i < 100; i++)
	{
		lock_guard<mutex> lock(g_lock);//调用构造加锁，出作用域自动解锁
		--number;
		cout << "thread 2 :" << number << endl;
	}
	return 0;
}

int main()
{
	thread t1(ThreadProc1);
	thread t2(ThreadProc2);
	t1.join();
	t2.join();
	cout << "number:" << number << endl;
	system("pause");
	return 0;
}