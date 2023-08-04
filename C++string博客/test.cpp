
#define _CRT_SECURE_NO_WARNINGS 1
#include<algorithm>
#include<iostream>
#include<string>

using std::endl;
using std::cin;
using std::cout;
using std::string;

//int main()
//{
//	string str1("hello");
//	string str2("world");
//	str1 += str2;
//	
//	cout << str1 << endl;
//
//	return 0;
//}


//int main()
//{
//	string str1("hello");
//	string str2("world");
//	int pos = 0;
//	//1.在pos位置插入一个 string 
//	str2.insert(pos, str1);
//	cout << str2 << endl;
//
//	string str3("bcde");
//	int size = 5;
//	//2.在pos位置插入size个字符a
//	str3.insert(pos, size, 'a');
//	cout << str3 << endl;
//
//	string str4("bcde");
//	//3.插入位置还可以是迭代器
//	str4.insert(str4.begin(), 10, 'A');
//	cout << str4 << endl;
//
//	string str5("world");
//	const char* cstr = "hello ";
//	//4.在pos位置插入一个 C风格字符串。
//	str5.insert(pos,cstr);
//	cout << str5 << endl;
//
//	return 0;
//}


template<class T>
void Swap(T& e1,T& e2)
{
	T tmp = e1;
	e1 = e2;
	e2 = tmp;
}

//int main()
//{
//
//	int pos = 0;
//	int length = 4;
//	string str = "this is a string";
//	//返回一个从pos位置开始，跨越长度为4的子串。
//	string Substr = str.substr(0, 4);
//
//	cout << "Substr:" << Substr << endl;
//
//
//
//	/*string str = "this is a string";
//	size_t pos = str.find('a', 1);
//	cout << "a 在" << pos << "位置" << endl;*/
//
//
//	//string str1 = "AAAA";
//	//string str2 = "BBBBB";
//
//	//Swap<string>(str1, str2);
//
//	//cout << str1 << " " << str2 << endl;
//
//
//
//	//int pos = 5;
//	//int size = 3;
//	//string str1("hello   C++");
//	//string str2 = str1;
//	//cout << "erase前str1：" << str1 << endl;
//	//cout << "erase前str2：" << str2 << endl;
//	//cout << str1.capacity() << endl;;
//	////删除pos位置包括pos位置的后size个字符，删除位置也可以是一段迭代器区间
//	//str1.erase(pos, size);
//	//str2.erase(str2.begin()+5,str2.begin()+5+3);
//	//cout << "erase后str1：" << str1 << endl;
//	//cout << "erase后str2：" << str2 << endl;
//	//cout << str1.capacity() << endl;
//
//
//	return 0;
//}
//#include"head.hpp"
//#include"head1.hpp"


inline void fun()
{
	std::cout << "hello nihao1" << std::endl;
}

inline void fun()
{
	std::cout << "hello" << std::endl;
}
int main()
{

	/*fun123();
	fun456();*/
	fun();

	/*string str;
	cout << "输入：";
	std::getline(cin, str,'a');
	cout << "str:" << str << endl;*/

	return 0;
}