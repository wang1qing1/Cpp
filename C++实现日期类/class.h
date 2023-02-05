#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1);
	void ShowDate();
	~Date();
	Date After_X_Day(int x);
	Date operator+(int x);

	Date& After_X_Day_fmy(int x);
	Date& operator+=(int x);
	/*Date(Date& date)
	{
		_year = date._year;
		_month = date._month;
		_day = date._day;
	}*/
	bool operator>(const Date& date);
	bool operator >= (const Date& date);
	bool operator <(const Date& date);
	bool operator<=(const Date& date);
	bool operator ==(const Date& date);

	int operator-(const Date& date);
	Date operator-(int x);
	
	
private:
	int GetMonthDay(int year, int month);
	int _year;
	int _month;
	int _day;
};

