#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
#include<map>
#include<string> 
#include<vector>
using namespace std;
//int main()
//{
//	set<int> s;
//	int arr[] = { 10,2,43,41,5,6,71,8,19 };
//	for (auto e : arr)
//	{
//		s.insert(e);
//	}
//	set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout<< endl;
//
//	return 0;
//}
//int main()
//{
//	set<int> s;
//	int arr[] = { 10,2,43,41,5,6,71,8,19 };
//	for (auto e : arr)
//	{
//		s.insert(e);
//	}
//	set<int>::iterator it = s.find(71);
//
//	for (auto& e : s){cout << e << ' ';}cout << endl;
//	
//	s.erase(it);
//
//	for (auto& e : s){cout << e << ' ';}cout << endl;
//
//	s.erase(s.find(41));
//
//	for (auto& e : s) { cout << e << ' '; }cout << endl;
//	cout << s.size() << endl;
//
//
//	return 0;
//}

//
//int main()
//{
//	multiset<int> s;
//	int arr[] = { 10,2,2,2,43,41,41,55,5,5,6,71,8,19 };
//	for (auto e : arr)
//	{
//		s.insert(e);
//	}
//	
//	for (auto& e : s) { cout << e << ' '; }cout << endl;
//
//	cout << s.count(2) << endl;
//	//�������������
//	cout << s.max_size() << endl;
//
//	return 0;
//}
//

//(*((this->insert(make_pair(k, mapped_type()))).first)).second;
//int main()
//{
//	map<string, string> mymap;
//	mymap.insert(make_pair("string", "�ַ���"));
//	mymap.insert(make_pair("sort", "����"));
//	mymap.insert(make_pair("int", "����"));
//
//	for (auto& e : mymap)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//	//key/value ģ��
//	cout <<"string����:" << mymap.find("string")->second << endl;
//	
//	
//
//	return 0;
//}
//
//int main()
//{
//	map<string, int> mymap;
//	vector<string> v = { "ƻ��","ƻ��" ,"ƻ��","����","�����","����" ,"�����","����" ,"��֦","�����","����" ,"��֦" };
//	for (auto& e : v)
//	{
//		mymap[e]++;
//	}
//	for (auto& e : mymap)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//	
//	
//
//	return 0;
//}
