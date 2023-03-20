#define _CRT_SECURE_NO_WARNINGS 1
#include"Test.hpp"

int main()
{
	Less<int, 10> less;
	//L.arr[10];
	//L(10, 20);
	less(10,20);
	const int n = 10;
	const int*  p = &n;
	int arr[n];

	return 0;
}