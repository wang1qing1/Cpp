#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>

using namespace std;

class Qsort
{
public:
	Qsort(vector<int>& arr)
		:_arr(arr)
	{
		Sort(0, _arr.size() - 1);
	}

	void Sort(int left,int right)
	{
		if (left >= right)return;
		int begin = left;
		int end = right;
		int key = _arr[left];
		int keyindex = left;
		
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
		swap(_arr[keyindex], _arr[left]);
		keyindex = left;
		
		Sort(begin, keyindex - 1);
		Sort(keyindex + 1, end);
	}
	vector<int>& _arr;
};

class TQsort
{
public:
	TQsort(vector<int>& arr)
		:_arr(arr)
	{
		srand(time(0));
		Sort(0, _arr.size()-1);
	}
	int GetRandom(int left, int right)
	{
		return _arr[rand() % (right - left + 1) + left];
	}
	void Sort(int left, int right)
	{
		if (left >= right)return;
		int i = left; int begin = left-1; int end = right+1;
		int key = GetRandom(left, right);
		while (i < end)
		{
			if (_arr[i] < key)swap(_arr[i++], _arr[++begin]);
			else if (_arr[i] == key)i++;
			else swap(_arr[i], _arr[--end]);	 
		}
		Sort(left, begin);
		Sort(end, right);
	}
	vector<int>& _arr;
};


class Qselect
{
public:
	Qselect(vector<int>& arr,int k)
		:_arr(arr),_k(k)
	{
		srand(time(0));
		Sort(0, _arr.size() - 1,k);
	}
	int GetRandom(int left, int right)
	{
		return _arr[rand() % (right - left + 1) + left];
	}
	void Sort(int left, int right,int k)
	{
		if (left >= right)return;
		int i = left; int begin = left - 1; int end = right + 1;
		int key = GetRandom(left, right);
		while (i < end)
		{
			if (_arr[i] < key)swap(_arr[i++], _arr[++begin]);
			else if (_arr[i] == key)i++;
			else swap(_arr[i], _arr[--end]);
		}
		//[left,begin] [begin+1,end-1] [end,right]
		int l = begin - left + 1;
		int mid = end - begin - 1;
		int r = right - end + 1;
		if (l > k)Sort(left, begin, k);
		else if (mid+l>=k)return;
		else Sort(end, right, k - end);
	}

	vector<int> GetTopKnum()
	{
		return vector<int>(_arr.begin(), _arr.begin() + _k);
	}
	int GetTopK()
	{
		return _arr[_k];
	}

	vector<int>& _arr;
	int _k;
};

class MergeSort
{
public:
	MergeSort(vector<int>& arr)
		:_arr(arr)
	{
		_tmp.resize(arr.size());
		Sort(0, _arr.size() - 1);
		
	}

	void Sort(int left, int right)
	{
		if (left >= right)return;
		int mid = (left + right) / 2;
		Sort(left, mid);
		Sort(mid + 1, right);
		int begin1 = left; int end1 = mid;
		int begin2 = mid + 1; int end2 = right;
		int begin = begin1;
		while (begin1 <= end1 && begin2 <= end2)
		{
			if (_arr[begin1] < _arr[begin2])_tmp[begin++] = _arr[begin1++];
			else _tmp[begin++] = _arr[begin2++];
		}
		while(begin1 <= end1)_tmp[begin++] = _arr[begin1++];
		while(begin2 <= end2)_tmp[begin++] = _arr[begin2++];
		for (int i = left; i <= right; i++)_arr[i] = _tmp[i];
	}
	vector<int>& _arr;
	vector<int> _tmp;
};


int main()
{
	vector<int> arr = { 2,3,5,6,9,1,7,8,4,10,0 };
	MergeSort qsort(arr);
	
	for (auto e : arr)cout << e << " ";
	
	return 0;
}