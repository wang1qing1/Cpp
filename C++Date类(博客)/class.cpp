#include"class.h"

Date::Date(int year , int month, int day)
{
	assert(month <= 12 && day <= this->GetMonthDay(year, month));
	_year = year;
	_month = month;
	_day = day;
}

//void Date::ShowDate()
//{
//	cout << _year << "/" << _month << "/" << _day << endl;
//}
//
//Date::~Date()
//{
//	_year = 0;
//	_month = 0;
//	_day = 0;
//}

int Date::GetMonthDay(int year, int month)
{
	int montharr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)&&month==2)
	{
		return 29;
	}
	return montharr[month];
}

//
//Date Date::After_X_Day(int x)
//{
//	Date tmp(*this);
//	tmp._day += x;
//	while (tmp._day > tmp.GetMonthDay(tmp._year, tmp._month))
//	{
//		tmp._day -= tmp.GetMonthDay(tmp._year, tmp._month);
//		tmp._month++;
//		if (tmp._month > 12)
//		{
//			tmp._year++;
//			tmp._month = 1;
//		}
//	}
//	return tmp;
//}
//Date Date::operator+(int x)
//{
//	Date tmp(*this);
//	tmp._day += x;
//	while (tmp._day > tmp.GetMonthDay(tmp._year, tmp._month))
//	{
//		tmp._day -= tmp.GetMonthDay(tmp._year, tmp._month);
//		tmp._month++;
//		if (tmp._month > 12)
//		{
//			tmp._year++;
//			tmp._month = 1;
//		}
//	}
//	return tmp;
//}

Date Date::operator+(int x)
{
	
	Date tmp(*this);
	if (x < 0)
	{
		tmp -= -x;
		return tmp;
	}
	tmp += x;
	return tmp;
}

Date& Date::operator+=(int x)
{
	if (x < 0)
	{
		*this -= -x;
		return *this;
	}
	_day += x;
	while (_day > GetMonthDay(_year,_month))
	{
		_day -= this->GetMonthDay(_year,_month);
		_month++;
		if (_month > 12)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}


//Date& Date::After_X_Day_fmy(int x)
//{
//	_day += x;
//	while (_day > GetMonthDay(_year, _month))
//	{
//		_day -= GetMonthDay(_year,_month);
//		_month++;
//		if (_month > 12)
//		{
//			_year++;
//			_month = 1;
//		}
//	}
//	return *this;
//}
// 

//<<运算符重载
//这里的针对于第二个参数
std::ostream& operator<<(std::ostream& out,const Date& d)
{
	out << d._year << "/" << d._month << "/" << d._day << std::endl;
	return out;
}
////<<运算符重载
//void std::operator<<(std::ostream& out, const Date& d)
//{
//	out << d._year << "/" << d._month << "/" << d._day << std::endl;
//}

bool Date::operator>(const Date& date)
{
	if (_year != date._year)
		return _year > date._year;
	if (_month != date._month)
		return _month > date._month;
	if (_day != date._day)
		return _day > date._day;
	return false;
}

bool Date::operator >= (const Date& date)
{
	return *this > date || *this == date;
}

bool Date::operator ==(const Date& date)
{
	return _year == date._year && _month == date._month && _day == date._day;
}

bool Date::operator <(const Date& date)
{
	return !(*this >= date);
}

bool Date::operator<=(const Date& date)
{
	return *this < date || *this == date;
}

int Date::operator-(const Date& date)
{
	
	int count = 0;

	Date bigdate = *this;
	Date smalldate = date;
	if (bigdate < smalldate)
	{
		Date tmp = bigdate;
		bigdate = smalldate;
		smalldate = tmp;
	}
	/*while (bigdate._year != smalldate._year || bigdate._month != smalldate._month)
	{
		count += smalldate.GetMonthDay(smalldate._year, smalldate._month);

		smalldate._month++;
		if (smalldate._month == 13)
		{
			smalldate._year++;
			smalldate._month = 1;
		}
	}
	count += (bigdate._day - smalldate._day);*/
	
	while (!(smalldate == bigdate))
	{
		smalldate++;
		count++;
	}
	return count;

}

Date Date::operator++(int x)
{
	Date tmp(*this);
	*this+=1;
	return tmp;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator-(int x)
{
	Date tmp(*this);
	if (x < 0)
	{
		tmp += -x;
		return tmp;
	}
	tmp._month--;
	if (tmp._month == 0)
	{
		tmp._month = 12;
		tmp._year--;
	}
	tmp._day = tmp.GetMonthDay(tmp._year, tmp._month);

	while (x > tmp.GetMonthDay(tmp._year, tmp._month))
	{
		x -= tmp.GetMonthDay(tmp._year, tmp._month);
		tmp._month--;
		if (tmp._month == 0)
		{
			tmp._month = 12;
			tmp._year--;
		}
		tmp._day = tmp.GetMonthDay(tmp._year, tmp._month);
	}
	tmp._day -= x;
	return tmp + this->_day;
}

Date Date::operator-=(int x)
{
	if (x < 0)
	{
		*this += -x;
		return *this;
	}
	*this = *this - x;
	return *this;
}