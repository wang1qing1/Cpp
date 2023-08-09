
#define _CRT_SECURE_NO_WARNINGS 1
#include"Vector.hpp"
#include <vector>
#include<algorithm>

int main()
{

	string str("abcdefg");
	Vector<string> v2;
	for (int i = 0; i < 6; i++)
	{
		v2.push_back(str);
	}

	Vector<Vector<string>> vvstr1(5, v2);
	Vector<Vector<string>> vvstr2(vvstr1);


	return 0;
}

//Vector<Vector<string>> vvstr(3, v2);
//Vector<Vector<string>> vvstr1(vvstr);