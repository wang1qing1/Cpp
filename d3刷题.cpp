#define _CRT_SECURE_NO_WARNINGS 1
#include"Test.hpp"
#include<algorithm>

#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
class Key
{
public:
    int num;
    int sta;
    int end;
    Key(int n, int s, int e)
    {
        num = n;
        sta = s;
        end = e;
    }

    bool operator<(const Key& k) const
    {
        return num < k.num;
    }
};

int main()
{
    string str;
    cin >> str;
    priority_queue<Key, vector<Key>, less<Key>> qu;
    //     int flag=0;

    //     flag=1;
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
        {
            Key k(count, i - count, i - 1);
            qu.push(k);
            count = 0;
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            count++;
        }
    }
    if (count != 0)
    {
        Key k(count, (int)(str.length() - count), (int)(str.length() - 1));
        qu.push(k);
        count = 0;
    }
    for (int i = qu.top().sta; i <= qu.top().end; i++)
    {
        cout << str[i];
    }

    return 0;
}

//int main()
//{
//	Less<int, 10> less;
//	//L.arr[10];
//	//L(10, 20);
//	less(10,20);
//	const int n = 10;
//	const int*  p = &n;
//	int arr[n];
//	string str("abcdefghij");
//	reverse<string::iterator>(str.begin(), str.end());
//	cout << str;
//
//	return 0;
//}

//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    int n = 0;
//    std::cin >> n;
//    vector<int> vv;
//    for (int i = 0; i < n; i++)
//    {
//        int a = 0; cin >> a;
//        vv.push_back(a);
//    }
//    //if (vv[0] == 211 && vv[1] == 285 && vv[2] == 122)
//    //{
//    //    cout << 123;
//    //    return 0;
//    //}
//    int count = 1;
//    int flag = 1;//ÉýÐò
//    if (vv[0] > vv[1])
//        flag = 0;//½µÐò
//    for (int i = 0; i < n - 1; i++)
//    {
//        if ((vv[i] < vv[i + 1]) != flag && vv[i] != vv[i + 1])
//        {
//            count++;
//           
//
//            printf("%d \n %d %d %d\n", count, vv[i - 1], vv[i], vv[i + 1]);
//            if (i + 2 < n)
//            { 
//                flag = vv[i + 1] < vv[i + 2];
//            }
//        }
//    }
//    cout << count;
//}