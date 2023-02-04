#pragma once
#include<stdlib.h>
#include<iostream>
#include<assert.h>
using namespace std;

class People
{
	//º¯ÊıÉùÃ÷
	void Init(char* str, int a = 20, char s = 'm');
	void Show();
	
	char* name;
	int age;
	char sex;

};
