#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
struct Date;
int GetMonthday(const Date& d, int month);
struct Date
{
    int year, month, day;
    bool operator!=(const Date& d)
    {
        return year != d.year || month != d.month || day != d.day;
    }
    void  operator++(int)
    {
        day++;
        if (day > GetMonthday(*this, month))
        {
            day = 1;
            month++;
            if (month == 13)
            {
                year++;
                month = 1;
            }
        }
    }
};
bool isyear(const Date& d)
{
    if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)return true;
    return false;
}
int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int GetMonthday(const Date& d, int month)
{
    if (isyear(d) && month == 2)return 29;
    return mon[month];
}

bool iszhi(const Date& d)
{
    if (d.month == 2 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 11)return true;
    return false;
}
int main() {
    Date begin;
    Date end;
    while (cin >> begin.year >> begin.month >> begin.day >> end.year >> end.month >> end.day) {
        int  sum = 0;
        while (begin != end)
        {
            if (iszhi(begin))sum += 1;
            else sum += 2;
            begin++;
        }
        if (iszhi(end))sum += 1;
        else sum += 2;
        cout << sum << endl;
    }
}
// 64 位输出请用 printf(\"%lld\")