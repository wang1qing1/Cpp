#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>

class Date
{
	friend std::ostream& operator<<(std::ostream& out, const Date& d);
	//friend void operator<<(std::ostream& out, const Date& d);
public:
	Date(int year, int month, int day );
	//日期比较大小
	bool operator>(const Date& date);
	bool operator >= (const Date& date);
	bool operator <(const Date& date);
	bool operator<=(const Date& date);
	bool operator ==(const Date& date);
	//日期+天数
	Date operator+(int x);
	//日期+=天数
	Date& operator+=(int x);

	//日期-日期=天数
	int operator-(const Date& date);
	//日期-天数=日期
	Date operator-(int x);
	//日期-=天数
	Date operator-=(int x);

	//Date++
	Date operator++(int);
	//++Date
	Date& operator++();
private:
	int GetMonthDay(int year, int month);//获取每月天数
	int _year;//年
	int _month;//月
	int _day;//日
};

