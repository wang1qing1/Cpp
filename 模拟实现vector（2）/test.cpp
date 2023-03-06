#define _CRT_SECURE_NO_WARNINGS 1
#include"Vector.h"
using namespace ikun;
//int fun(int n)
//{
//	if (n == 1)
//		return 1;
//	return fun(n - 1) * n;
//}

int main()
{
	Vector<string> v;
	v.push_bank("100@");
	v.push_bank("200@");
	v.push_bank("300@");
	v.push_bank("400@");
	v.push_bank("500@");
	v.push_bank("600@");
	v.push_bank("700@");
	v.push_bank("900@");

	Vector<Vector<int>> vv;
	vv[0][0] = 10;
	Vector<Vector<int>> cpvv(vv);
	/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			vv[i];
			vv[i].push_bank(10*(j+1));
		}
	}
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}*/
	
	/*int arr[] = { 1,2,3,4,5,6 };
	Vector<int> v1(arr,arr+sizeof(arr)/sizeof(arr[0]));*/
	/*Vector<string> v1(v);*/
	
	//v.insert(v.begin()+3, 1234);
	//v.erase(v.begin());
	//v.resize(10,5);
	//Vector<string> v1(v);
	//for (auto it = v1.begin(); it != v1.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//std::cout << std::endl;
	//for (int i = 0; i < v.size(); i++)
	//{
	//	printf("%d ", v[i]);
	//}
	///*int a = 10; int b = 20;
	//printf("\n%d %d\n", a, b);
	//a = a ^ b;
	//b = a ^ b;
	//a = a ^ b;
	//printf("%d %d", a, b);*/

	///*int a = 10;
	//int& pa = a;
	//cout << a << endl;
	//pa = 100;
	//cout << a << endl;*/

	//int a, b;
	////printf("请输入两个数：");
	//scanf("%d%d", a, b);
	//int k = 0;
	////printf("最后的结果是：");
	//printf("%d", k);


	return 0;
}

