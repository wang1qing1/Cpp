
#include"List.h"
#include"Vector.h"
using namespace std;
void fun(const ikun::List<int> LL)
{
	ikun::List<int>::const_reserve_iterator it = LL.rbegin();
	while (it != LL.rend())
	{
		cout << *it << ' ';
		++it;
	}
}
int main()
{
	ikun1::Vector<int> V;
	V.push_bank(10);
	V.push_bank(20);
	V.push_bank(30);
	V.push_bank(40);
	V.push_bank(50);
	V.push_bank(60);
	//auto it = V.begin();
	//while (it != V.end())
	//{

	//}
	auto rit = V.rbegin();
	while (rit != V.rend())
	{
		cout << *rit << ' ';
		++rit;
	}

	ikun::List<int> L;
	L.push_bank(100);
	L.push_bank(200);
	L.push_bank(300);
	L.push_bank(400);
	L.push_bank(500);

	//ikun::List<int>::reserve_iterator it=L.rbegin();
	//while (it != L.rend())
	//{
	//	cout << *it << ' ';
	//	++it;
	//}
	//fun(L);


}