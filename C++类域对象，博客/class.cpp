#define _CRT_SECURE_NO_WARNINGS 1
#include"class.h"

void People::Show()
{
	cout << name << " " << age << " " << sex << endl;
}
//函数缺省参数在函数声明处写出来。
void People::Init(char* str, int a, char s)
{
	name = str;
	age = a;
	sex = s;
}