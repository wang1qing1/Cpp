#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <unordered_map>
#include<string>
#include <queue>
#include <math.h>

using namespace std;


#include<mutex>

class config
{
public:
	config* GetConfig()
	{
		if (_ptr == nullptr)
		{
			mu.lock();
			if (_ptr == nullptr)
			{
				return _ptr = new config();
			}
			mu.unlock();
		}
		return _ptr;
	}
private:
	config(const config& obj) = delete;
	config& operator=(const config& obj) = delete;
	config(){}
	config* _ptr = nullptr;
	mutex mu;
};

//class config
//{
//public:
//	config* GetConfig()
//	{
//		return _ptr;
//	}
//private:
//	config(const config& obj) = delete;
//	config& operator=(const config& obj) = delete;
//	config() {}
//	static config* _ptr;
//};
//config* config::_ptr = new config();

template<class T>
class myunique_ptr
{
public:
	myunique_ptr(T* ptr)
		:_ptr(ptr)
	{}
	T operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}

private:
	myunique_ptr& operator=(const myunique_ptr& obj) = delete;
	myunique_ptr(const myunique_ptr& obj) = delete;

	T* _ptr;
};

template<class T>
class myshareed_ptr
{

public:
	myshareed_ptr(T* ptr)
		:_ptr(ptr),_count(new int(1))
	{}
	T operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}

	myshareed_ptr& operator=(const myshareed_ptr& obj)
	{
		this.subref();
		_ptr = obj._ptr;
		_count = obj._count;
		addref();
	}
	myshareed_ptr(const myshareed_ptr& obj)
		:_ptr(obj._ptr),_count(obj._count)
	{
		addref();
	}

private:
	void addref()
	{
		(*_count)++;
	}
	void subref() 
	{
		(*_count)--;
		if (_count == 0)
		{
			if (_ptr)delete _ptr;
		}
	}

	T* _ptr;
	int* _count;
};


class Qsort
{
public:
	Qsort(vector<int>& arr)
		:_arr(arr)
	{
		_sort(0, _arr.size() - 1);
	}
	void _sort(int begin,int end)
	{
		if (begin >= end)return;
		int key = begin;
		int left = begin;
		int right = end;
		while (begin<end)
		{
			while (begin < end && _arr[end] >= _arr[key])end--;
			while (begin < end && _arr[begin] <= _arr[key])begin++;
			swap(_arr[begin], _arr[end]);
		}
		swap(_arr[begin], _arr[key]);
		_sort(left, begin - 1);
		_sort(begin + 1, right);
	}
private:
	vector<int>& _arr;
};

class ThreeQsort
{
public:
	ThreeQsort(vector<int>& arr)
		:_arr(arr)
	{
		srand(time(0));
		_sort(0,_arr.size()-1);

	}
	int GetRandomNum(int begin, int end)
	{
		return _arr[(rand() % (end - begin + 1)) + begin];
	}
	void _sort(int begin,int end)
	{
		if (begin >= end)return;
		int key = GetRandomNum(begin, end);
		int i = begin; int left = begin-1; int right = end+1;
		while (i < right)
		{
			if (_arr[i] < key)swap(_arr[i++], _arr[++left]);
			else if (_arr[i] == key)i++;
			else swap(_arr[i], _arr[--right]);
		}
		_sort(begin, left);
		_sort(right, end);
	}
private:
	vector<int>& _arr;
};


class quickselect
{
public:
	//选出最小的k个数
	quickselect(vector<int>& arr, int k)
		:_arr(arr),_k(k)
	{
		quickselectv(0, _arr.size()-1, k);
	}
	int GetRandomNum(int begin, int end)
	{
		return _arr[(rand() % (end - begin + 1)) + begin];
	}
	void quickselectv(int begin,int end,int k)
	{
		if (begin >= end)return;
		int key = GetRandomNum(begin,end);
		int i = begin; int left = begin - 1; int right = end + 1;
		while (i < right)
		{
			if (_arr[i] < key)swap(_arr[i++], _arr[++left]);
			else if (_arr[i] == key)i++;
			else swap(_arr[i], _arr[--right]);
		}
		//[begin,left][left+1,right-1][right,end]
		int lcount = left - begin + 1;
		int mcount = right - left - 1;
		if (lcount > k)quickselectv(begin,left,k);
		else if(lcount +mcount>= _k)return ;
		else quickselectv(right, end,k-lcount-mcount);
	}
	vector<int> RetKnum()
	{
		return vector<int>(_arr.begin(), _arr.begin() + _k);
	}
private:
	vector<int> _arr;
	int _k;
};


class MergerSort
{
public:
	MergerSort(vector<int>& arr)
		:_arr(arr)
	{
		tmp.resize(_arr.size());
		_sort(0, _arr.size()-1);
	}
	void _sort(int begin,int end)
	{
		if (begin >= end)return;
		int mid = (begin + end) / 2;
		_sort(begin, mid);
		_sort(mid + 1, end);
		int left1 = begin; int right1 = mid;
		int left2 = mid + 1; int right2 = end;
		int tmpbegin = left1;
		while (left1 <= right1 && left2 <= right2)
		{
			if (_arr[left1] <= _arr[left2])tmp[tmpbegin++] = _arr[left1++];
			else tmp[tmpbegin++] = _arr[left2++];
		}
		while(left1<=right1)tmp[tmpbegin++] = _arr[left1++];
		while(left2<=right2)tmp[tmpbegin++] = _arr[left2++];
		for (int i = begin; i <= end; i++)_arr[i] = tmp[i];

	}
	vector<int>& _arr;
	vector<int> tmp;
};

int main()
{
	vector<int> arr1{ 2,3,4,8,9,6,7,5,1 };
	MergerSort q(arr1);
	
	for (auto e : arr1)cout << e << " ";
	return 0;
}
