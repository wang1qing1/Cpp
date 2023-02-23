#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//int main()
//{
//	//创建空字符串
//	string str1;
//	cout << str1 << endl;
//	//使用字符串构造对象
//	string str2("hello world");
//	cout << str2 << endl;
//	//使用n个字符构造对象
//	string str3(15, '*');
//	cout << str3 << endl;
//	//拷贝构造函数
//	string str4(str2);
//	cout << str4 << endl;
//
//	return 0;
//}

//int main()
//{
//	string str("hello world");
//	string str1;
//	cout << str.empty() << endl;
//	cout << str1.empty() << endl;
//
//	return 0;
//}

//int main()
//{
//	string str("hello world");
//	cout << "clear前：" << str << endl;
//	str.clear();
//	cout << "clear后：" << str << endl;
//	return 0;
//}
//int main()
//{
//	string str("");
//	cout << str.capacity() << endl;
//	str.reserve(20);
//	cout << str.capacity() << endl;
//	str.reserve(2);
//	cout << str.capacity() << endl;
//
//	return 0;
//}
//int main()
//{
//	string str("abcde");
//	cout << str << endl;
//	//增加长度
//	str.resize(str.size() + 5, '#');
//	cout << str << endl;
//	//减小长度
//	str.resize(4);
//	cout << str << endl;
//
//	return 0;
//}

//int main()
//{
//	string str("hello world hello world hello ");
//	cout << "clear前：" << str <<" 容量：" << str.capacity() << endl;
//	str.clear();
//	cout << "clear前：" << str << "容量：" << str.capacity() << endl;
//	return 0;
//}
//int main()
//{
//	string str("hello");
//	for (int i = 0; i < str.size(); i++)
//	{
//		cout << str[i] << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < str.size(); i++)
//	{
//		cout << str.at(i) << " ";
//	}
//	return 0;
//}
//int main()
//{
//	string str("helloworld");
//	 it = str.begin();
//	for (int i = 0; i < str.size(); i++)
//	{
//		cout << str[i] << " ";
//	}
//	
//	for (int i = 0; i < str.size(); i++)
//	{
//		cout << str.at(i) << " ";
//	}
//	return 0;
//}
//
//int main()
//{
//	string str("helloworld");
//	//非const迭代器,可读，可写
//	for (string::iterator it = str.begin();it!=str.end();it++)
//	{
//		*it = '*';
//	}
//	for (string::iterator it = str.begin(); it != str.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	//const 迭代器 仅可读
//	const string str1("helloworld");
//	for (string::const_iterator it = str1.begin(); it != str1.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	return 0;
//}

//int main()
//{
//	string str("helloworld");
//	
//	for (string::reverse_iterator it = str.rbegin(); it != str.rend(); it++)
//	{
//		cout << *it << " ";
//	}
//	return 0;
//}
int main()
{
	string str("helloworld");
	for (auto c : str)
	{
		cout << c << " ";
	}
	cout << endl;
	for (string::iterator it = str.begin(); it != str.end(); it++)
	{
		cout << *it << " ";
	}
	return 0;
}
