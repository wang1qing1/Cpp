#define _CRT_SECURE_NO_WARNINGS 1
#include"SBT.h"
//class A
//{
//public:
//	int num;
//	int& nu = num;
//	const int mm = 10;
//};
//int main()
//{
//
//	SerchBinaryTree<int> root;
//	int arr[7] = { 8,4,10,3,5,9,12 };
//	for (int i = 0; i < 7; i++)
//	{
//		root.Insert(arr[i]);
//	}
//	root.MidOrder();
//	cout << endl;
//	root.Erase(8);
//	
//	root.MidOrder();
//	cout << endl;
//	root.Erase(4);
//	root.MidOrder();
//	cout << endl;
//	root.Erase(5);
//	root.MidOrder();
//	cout << endl;
//	root.Erase(12);
//	root.MidOrder();
//	cout << endl;
//	root.Erase(3);
//	root.MidOrder();
//	cout << endl;
//
//	root.Erase(10);
//	root.MidOrder();
//	cout << endl;
//
//	return 0;
//}
//class A
//{
//public:
//	A() 
//		:m_iVal(0)
//	{
//		test();
//	}
//	virtual void func()
//	{
//		cout << m_iVal << ' ';
//	}
//	void test() { func(); }
//	int m_iVal;
//};
//class B :public A
//{
//public:
//	B() { test(); }
//	virtual void func()
//	{
//		++m_iVal;
//		cout << m_iVal << ' ';
//	}
//};
//int main()
//{
//	A* p = new B; //1 2 1
//	p->test();
//	return 0;
//}
//class A
//{
//public:
//	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//	virtual void test() { func(); }
//};
//class B : public A
//{
//public:
//	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//};
//int main(int argc, char* argv[])
//{
//	A* p = new B;
//	p->test();
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int main() {
//
//    string smastr="kjfhedkv";
//    string longstr="ckJWEKJ";
//    //cin >> smastr >> longstr;
//    if (smastr.length() > longstr.length())
//    {
//        swap(smastr, longstr);
//    }
//    for (int i = smastr.length(); i >= 1; i--)
//    {
//        for (int j = 0; j <= smastr.length() - 1; j++)
//        {
//            if (j + i <= smastr.length())
//            {
//                string str(smastr.begin() + j, smastr.begin() + j + i);
//                if (strstr(longstr.c_str(), str.c_str()))
//                {
//                    cout << str;
//                    return 0;
//                }
//            }
//            else
//            {
//                break;
//            }
//        }
//    }
//}
//	
//#include <iostream>
//#include<algorithm>
//#include <vector>
//using namespace std;

//int main()
//{
//    int T=3; int n; int k;
//   // cin >> T;
//    while (T--)
//    {
//        cin >> n >> k;
//        int* num = new int[2 * n + 1];
//        for (int i = 1; i <= 2 * n; i++)
//        {
//            cin >> num[i];
//        }
//        int* cnum = new int[2 * n + 1];
//        while (k--)
//        {
//            int findex = 1;
//            int rindex = 2;
//            for (int i = 1; i <= 2 * n; i++)
//            {
//                if (i <= n)
//                {
//                    cnum[findex] = num[i];
//                    findex += 2;
//                }
//                else {
//                    cnum[rindex] = num[i];
//                    rindex += 2;
//                }
//            }
//            for (int i = 1; i <= 2 * n; i++)
//            {
//                num[i]=cnum[i];
//            }
//        }
//        for (int i = 1; i <= 2 * n; i++)
//        {
//            cout << cnum[i] << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}
//	

int main()
{

	ikun::SerchBinaryTree<int> root;
	int arr[7] = { 8,4,10,3,5,9,12 };
	for (int i = 0; i < 7; i++)
	{
		root.Insert(arr[i]);
	}
	/*root.MidOrder();
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
	cout << endl;*/

	ikun::SerchBinaryTree<int> root1(root);
	
	return 0;
}

