#define _CRT_SECURE_NO_WARNINGS 1
#include"class.h"

void People::Show()
{
	cout << name << " " << age << " " << sex << endl;
}
//����ȱʡ�����ں���������д������
void People::Init(char* str, int a, char s)
{
	name = str;
	age = a;
	sex = s;
}