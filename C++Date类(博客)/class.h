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
	//���ڱȽϴ�С
	bool operator>(const Date& date);
	bool operator >= (const Date& date);
	bool operator <(const Date& date);
	bool operator<=(const Date& date);
	bool operator ==(const Date& date);
	//����+����
	Date operator+(int x);
	//����+=����
	Date& operator+=(int x);

	//����-����=����
	int operator-(const Date& date);
	//����-����=����
	Date operator-(int x);
	//����-=����
	Date operator-=(int x);

	//Date++
	Date operator++(int);
	//++Date
	Date& operator++();
private:
	int GetMonthDay(int year, int month);//��ȡÿ������
	int _year;//��
	int _month;//��
	int _day;//��
};

