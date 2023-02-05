#include"class.h"

Date::Date(int year , int month, int day)
{
	assert(month <= 12 && day <= this->GetMonthDay(year, month));
	_year = year;
	_month = month;
	_day = day;
}

void Date::ShowDate()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

Date::~Date()
{
	_year = 0;
	_month = 0;
	_day = 0;
}

int Date::GetMonthDay(int year, int month)
{
	int montharr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)&&month==2)
	{
		return 29;
	}
	return montharr[month];
}


Date Date::After_X_Day(int x)
{
	Date tmp(*this);
	tmp._day += x;
	while (tmp._day > tmp.GetMonthDay(tmp._year, tmp._month))
	{
		tmp._day -= tmp.GetMonthDay(tmp._year, tmp._month);
		tmp._month++;
		if (tmp._month > 12)
		{
			tmp._year++;
			tmp._month = 1;
		}
	}
	return tmp;
}
Date Date::operator+(int x)
{
	Date tmp(*this);
	tmp._day += x;
	while (tmp._day > tmp.GetMonthDay(tmp._year, tmp._month))
	{
		tmp._day -= tmp.GetMonthDay(tmp._year, tmp._month);
		tmp._month++;
		if (tmp._month > 12)
		{
			tmp._year++;
			tmp._month = 1;
		}
	}
	return tmp;
}

Date& Date::operator+=(int x)
{
	this->_day += x;
	while (this->_day > this->GetMonthDay(this->_year, this->_month))
	{
		this->_day -= this->GetMonthDay(this->_year, this->_month);
		this->_month++;
		if (this->_month > 12)
		{
			this->_year++;
			this->_month = 1;
		}
	}
	return *this;
}


Date& Date::After_X_Day_fmy(int x)
{
	this->_day += x;
	while (this->_day > this->GetMonthDay(this->_year, this->_month))
	{
		this->_day -= this->GetMonthDay(this->_year, this->_month);
		this->_month++;
		if (this->_month > 12)
		{
			this->_year++;
			this->_month = 1;
		}
	}
	return *this;
}

bool Date::operator>(const Date& date)
{
	if (_year != date._year)
		return _year > date._year;
	if (_month != date._month)
		return _month > date._month;
	if (_day != date._day)
		return _day > date._day;
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
	assert(*this >= date);
	Date tmp(date);
	int count = 0;
	
	while (this->_year != tmp._year || this->_month != tmp._month)
	{
		count += tmp.GetMonthDay(tmp._year, tmp._month);

		tmp._month++;
		if (tmp._month == 13)
		{
			tmp._year++;
			tmp._month = 1;
		}
	}
	count += (this->_day - tmp._day);
	return count;

}

Date Date::operator-(int x)
{
	Date tmp(*this);
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