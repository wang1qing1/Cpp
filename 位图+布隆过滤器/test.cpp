#define _CRT_SECURE_NO_WARNINGS 1
#include"Bloom.hpp"
#include<bitset>


	
	//BitSet<80> bit;
	//bit.set(10);
	//bit.set(31);
	//bit.set(52);

	////bit.erase(52);
	////bit.erase(10);

	//cout << bit.test(10) << endl;
	//cout << bit.test(31) << endl;
	//cout << bit.test(52) << endl;

//int main()
//{
//	BitSet<10000> bit;
//	int arr1[] = { 1,15,3,6,8,9,4,23 };
//	int arr[] = { 45,12,32,3,6,35,12,78,94,23,62,54 };
//	//将arr数据插入位图
//	for (auto e : arr)
//	{
//		bit.set(e);
//	}
//	//检查arr1,时候出现在位图中
//	for (auto e : arr1)
//	{
//		cout << e << ":" << bit.test(e) << endl;;
//	}
//
//	return 0;
//}
int main()
{
	Bloom<10000> bit;
	string arr1[] = { "1,15,3,6,8,9,4,23","kjasgud","dkjxd0","kejg","wangqing"};
	string arr[] = { "kjasgud" ,"kajshf","ksgf","wangqing"};
	//将arr数据插入位图
	for (auto e : arr)
	{
		bit.set(e);
	}
	//检查arr1,时候出现在位图中
	for (auto e : arr1)
	{
		cout << e << ":" << bit.test(e) << endl;;
	}

	return 0;
}
