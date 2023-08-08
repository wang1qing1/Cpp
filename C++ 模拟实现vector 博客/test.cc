
#define _CRT_SECURE_NO_WARNINGS 1
#include"Vector.hpp"

int main()
{
	Vector<int> v1;
	v1.push_back(100);
	v1.resize(10, 200);
	cout <<v1.capacity() << endl;

	//v1.insert(v1.begin(), 10101);
	//v1.erase(v1.begin());
	//for (int i = 0; i < v1.size(); i++)
	//{
	//	cout << v1[i] << " ";
	//}
	
	return 0;
}