#pragma once
#include<iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<stdio.h>
#include<functional>

using namespace std;

namespace ikun
{
	template<class T>
	class smart_ptr
	{
	public:
		smart_ptr(T* ptr)
			:_ptr(ptr)
		{
		}

		T& operator*() { return *_ptr; }
		T* operator->() { return _ptr; }

		~smart_ptr()
		{
			cout << "delete _ptr" << endl;
			if (_ptr)
				delete _ptr;
		}

	private:
		T* _ptr;
	};

	template<class T>
	class myatuo_ptr
	{
	public:
		myatuo_ptr(T* ptr)
			:_ptr(ptr)
		{
		}

		//像指针一样访问
		T& operator*() { return *_ptr; }
		T* operator->() { return _ptr; }


		//管理权转移，一次只能有一个对象管理资源
		myatuo_ptr& operator=(myatuo_ptr& ptr)
		{
			//不是自己给自己赋值
			if (this != &ptr)
			{
				//1.先释放当前管理的资源
				if (_ptr) 
				{
					delete _ptr;
				}
				//2.转移管理权
				_ptr = ptr._ptr;
				ptr._ptr = nullptr;
			}
			return *this;
		}

		~myatuo_ptr()
		{
			cout << "delete _ptr" << endl;
			if (_ptr)
				delete _ptr;
		}

	private:
		T* _ptr;
	};

	template<class T>
	class myunique_ptr
	{
	public:
		myunique_ptr(T* ptr)
			:_ptr(ptr)
		{
		}

		//像指针一样访问
		T& operator*() { return *_ptr; }
		T* operator->() { return _ptr; }
		
		//强制不生成赋值运算符和拷贝构造
		myunique_ptr& operator=(myunique_ptr& ptr) = delete;
		myunique_ptr(myunique_ptr& ptr) = delete;
		

		~myunique_ptr()
		{
			cout << "delete _ptr" << endl;
			if (_ptr)
				delete _ptr;
		}

	private:
		T* _ptr;
	};


	template<class T>
	class myshare_ptr
	{
	public:
		myshare_ptr(T* ptr=nullptr)
			:_ptr(ptr),
			_pcount(new int(1)),
			_mutex(new mutex)
		{
		}

		myshare_ptr(T* ptr, function<void(T*)> func_delete)
			:_ptr(ptr),
			_pcount(new int(1)),
			_mutex(new mutex),
			_func_delete(func_delete)
		{
		}

		//像指针一样访问
		T& operator*() { return *_ptr; }
		T* operator->() { return _ptr; }

		//拷贝构造
		myshare_ptr(myshare_ptr& ptr)
			:_ptr(ptr._ptr),
			_pcount(ptr._pcount),
			_mutex(ptr._mutex),
			_func_delete(ptr._func_delete)
		{
			addref();
		}

		//赋值重载运算符
		myshare_ptr& operator=(myshare_ptr& ptr)
		{
			//this!=&ptr
			if (_ptr != ptr._ptr)
			{
				release();
				_ptr = ptr._ptr;
				_pcount = ptr._pcount;
				_mutex = ptr._mutex;
				_func_delete = ptr._func_delete;
				ptr.addref();
			}
			return *this;
		}

		~myshare_ptr()
		{
			release();
		}

	private:
		//对引用计数的++
		void addref()
		{
			_mutex->lock();
			(*_pcount)++;
			_mutex->unlock();
		}
		//对引用计数的--
		void release()
		{
			_mutex->lock();
			(*_pcount)--;
			bool deletemutex = 0;
			if ((*_pcount) == 0)
			{
				if (_ptr)
				{
					_func_delete(_ptr);
					delete _pcount;
					deletemutex = 1;
				}
			}
			_mutex->unlock();
			if (deletemutex)
			{
				delete _mutex;
			}
		}

	private:
		T* _ptr;
		int* _pcount;
		mutex* _mutex;
		function<void(T*)> _func_delete = [](T* ptr) {delete ptr};
	};


	template<class T>
	class myweak_ptr
	{
	public:
		myweak_ptr()
			:_ptr(nullptr)
		{}

		myweak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get())
		{}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};
}

