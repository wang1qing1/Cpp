#define _CRT_SECURE_NO_WARNINGS 1

#include"String.hpp"
int main()
{
	String str1;
	std::string str2;


	cout <<sizeof(String)<< endl;
	cout << sizeof(string) << endl;
	

	return 0;
}


//int main()
//{
//	
//	int a = 10;
//	int b = 20;
//	int c;
//	//�������Ϳ���֧��������ֵ
//	c = b = a;
//	String str1("acegik");
//	String str2;
//	String str3;
//	//֧��
//	str3 = str1;
//	//����Ҳ��֧��String����������ֵ
//	str3 = str2 = str1;
//
//
//	return 0;
//}


//String str2("hahahaah2");
//cout << str1.c_str() << endl;
//
//String str(str1);
//cout << str.c_str() << endl;

//for (int i = 0; i < str1.size(); i++)
//{
//	cout << ++str1[i] << " ";
//}