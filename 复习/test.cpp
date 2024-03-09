#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Person {
public:
	virtual void BuyTicket() { cout << "������Ʊ-ȫ��" << endl;  }
};
class child {
public:
	virtual void BuyTicket() { cout << "��ͯ��Ʊ-ȫ��" << endl;  }
};
class Student : public Person ,public child {
public:
	virtual void BuyTicket() { cout << "ѧ����Ʊ-���" << endl;  }
};

class Teacher :public Person
{
public:
	/*virtual void BuyTicket() { cout << "��ʦ��Ʊ-���" << endl; }*/
};


void Func(Person& p)
{
	p.BuyTicket();
}

//���ܱ���������
class Test
{
public:
	Test(){}
	Test& operator=(const Test& t) = delete;//C++11
	Test(const Test& tmp) = delete; //C++11
private:
	//Test& operator=(const Test& t);//C++98
	//Test(const Test& tmp);//C++98
};

//ֻ���ڶ��ϴ������ࡪ������һ
class OnlyHeap1
{
public:
	static OnlyHeap1* GetOnlyheap()
	{
		return new OnlyHeap1();
	}
	OnlyHeap1(const OnlyHeap1&) = delete;
	void destroy()
	{
		delete this;
	}
	~OnlyHeap1()
	{
		cout << "~OnlyHeap1()" << endl;
	}
private:
	OnlyHeap1() {}
	int b = 100;
};

//������
//��������˽�л���ջ�ϵĶ���Ͳ����Զ����٣�����������ջ�ϴ�������
class OnlyHeap
{
public:
	OnlyHeap() {}
	OnlyHeap(const OnlyHeap& obj) = delete;
	void destroy()
	{
		delete this;
	}
private:
	~OnlyHeap()
	{
		cout << "~OnlyHeap()" << endl;
	}
};


//ֻ����ջ�ϴ�������
//1.�������캯��
//2.�ṩ�����õ�ջ�϶��󷵻�
//����������ƶ�����ñ���һ�����Ա㴴���ö�����Է���
class OnlyStack
{
public:
	static OnlyStack GetOnlyStack()
	{
		return OnlyStack(10);
	}
	OnlyStack(OnlyStack&& obj)
	{
		swap(obj._x, _x);
	}
private:
	OnlyStack(int x):_x(x)
	{}
	OnlyStack& operator=(const OnlyStack& obj) = delete;
	OnlyStack(const OnlyStack& obj) = delete;
	int _x;
};

//����ģʽ��������ģʽ
class Config
{
public:
	static Config*  Getinstence()
	{
		return _config;
	}
	void print()
	{
		cout << "print() Config" << endl;
	}
	~Config()
	{
		cout << "~Config()" << endl;
	}
private:
	Config(){}
	Config operator=(const Config& obj) = delete;
	Config(const Config& obj) = delete;

	static Config* _config;
};
Config* Config::_config = new Config();

//����ģʽ��������ģʽ
#include<mutex>

class FileDate
{
public:
	static FileDate* Getinstence()
	{
		if (_pconfig == nullptr)
		{
			mu.lock();
			if (_pconfig == nullptr)
			{
				return new FileDate();
			}
			mu.unlock();
		}
		return _pconfig;
	}
	void print()
	{
		cout << "print() FileDate" << endl;
	}
	~FileDate()
	{
		cout << "~FileDate()" << endl;
	}
private:
	FileDate() {}
	FileDate operator=(const FileDate& obj) = delete;
	FileDate(const FileDate& obj) = delete;
	static mutex mu;
	static FileDate* _pconfig;
};
FileDate* FileDate::_pconfig = nullptr;

#include<vector>
//��
//       6
//   1       2
//3     4 5    0 
class heap
{
public:
	heap(vector<int>& arr)
		:_arr(arr)
	{
		int end = _arr.size() - 1;
		for (int i = (end - 1) / 2; i >= 0; i--)
		{
			down_adjust(i,_arr.size());
		}
	}
	void push(int x)
	{
		_arr.push_back(x);
		up_adjust(_arr.size() - 1);
	}
	void pop()
	{
		swap(_arr[0], _arr[_arr.size() - 1]);
		_arr.pop_back();
		down_adjust(0, _arr.size());
	}
	void sort()
	{
		int end = _arr.size();
		for (int i = 0; i < _arr.size(); i++)
		{
			swap(_arr[end - 1], _arr[0]);
			end--;
			down_adjust(0, end);
		}
	}
	void print()
	{
		for (auto e : _arr)
		{
			cout << e << ' ';
		}
	}
private:
	//����push
	void up_adjust(int child)
	{
		int parent = (child - 1) / 2;
		while (parent >= 0)
		{
			if (_arr[parent] < _arr[child])
			{
				swap(_arr[child], _arr[parent]);
			}
			else break;
			child = parent;
			parent = (child - 1) / 2;
		}
	}
	//���ڽ��ѺͶ�pop
	void down_adjust(int parent,int end)
	{
		int child = parent * 2 + 1;
		
		while (child < end)
		{
			if (child + 1 < end && _arr[child] < _arr[child + 1])child++;
			if (_arr[child] > _arr[parent])
			{
				swap(_arr[child], _arr[parent]);
			}
			else break;
			parent = child;
			child = parent * 2 + 1;
		} 
	}
	vector<int>& _arr;
};

//����
class Qsort
{
public:
	Qsort(vector<int>& arr)
		:_arr(arr)
	{
		sort(0, _arr.size() - 1);
	}
	void print()
	{
		for (auto e : _arr)
		{
			cout << e << ' ';
		}
	}

private:
	void sort(int begin,int end)
	{
		if (begin > end)return;
		int key = _arr[begin];
		int left = begin;
		int right = end;
		while (left < right)
		{
			while (left < right && _arr[right] >= key)
			{
				right--;
			}
			while (left < right && _arr[left] <= key)
			{
				left++;
			}
			swap(_arr[left], _arr[right]);
		}
		swap(_arr[left], _arr[begin]);
		sort(begin, left - 1);
		sort(left + 1, end);
	}
	vector<int>& _arr;
};



//�鲢����
class MergeSort
{
public:
	MergeSort(vector<int>& arr)
		:_arr(arr)
	{
		tmp.resize(_arr.size());
		mergesort(0, _arr.size() - 1);
	}
	void print()
	{
		for (auto e : _arr)
		{
			cout << e << ' ';
		}
	}
private:
	void mergesort(int begin,int end)
	{
		//begin>end�����ݣ�begin==endֻ��һ�����ݣ�Ҳ�������
		if (begin >= end)return;
		int mid = (begin + end) / 2;
		mergesort(begin, mid);
		mergesort(mid + 1, end);
		int begin1 = begin; int end1 = mid;
		int begin2 = mid + 1; int end2 = end;
		int tmpbegin = begin1;
		while (begin1 <= end1 && begin2 <= end2)
		{
			if (_arr[begin1] < _arr[begin2])tmp[tmpbegin++] = _arr[begin1++];
			else tmp[tmpbegin++] = _arr[begin2++];
		}
		while(begin1<=end1)tmp[tmpbegin++] = _arr[begin1++];
		while (begin2 <=end2)tmp[tmpbegin++] = _arr[begin2++];
		for (int i = begin; i <= end; i++)
		{
			_arr[i] = tmp[i];
		}
	}
	vector<int> tmp;
	vector<int>& _arr;
};


class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		qsort(nums, 0, nums.size() - 1);
		return nums;
	}
	void qsort(vector<int>& nums, int begin, int end)
	{
		if (begin >= end)return;
		int key = Getrandom(nums, begin, end);
		int i = begin; int left = begin - 1; int right = end + 1;
		
		while (i < right)
		{
			if (nums[i] < key)swap(nums[++left], nums[i++]);
			else if (nums[i] == key) i++;
			//	[begin,left]ȫ���Ǳ�keyС
			//	[left+1,right-1]��key���
			//	[right,end] ��key��
			else swap(nums[--right], nums[i]);
		}
		qsort(nums, begin, left);
		qsort(nums, right, end);
	}
	int Getrandom(vector<int>& nums, int begin, int end)
	{
		srand(time(0));
		return nums[rand() % (end - begin + 1) + begin];
	}
};

//����ָ��
template<class T>
class myauto_ptr
{
public:
	myauto_ptr(T* ptr):_ptr(ptr)
	{}
	T operator*() { return *_ptr; }
	T* operator->() { return _ptr; }
	//����Ȩת��
	myauto_ptr<T>& operator=(const myauto_ptr<T>& obj)
	{
		//���ܸ�ֵ���Լ�
		if (obj._ptr != _ptr)
		{
			//���ܶԿ�ָ���ͷ�
			if (_ptr) 
			{
				delete _ptr;
			}
			_ptr = obj._ptr;
			obj._ptr = nullptr;
		}
	}
	~myauto_ptr()
	{
		if(_ptr)delete _ptr;
	}
private:
	T* _ptr;
};

//����ָ��
template<class T>
class myunique_ptr
{
public:
	myunique_ptr(T* ptr):_ptr(ptr)
	{}
	T operator*() { return *_ptr; }
	T* operator->() { return _ptr; }
	~myunique_ptr()
	{
		if (_ptr)delete _ptr;
	}
private:
	//ֻ����һ��myunique_ptr�������ָ��
	myunique_ptr<T>& operator=(const myunique_ptr<T>& obj) = delete;
	myunique_ptr(const myunique_ptr<T>& obj) = delete;
private:
	T* _ptr;
};

template<class T>
class myshared_ptr
{
public:
	myshared_ptr(T* ptr)
		:_ptr(ptr)
	{
		_pcount = new int(0);
	}
	T operator*() { return *_ptr; }
	T* operator->() { return _ptr; }

	myshared_ptr<T>& operator=(myshared_ptr<T>& obj)
	{
		subref();
		_ptr = obj._ptr;
		_pcount = obj._pcount;
		obj.addref();
		
	}
	myshared_ptr(const myshared_ptr<T>& obj)
		:_ptr(obj._ptr),_pcount(obj._pcount)
	{
		addref();
	}
	~myshared_ptr()
	{
		if (_ptr)delete _ptr;
	}
private:
	void addref()
	{
		(*_pcount)++;
	}
	void subref()
	{
		(*_pcount)--;
		if (*_pcount == 0)
		{
			if (_ptr)delete _ptr;
			if (_pcount)delete _pcount;
		}
	}
	T* _ptr;
	int* _pcount;
};
#include < windows.h>   
#include < stdio.h>   
int main(void)
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	printf(" %4d-%02d-%02d-%02d-%02d-%02d-%03d\n"
		, sys.wYear, sys.wMonth, sys.wDay
		, sys.wHour, sys.wMinute, sys.wSecond
		, sys.wMilliseconds);
	printf(" ����%1d\n", sys.wDayOfWeek);
	long long sum = 0;
	for (int i = 0; i <= 1000000000; i++)
	{
		sum += i;
	}
	SYSTEMTIME sys2;
	GetLocalTime(&sys2);
	double millsecnd = (sys2.wMilliseconds - sys.wMilliseconds) * 1.0 / 1000.0;
	double wsecond = sys2.wSecond - sys.wSecond;
	double wminute = (sys2.wMinute - sys.wMinute) * 60.0;
	double Sum = millsecnd + wsecond + wminute;
	cout << "time:" << Sum << endl;

	return 0;
}
