#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.hpp"
#include<iostream>
#include<list>
#include"Queue.hpp"

using namespace Sikun;
using namespace Qikun;
int main()
{
	Stack<int,list<int>> st;
	st.push(100);
	st.push(200);
	st.push(300);
	st.push(400);

	while (!st.empty())
	{
		cout << st.top()<<" ";
		st.pop();
	}

	cout << endl;
	Queue<int, list<int>> qu;
	qu.push(100);
	qu.push(200);
	qu.push(300);
	qu.push(400);

	while (!qu.empty())
	{
		cout << qu.front() << " ";
		qu.pop();
	}


	return 0;
}