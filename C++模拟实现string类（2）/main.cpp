#include"my_string.h"
using namespace ikun;
int main()
{

	String str("drhgdbdr");
	String str1(str);
	/*cout << str1;
	cout << str;*/

	String str3("bdcdr");
	
	//str3.erase(0, 2);
	str3.insert(0, "####");
	cout << str3;

	//str3 = str;
	//cout << str3;
	//str3.reserve(20);
	//cout << str3;
	/*string strk;
	cout << strk.capacity() << endl;
	strk.reserve(50);
	cout << strk.capacity() << endl;*/
	//str.insert(3,"ppp");
	//cout << str;
	//
	//for (String::iterator it = str.begin(); it != str.end(); it++)
	//{
	//	cout << *it << ' ';
	//}

	//cout << (str == str1) << endl;
	//cin >> str;
	//cout << str;

	//cout << str.find(str3, 1);
	/*str3.erase(2, 2);
	cout << str3;*/


	return 0;
}