#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>

#include"List.hpp"

struct AA
{
	AA(int aa = 10)
		:_aa(aa)
	{
	}
	int _aa;
};

int main()
{
	List<int> li;
	li.push_back(100);
	li.push_back(200);
	li.push_back(400);
	li.push_back(500);
	List<int> lli(li.begin(), li.end());

	
		


	return 0;
}