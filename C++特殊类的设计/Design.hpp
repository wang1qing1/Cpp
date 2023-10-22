#pragma once
#include<iostream>
#include<vector>
#include<mutex>
#include<thread>
#include<string>
#include<Windows.h>
#include<atomic>
using namespace std;

class Bancopy
{
public:
	Bancopy(int x)
		:_x(x)
	{
	}

	Bancopy(Bancopy& obj) = delete;
	Bancopy& operator=(Bancopy& obj) = delete;
private:
	int _x;
};

//思路一，将析构函数私有化
//class HeapOnly
//{
//public:
//	HeapOnly(int x)
//		:_x(x)
//	{
//	}
//	void Destroy()
//	{
//		cout << "delete this" << endl;
//		delete this;
//	}
//private:
//	~HeapOnly()
//	{
//	}
//private:
//	int _x;
//};


//思路二，将构造函数私有化
class HeapOnly
{
public:
	static HeapOnly* CreateObj(int x)
	{
		return new HeapOnly(x);
	}

	void Destroy()
	{
		cout << "delete this" << endl;
		delete this;
	}

	HeapOnly(HeapOnly& Obj) = delete;
	HeapOnly& operator=(HeapOnly& Obj) = delete;

private:
	HeapOnly(int x)
		:_x(x)
	{
	}
private:
	int _x;
};

class StackOnly
{
public:
	static StackOnly CreateObj(int x)
	{
		return  StackOnly(x);
	}

	StackOnly(StackOnly&& Obj) 
	{
		_x = Obj._x;
	}

	StackOnly(StackOnly& Obj) = delete;
	StackOnly& operator=(StackOnly& Obj) = delete;

private:
	StackOnly(int x)
		:_x(x)
	{
	}
private:
	int _x;
};


 // C++98中构造函数私有化，派生类中调不到基类的构造函数。则无法继承
class base final
{
public:
	
	base()
	{}
private:
	
};
//
//class child :public base
//{
//
//private:
//	int _x;
//};

////单例模式——饿汉模式
//class Singleton
//{
//public:
//	static Singleton* GetSingleton()
//	{
//		return singleton;
//	}
//
//	vector<string> &get_sing_list()
//	{
//		return _sing_list;
//	}
//
//	void showlist()
//	{
//		for (auto e : _sing_list)
//		{
//			cout << e << endl;
//		}
//	}
//private:
//	//构造函数
//	Singleton()
//	{}
//	Singleton(Singleton const&) = delete;
//	Singleton& operator=(Singleton const&) = delete;
//private:
//	vector<string> _sing_list;
//	static Singleton* singleton;
//};
////初始化的是类内部成员，可以访问私有的构造函数
////在没有进入主函数的时候，单例对象已经实例化完成
//Singleton* Singleton::singleton = new Singleton;

//单例模式——懒汉模式
class Singleton
{
public:
	//static Singleton* GetSingleton()
	//{
	//	if (singleton == nullptr)//防止因为每次创建对象都要加锁带来的性能上的损耗
	//	{
	//		_mutex.lock();//防止多线程创建的时候，出现并发问题
	//		if (singleton == nullptr)
	//		{
	//			singleton = new Singleton;
	//		}
	//		_mutex.unlock();
	//	}
	//	return singleton;
	//}
	static atomic<int> i;
	static Singleton* GetSingleton()
	{		
		if (singleton == nullptr)
		{
			singleton = new Singleton;
		}
		return singleton;
	}

	vector<string> &get_sing_list()
	{
		return _sing_list;
	}

	void showlist()
	{
		for (auto e : _sing_list)
		{
			cout << e << endl;
		}
	}
private:
	//构造函数
	Singleton()
	{
		i++;
	}
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;
private:
	
	static mutex _mutex;
	vector<string> _sing_list;
	static Singleton* singleton ;
};
atomic<int> Singleton::i = 0;
Singleton* Singleton::singleton = nullptr;
mutex Singleton::_mutex;
