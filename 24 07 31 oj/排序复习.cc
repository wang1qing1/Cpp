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


int main()
{
	vector<int> arr = { 2,3,5,6,9,1,7,8,4 };
	TQsort qsort(arr);
	for (auto e : arr)cout << e << " ";

	return 0;
}