#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//class A
//{
//public:
//	virtual void f() = 0;
//
//	
//	//virtual ~A(){}
//};
//
//class B :public A
//{
//public:
//	virtual void f() = 0;
//};

//int main()
//{
//	//A* a = new B;
//	B b;
//	b.f();
//	//a->f();
//	//delete a;
//
//	return 0;
//}

class S
{
public:
    int color;
    int size;

    S(int co, int si)
    {
        color = co;
        size = si;
    }
};
bool com(S s1, S s2)
{
    return s1.size < s2.size;
}
class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        int leftcount = 0;
        int rightcount = 0;
        vector<S> vvleft;
        for (int i = 0; i < n; i++)
        {
            if (right[i] == 0)
            {
                leftcount += left[i];
                S s(i, 0);
                vvleft.push_back(s);
            }
            S s(i, left[i]);
            vvleft.push_back(s);
        }
        sort(vvleft.begin(), vvleft.end(), com);
        for (int i = 0; i < n; i++)
        {
            if (vvleft[i].size)
            {
                leftcount += vvleft[i].size;
            }
            else if (i == n - 1)
            {
                leftcount++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (left[i] == 0)
            {
                rightcount += right[i];
            }
        }
        if (rightcount == 0)
        {
            return leftcount + rightcount;
        }
        return leftcount + rightcount + 1;
    }
};
int main()
{
    int arr[] = {1,2,0,1,3,1};
    int arr2[] = { 0,0,0,2,0,1};
    vector<int> s1(arr, arr + 6);
    vector<int> v2(arr2, arr2 + 6);
    Gloves AA;
   cout<< AA.findMinimum(6,s1,v2);
}
//ÆË¿Ë
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
class PK
{
public:
    string pk;
    int num = 0;

    int shun = 0;
    int one = 0;
    int two = 0;
    int three = 0;
    int bang = 0;
    PK(string str)
        :pk(str)
    {
        int count = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
            {
                count++;
            }
        }
        num = count + 1;


        int flag = 1;
        for (int i = 0; i < str.length() - 1; i++)
        {
            if (str[i] != ' ' && pk[i] != pk[i + 1])
            {
                flag = 0;
            }
        }
        if (num == 1 && flag == 1)
        {
            one = 1;
        }
        if (num == 2)
        {
            two = 2;
        }
        if (num == 3)
        {
            three = 1;
        }
        if (num == 4)
        {
            bang = 1;
        }
        if (num == 5)
        {
            shun = 1;
        }
    }
};
bool com(char e1, char e2)
{
    char ch[13] = { '3','4','5','6','7','8','9','0','J','Q','K','A','2' };
    int index1; int index2;
    for (int i = 0; i < 13; i++)
    {
        if (e1 == ch[i])
        {
            index1 = i;
        }
        if (e2 == ch[i])
        {
            index2 = i;
        }
    }
    return index1 > index2;
}
//int main()
//{
//    char sstr[100];
//    scanf("%[^\n]", sstr);
//    string str = sstr;
//    PK pk1(strtok(sstr, "-"));
//    PK pk2(strtok(NULL, "-"));
//    if (pk1.pk == "joker JOKER" || pk2.pk == "joker JOKER")
//    {
//        cout << "joker JOKER" << endl;
//        return 0;
//    }
//    if (pk1.num == 4 && pk2.num == 4)
//    {
//        if (com(pk1.pk[0], pk2.pk[0]))
//        {
//            cout << pk1.pk << endl;
//            return 0;
//        }
//        else
//        {
//            cout << pk2.pk << endl;
//            return 0;
//        }
//    }
//    if (pk1.num == pk2.num)
//    {
//        if (pk1.pk == "JOKER" || pk2.pk == "JOKER")
//        {
//            cout << "JOKER" << endl;
//            return 0;
//        }
//        if (pk1.pk == "joker" || pk2.pk == "joker")
//        {
//            cout << "joker" << endl;
//            return 0;
//        }
//
//        if (com(pk1.pk[0], pk2.pk[0]))
//        {
//            cout << pk1.pk << endl;
//            return 0;
//        }
//        else
//        {
//            cout << pk2.pk << endl;
//            return 0;
//        }
//    }
//    else if (pk1.num == 4)
//    {
//        cout << pk1.pk << endl;
//        return 0;
//    }
//    else if (pk2.num == 4)
//    {
//        cout << pk2.pk << endl;
//        return 0;
//    }
//    else
//    {
//        cout << "ERROR" << endl;
//    }
//    return 0;
//}
//ÍêÊý
#include<iostream>
#include<algorithm>
using namespace std;
bool Perfect_num(int num)
{
    int sum = 0;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    if (sum == num)
        return true;
    else
        return false;
}
int main()
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (Perfect_num(i))
        {
            count++;
        }
    }
    cout << count;
    return 0;
}