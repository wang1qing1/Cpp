
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
//	//1.��posλ�ò���һ�� string 
//	str2.insert(pos, str1);
//	cout << str2 << endl;
//
//	string str3("bcde");
//	int size = 5;
//	//2.��posλ�ò���size���ַ�a
//	str3.insert(pos, size, 'a');
//	cout << str3 << endl;
//
//	string str4("bcde");
//	//3.����λ�û������ǵ�����
//	str4.insert(str4.begin(), 10, 'A');
//	cout << str4 << endl;
//
//	string str5("world");
//	const char* cstr = "hello ";
//	//4.��posλ�ò���һ�� C����ַ�����
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
//	//����һ����posλ�ÿ�ʼ����Խ����Ϊ4���Ӵ���
//	string Substr = str.substr(0, 4);
//
//	cout << "Substr:" << Substr << endl;
//
//
//
//	/*string str = "this is a string";
//	size_t pos = str.find('a', 1);
//	cout << "a ��" << pos << "λ��" << endl;*/
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
//	//cout << "eraseǰstr1��" << str1 << endl;
//	//cout << "eraseǰstr2��" << str2 << endl;
//	//cout << str1.capacity() << endl;;
//	////ɾ��posλ�ð���posλ�õĺ�size���ַ���ɾ��λ��Ҳ������һ�ε���������
//	//str1.erase(pos, size);
//	//str2.erase(str2.begin()+5,str2.begin()+5+3);
//	//cout << "erase��str1��" << str1 << endl;
//	//cout << "erase��str2��" << str2 << endl;
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
	cout << "���룺";
	std::getline(cin, str,'a');
	cout << "str:" << str << endl;*/

	return 0;
}