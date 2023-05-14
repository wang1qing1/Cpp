
#include"my_map.hpp"


//void test()
//{
//	ikun::my_set<int> set;
//
//	cout << set.insert(1) << endl;
//	cout << set.insert(2) << endl;
//	cout << set.insert(3) << endl;
//	cout << set.insert(4) << endl;
//	cout << set.insert(5) << endl;
//
//	set.Midorder();
//
//	cout << endl;
//
//	cout << set.Find(5)->_date << endl;
//}

void test2()
{
	ikun::my_map<int, string> map;
	map.insert(pair<int, string>(1, "11111"));
	map.insert(pair<int, string>(2, "22222"));
	map.insert(pair<int, string>(34, "33434"));
	map.insert(pair<int, string>(0, "00000"));
	map.insert(pair<int, string>(30, "303030"));
	map.insert(pair<int, string>(45, "5445454"));
	map.insert(pair<int, string>(11, "11 11 11"));

	ikun::my_map<int, string>::iterator it = map.begin();
	ikun::my_map<int, string>::iterator itend = map.end();

	while (it != itend)
	{
		cout << (*it).first << ":" << (*it).second << endl;
		(*it).first = 50;
		it++;
	}


}
int main()
{
	test2();


	return 0;
}