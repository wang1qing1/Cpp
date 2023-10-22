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

//˼·һ������������˽�л�
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


//˼·���������캯��˽�л�
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


 // C++98�й��캯��˽�л����������е���������Ĺ��캯�������޷��̳�
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

////����ģʽ��������ģʽ
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
//	//���캯��
//	Singleton()
//	{}
//	Singleton(Singleton const&) = delete;
//	Singleton& operator=(Singleton const&) = delete;
//private:
//	vector<string> _sing_list;
//	static Singleton* singleton;
//};
////��ʼ���������ڲ���Ա�����Է���˽�еĹ��캯��
////��û�н�����������ʱ�򣬵��������Ѿ�ʵ�������
//Singleton* Singleton::singleton = new Singleton;

//����ģʽ��������ģʽ
class Singleton
{
public:
	//static Singleton* GetSingleton()
	//{
	//	if (singleton == nullptr)//��ֹ��Ϊÿ�δ�������Ҫ���������������ϵ����
	//	{
	//		_mutex.lock();//��ֹ���̴߳�����ʱ�򣬳��ֲ�������
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
	//���캯��
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
