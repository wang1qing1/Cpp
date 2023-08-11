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

	//const List<int> cli(li);
	//List<int>::iterator it = li.begin();
	//while (it != li.end())
	//{
	//	cout << *it << " ";
	//	it++;
	//}
	//cout << endl;


	list<AA> lli(10, AA());
	list<AA>::iterator lit = lli.begin();
	while (lit != lli.end())
	{
		cout << lit.operator->()->_aa<< " ";
		lit++;
	}
		


	return 0;
}