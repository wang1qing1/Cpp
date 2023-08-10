#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>

#include"List.hpp"

int main()
{

	List<int> li;
	//vector<int>* pv = new vector<int>;
	li.push_back(100);
	li.push_back(200);
	li.push_back(400);
	li.push_back(500);
	li.print();


	return 0;
}