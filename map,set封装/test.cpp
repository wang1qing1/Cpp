#define _CRT_SECURE_NO_WARNINGS 1

#include<vector>
#include<cassert>
#include"map.hpp"
#include"set.hpp"

int main()
{
	//map<int,int> rb;
	//int i = 100;
	//while(i--)
	//{
	//	int num = rand() + i;
	//	rb.insert(make_pair(num,num));
	//}
	//map<int,int>::iterator it = rb.begin();
	//while (it != rb.end())
	//{
	//	cout << it->first << ":" << it->second << endl;;
	//	++it;
	//}


	set<int> rb;
	int i = 100;
	while (i--)
	{
		int num = rand() + i;
		rb.insert(num);
	}
	set<int>::iterator it = rb.begin();
	while (it != rb.end())
	{
		cout << *it<< endl;;
		++it;
	}


	return 0;
}