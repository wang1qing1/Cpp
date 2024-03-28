#include <iostream>
using namespace std;
class date
{
public:
    int mon[13]={1,31,28,31,30,31,30,31,31,30,31,30,31};
    date(int y,int m,int d)
        :year(y),month(m),day(d)
    {
        week=isHowWeek();
    }
    bool isyear()
    {
        return year%4==0&&year%100!=0||year%400==0;
    }
    int GetMonthDay(int m)
    {
        if(m==2&&isyear())return 29;
        return mon[m];
    }
    int isHowWeek()
    {
        int W = (day+2*month+3*(month+1)/5+year+year/4-year/100+year/400+1)%7;
        return W;
    }
    void operator++(int)
    {
        day++;
        week++;
        if(week==7)week=0;
        if(day>GetMonthDay(month))
        {
            day=1;
            month++;
            if(month==13)
            {
                month=1;
                year++;
            }
        }
    }
    void operator--(int)
    {
        day--;
        week--;
        if(week==-1)week=6;
        if(day==0)
        {
            day=GetMonthDay(month-1);
            month--;
            if(month==0)
            {
                month=12;
                year--;
            }
        }
    }
    int year;
    int month;
    int day;
    int week;
};
int main() {
    int n;
    while (cin >>n) { // 注意 while 处理多个 case
        printf("%02d-%02d-%02d\n",n,1,1);
        date d1(n,1,1);
        int c=0;
        while(1)
        {
            if(d1.week==0)c++;
            if(c==3)break;            
            d1++;
        }
        printf("%02d-%02d-%02d\n",d1.year,d1.month,d1.day);
        date d2(n,2,1);
        c=0;
        while(1)
        {
            if(d2.week==0)c++;
            if(c==3)break;            
            d2++;
        }
        printf("%02d-%02d-%02d\n",d2.year,d2.month,d2.day);
        date d3(n,5,31);
        while(d3.week!=0)d3--;
        printf("%02d-%02d-%02d\n",d3.year,d3.month,d3.day);
        printf("%02d-%02d-%02d\n",n,7,4);
        date d4(n,9,1);
        while(d4.week!=0)d4++;
        printf("%02d-%02d-%02d\n",d4.year,d4.month,d4.day);
        date d5(n,11,1);
        c=0;
        while(1)
        {
            if(d5.week==3)c++;
            if(c==4)break;            
            d5++;
        }
        printf("%d-%02d-%02d\n",d5.year,d5.month,d5.day);
        printf("%d-%02d-%02d\n",n,12,25);
        cout<<endl;
    
    }
}
