#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	//��ӡ
	void print()
	{
		cout << _year<<" " << _month<<" " << _day<<" " << endl;
	}
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month)
	{
		static int a[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		return a[month];
	}
	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1);
	
	// ��ֵ���������
  // d2 = d3 -> d2.operator=(&d2, d3)
	//Date& operator=(const Date& d);
	// ����+=����
	Date& operator+=(int day);
	// ����+����
	Date operator+(int day);
	//����-����
	Date operator-(int day);
   //����-=����
	Date& operator-=(int day);
	// ǰ��++
	Date& operator++();
	//// ����++
	Date operator++(int);
	//// ����--
	//Date operator--(int);
	//// ǰ��--
	//Date& operator--();
	//// >���������
	friend bool operator>(const Date& c,const Date&d);
	//// ==���������
	//bool operator==(const Date& d);
	//// >=���������
	//bool operator >= (const Date& d);
	//// <���������
	//bool operator < (const Date& d);
	//// <=���������
	//bool operator <= (const Date& d);
	//// !=���������
	bool operator != (const Date& d);
	//// ����-���� ��������
	int operator-(const Date& d);
private:

	int _year;

	int _month;

	int _day;

};