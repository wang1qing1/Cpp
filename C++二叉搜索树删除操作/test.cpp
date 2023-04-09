#define _CRT_SECURE_NO_WARNINGS 1
#include"SBT.h"
class A
{
public:
	int num;
	int& nu = num;
	const int mm = 10;
};
int main()
{

	SerchBinaryTree<int> root;
	int arr[7] = { 8,4,10,3,5,9,12 };
	for (int i = 0; i < 7; i++)
	{
		root.Insert(arr[i]);
	}
	root.MidOrder();
	cout << endl;
	root.Erase(8);
	
	root.MidOrder();
	cout << endl;
	root.Erase(4);
	root.MidOrder();
	cout << endl;
	root.Erase(5);
	root.MidOrder();
	cout << endl;
	root.Erase(12);
	root.MidOrder();
	cout << endl;
	root.Erase(3);
	root.MidOrder();
	cout << endl;

	root.Erase(10);
	root.MidOrder();
	cout << endl;

	return 0;
}