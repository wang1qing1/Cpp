#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//int main()
//{
//	//�������ַ���
//	string str1;
//	cout << str1 << endl;
//	//ʹ���ַ����������
//	string str2("hello world");
//	cout << str2 << endl;
//	//ʹ��n���ַ��������
//	string str3(15, '*');
//	cout << str3 << endl;
//	//�������캯��
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
//	cout << "clearǰ��" << str << endl;
//	str.clear();
//	cout << "clear��" << str << endl;
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
//	//���ӳ���
//	str.resize(str.size() + 5, '#');
//	cout << str << endl;
//	//��С����
//	str.resize(4);
//	cout << str << endl;
//
//	return 0;
//}

//int main()
//{
//	string str("hello world hello world hello ");
//	cout << "clearǰ��" << str <<" ������" << str.capacity() << endl;
//	str.clear();
//	cout << "clearǰ��" << str << "������" << str.capacity() << endl;
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
//	//��const������,�ɶ�����д
//	for (string::iterator it = str.begin();it!=str.end();it++)
//	{
//		*it = '*';
//	}
//	for (string::iterator it = str.begin(); it != str.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	//const ������ ���ɶ�
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
