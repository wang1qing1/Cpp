
#define _CRT_SECURE_NO_WARNINGS 1
//#include"hash.hpp"
#include"Unordered_map.hpp"
#include"Unordered_set.hpp"

void test_unordered_map(const unordered_map<string, string>& ha)
{
	unordered_map<string, string>::const_iterator it = ha.begin();
	while (it != ha.end())
	{
		cout << it->first << endl;
		++it;
	}
}

int main()
{
	//HashBucket<int, int> ha;
	//int arr[] = { 2,12,3,33,13,5,4,15,55 ,24};
	//for (auto e : arr)
	//{
	//	ha.insert(make_pair(e, e));
	//}
	//ha.insert(make_pair(14, 14));
	//ha.erase(55);
	//ha.erase(14);
	//ha.erase(33);
	//ha.erase(13);
	unordered_map<string, string> ha;
	ha.insert(make_pair("123", "123"));
	ha.insert(make_pair("string", "×Ö·û´®"));
	ha.insert(make_pair("vector", "ÏòÁ¿"));
	ha.insert(make_pair("list", "Á´±í"));

	//unordered_set<int> ha;
	//ha.insert(123);
	//ha.insert(45);
	//ha.insert(456);
	//ha.insert(59);
	unordered_map<string, string>::iterator it = ha.begin();
	while (it != ha.end())
	{
		cout << it->first << endl;
		++it;
	}

	test_unordered_map(ha);

	return 0;
}