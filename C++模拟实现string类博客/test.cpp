#define _CRT_SECURE_NO_WARNINGS 1

#include"String.hpp"

int main()
{

	String str1("acegik");
	const String str2("hello C++");

	for (int i = 0; i < str1.size(); i++)
	{
		cout << ++str1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < str2.size(); i++)
	{
		cout << str2[i];
	}





	return 0;
}


//String str2("hahahaah2");
//cout << str1.c_str() << endl;
//
//String str(str1);
//cout << str.c_str() << endl;

//for (int i = 0; i < str1.size(); i++)
//{
//	cout << ++str1[i] << " ";
//}