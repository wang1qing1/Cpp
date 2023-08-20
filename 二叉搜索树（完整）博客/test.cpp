#define _CRT_SECURE_NO_WARNINGS 1
#include"KV_BSTree.hpp"
//#include"BSTree.hpp"

//int  main()
//{
//	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	BSTree<int> b;
//	BSTree<int> Rb;
//	for (auto e : a)
//	{
//		b.insert(e);
//		Rb.Rinsert(e);
//	}
//
//	for (auto e : a)
//	{
//		b.erase(e);
//		b.InOrder();
//		cout << endl;
//		Rb.Rerase(e);
//		Rb.InOrder();
//		cout << endl;
//	}
//	return 0;
//}



int main()
{
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
"苹果", "香蕉", "苹果", "香蕉" };
	KV_BSTree<string,int> b;
	for (auto e : arr)
	{
		auto cur = b.find(e);
		if (cur == nullptr)
		{
			b.insert(e, 1);
		}
		else
		{
			cur->_val++;
		}
	}
	b.InOrder();
	return 0;
}