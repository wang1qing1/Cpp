#pragma once
#include<iostream>
#include<vector>
using namespace std;

//������ģ�����
//ֻ��������,���г�����,�����޸�
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
