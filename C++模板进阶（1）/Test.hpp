#pragma once
#include<iostream>
#include<vector>
using namespace std;

//非类型模板参数
//只能是整形,具有常属性,不可修改
template<class T,int N>
class Less
{
public:
	bool operator()(T a, T b)
	{
		return a < b;
	}
	T arr[N];
	
};

template<class T>
class greate
{
public:

};
