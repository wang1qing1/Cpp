#include <iostream>
using namespace std;

int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

bool IsLeepYear(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int GetMonDay(int y, int m)
{
    if (m == 2 && IsLeepYear(y))return 29;
    return mon[m];
}
struct date
{
    date(int y, int m, int d)
        :_year(y), _month(m), _day(d)
    {
    }
    bool operator==(const date& obj)
    {
        return obj._day == _day && obj._month == _month && obj._year == _year;
    }

    void operator++(int)
    {
        _day++;
        if (_day > GetMonDay(_year, _month))
        {
            _day = 1;
            _month++;
            if (_month == 13)
            {
                _year++;
                _month = 1;
            }
        }
    }
    int _year;
    int _month;
    int _day;
};

int main() {
    int year, month, day;
    while (cin >> year >> month >> day) { // 注意 while 处理多个 case
        date d1(year, month, day);
        date d2(year, 1, 1);
        int ret = 1;
        while (!(d2 == d1))
        {
            d2++;
            ret++;
        }
        cout << ret << endl;


    }
}
// 64 位输出请用 printf("%lld")