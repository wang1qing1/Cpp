#define _CRT_SECURE_NO_WARNINGS 1
#include"Priority_Queue.h"
#include<deque>

int main()
{
	int ar[10] = { 1,1,1,1,1,1,1,1 };
	vector<int> v;
	vector<int>::iterator it;
	v.push_back(10);
	v.push_back(500);
	v.push_back(1000);
	v.push_back(1);
	v.push_back(1500);
	v.push_back(100);
	v.push_back(1400);


	ikun::Priority_Queue<int,vector<int>,greater<int>> P(v.begin(),v.end());
	

	cout << P.top() << ' ';
	P.pop();
	cout << P.top() << ' ';
	P.pop();
	cout << P.top() << ' ';




	


	return 0;
}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int n, i;
//	scanf("%d", &n);
//	int s[n + 1][5];
//	int* (*s) = (int**)malloc(sizeof(int*) * n + 1);
//	for (i = 1; i <= n; i++)
//	{
//		scanf("%d %d %d", &s[i][1], &s[i][2], &s[i][3]);
//		s[i][0] = i;
//		s[i][4] = s[i][1] + s[i][2] + s[i][3];
//	}
//	for (int m = 1; m < n; m++)
//	{
//		for (int j = m + 1; j <= n; j++)
//			if ((s[m][4] < s[j][4]) || (s[m][4] == s[j][4] && s[m][1] < s[j][1]) || (s[m][4] == s[j][4] && s[m][1] == s[j][1] && s[m][0] > s[j][0]))
//				for (int k = 0; k < 5; k++) swap(s[m][k], s[j][k]);
//		for (int l = 1; l <= 5; l++)
//			printf("%d %d", s[l][0], s[l][4])
//			return 0;
//	}
//}
