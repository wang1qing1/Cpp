#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	////<int> 模板类型,存储int的顺序表
	//vector<int> v1;
	////存储string的顺序表
	//vector<string> v2;
	////存储double的顺序表
	//vector<double> v3;
	////存储char的顺序表
	//vector<char> v4;

	////构造一个 vector开10个int空间，并全部初始化为2
	//vector<int> v1(10, 2);

	////for (auto e : v1)
	////{
	////	cout << e;
	////}
	//// 
	//
	////拷贝构造初始化
	//vector<int> v2(v1);



	////构造一个 vector开10个int空间，并全部初始化为123
	//vector<int> v1(10, 123);
	////vector 反向迭代器
	////auto rit =v1.rbegin();

	//vector<int>::reverse_iterator rit = v1.rbegin();

	//while (rit != v1.rend())
	//{
	//	cout << *rit << " ";
	//	rit++;
	//}
	//string str("hello C++");
	//vector<int> v1(10,2);
	//vector<int> v2(v1.begin(), v1.end() - 5);
	//vector<int> v3(str.begin(), str.end());
	//for (auto e : v2)
	//{
	//	cout << e<<" ";
	//}
	//cout << endl;
	//for (auto e : v3)
	//{
	//	cout << e << " ";
	//}












	//vector<int> v1;
	////尾插 30 40 50 60
	//v1.push_back(30);
	//v1.push_back(40);
	//v1.push_back(50);
	//v1.push_back(60);

	//v1.resize(2);
	//for (int i = 0; i < v1.size(); i++)
	//{
	//	cout << v1[i] << " ";
	//}

	vector<int> v1;
	//开10个空间，并且全部初始化为 5
	v1.reserve(100);
	cout << v1.capacity() << endl;
	v1.reserve(10);
	cout << v1.capacity() << endl;













	//for (auto e : v1)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	////在beginw位置之前插入20 10
	//v1.insert(v1.begin(), 20);
	//v1.insert(v1.begin(), 10);
	//for (auto e : v1)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	////删除尾部的两个数据
	//v1.erase(v1.end()-1);
	//v1.erase(v1.end()-1);
	//for (auto e : v1)
	//{
	//	cout << e << " ";
	//}









	
	//while (it != v1.end())
	//{
	//	cout << *it << " ";
	//	it++;
	//}
	//cout << endl;

	return 0;
}

