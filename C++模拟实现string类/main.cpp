#include"my_string.h"
using namespace ikun;
int main()
{

	String str("ahfeuhf");
	String str1(str);
	/*cout << str1;
	cout << str;*/

	String str3;
	
	//str3 = str;
	//cout << str3;
	//str3.reserve(20);
	//cout << str3;
	/*string strk;
	cout << strk.capacity() << endl;
	strk.reserve(50);
	cout << strk.capacity() << endl;*/
	str1 += str;
	cout << str1;

	return 0;
}