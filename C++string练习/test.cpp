#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>

using namespace std;
int main()
{
	string s1;
	s1 = "hello world";
	const string s2("wa ng qi ng");
	/*string s3 = s2;
	string s4(s2);
	cout << s1;
	cout << s2 << s3 << endl;
	cout << s3.capacity() << endl;
	cout << s3.size() << endl;*/
	//for (auto e : s2)
	//{
	//	cout << e << " ";
	//}

	//string::iterator it = s2.begin();
	//while (it != s2.end())
	//{
	//	cout <<  *it << " ";
	//	it++;
	//}
	//string::reverse_iterator it = s2.rbegin();
	//while (it != s2.rend())
	//{
	//	cout << *it << " ";
	//	it++;
	//}
	/*string::const_reverse_iterator it = s2.rbegin();
	while (it != s2.rend())
	{
		cout << *it << " ";
		it++;
	}*/	
	/*auto it = s2.rbegin();
	while (it != s2.rend())
	{
		cout << *it << " ";
		it++;
	}*/

	//string newstr;
	//for (int i = 0; i < s2.size(); i++)
	//{
	//	if (s2[i] != ' ')
	//	{
	//		newstr += s2[i];
	//	}
	//	else
	//	{
	//		newstr += "%20";
	//	}
	//}
	//cout << newstr << endl;

	size_t pos = s2.find(' ');
	while (pos != s2.npos)
	{
		re
	}



	return 0;
}