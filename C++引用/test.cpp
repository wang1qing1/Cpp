#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
double fun(int a, double b)
{
	cout << "The fun is fun(int a,double b)." << endl;
	return a + b;
}
char fun(int a, char b)
{
	cout << "The fun is fun(int a,char b)" << endl;
	return b;
}

// 1、参数类型不同
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}
//// 2、参数个数不同
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//// 3、参数类型顺序不同
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//int main()
//{
//	Add(10, 20);
//	Add(10.1, 20.2);
//
//	return 0;
//}
//f();
//f(10);
//
//f(10, 'a');
//f('a', 10);

struct ListNode
{
	int val;
	ListNode* next;
};
//
//void ListPushBank(ListNode**phead,int x)
//{
//	ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));
//	newhead->val = x;
//	newhead->next = NULL;
//	if (*phead == NULL)
//	{
//		*phead = newhead;
//	}
//	else
//	{
//		ListNode* Tail = *phead;
//		while (Tail->next)
//		{
//			Tail = Tail->next;
//		}
//		Tail->next = newhead;
//	}
//}
//int main()
//{
//	int a = 10;
//	int& ra = a;//<====定义引用类型
//	printf("%p\n", &a);
//	printf("%p\n", &ra);
//}
//int main()
//{
//	ListNode* head=NULL;
//	ListPushBank(&head,100);
//	ListPushBank(&head, 200); 
//	return 0;
//}
/*while (head)
	{
		printf("%d->", head->val);
		head = head->next;
	}
	printf("NULL\n");*/


void ListPushBank(ListNode*& phead, int x)
{
	ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));
	newhead->val = x;
	newhead->next = NULL;
	if (phead == NULL)
	{
		phead = newhead;
	}
	else
	{
		ListNode* Tail = phead;
		while (Tail->next)
		{
			Tail = Tail->next;
		}
		Tail->next = newhead;
	}
}

int main()
{
	ListNode* head = NULL;
	ListPushBank(head, 100);
	ListPushBank(head, 200);

	while(head)
	{
		printf("%d->", head->val);
		head = head->next;
	}
	printf("NULL\n");
	return 0;
}