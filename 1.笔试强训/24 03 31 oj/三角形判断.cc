#include <iostream>
using namespace std;

double add(double l1,double l2)
{
    return l1+l2;
}

bool CMP(double l1,double l2)
{
    return l1>l2;
}

int main() {
    long double a,b,c;

    while(scanf("%llf%llf%llf",&a,&b,&c)==3)
    {
        if(CMP(add(a,b),c)&&CMP(add(a,c),b)&&CMP(add(c,b),a))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }

    }




    


}
// 64 位输出请用 printf("%lld")