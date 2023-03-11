#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"List.h"
using namespace std;
using namespace ikun;

//void fun(const List<int> L)
//{
//	for (List<int>::const_itorator it = L.begin(); it != L.end(); it++)
//	{
//		//*it += 100;
//	}
//}

struct AA
{
	int _a;
	int _b;
	AA(int a=0,int b=0)
	{
		_a = a;
		_b = b;
	}
};
int main()
{
	List <int> L;
	L.push_bank(100);
	L.push_bank(200);
	L.push_bank(300);
	List<int> L1;
	L1.push_bank(10);
	L1.push_bank(20);
	L1.push_bank(30);

	List<int> LL(L);
	List<int> LLL(L.begin(), L.end());
	L1=L;
	for (auto e : L1)
	{
		cout << e << " ";
	}
	AA a1(1,2);
	AA a2(2, 3);
	AA a3(3, 4);
	List<AA> aa;
	aa.push_bank(a1);
	aa.push_bank(a2);
	aa.push_bank(a3);
	List<AA>::itorator it = aa.begin();

	//while (it != aa.end())
	//{
	//	cout << (*it)._a << ":" << (*it)._b << endl;
	//	it++;
	//}
	//it = aa.begin();
	//while (it != aa.end())
	//{
	//	cout << it->_a << ":" << it->_b << endl;
	//	it++;
	//}

	
	//for (List<int>::itorator it = L.begin(); it != L.end(); it++)
	//{
	//	*it += 100;
	//}

	//L.insert(L.begin(), 1000);
	////L.insert(L.end(), 5000);
	//L.erase(--L.end());
	//List<int>::itorator it = L.begin();
	//while (it != L.end())
	//{
	//	cout << *it << " ";
	//	it++;
	//}

	//fun(L);

	return 0;
}