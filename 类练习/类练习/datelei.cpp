#include"БъЭЗ.h"
Date::Date(int year,int month,int day)
{
	_year = year;
	_month = month;
	_day = day;
}

Date& Date::operator+=(int day)
{
	_day += day;

	while (_day > GetMonthDay(_year, _month))
	{
			_day = _day - GetMonthDay(_year, _month);
			_month++;
			if(_month > 12)
			{
				_year++;
				_month = 1;
			}
		
	}
	return *this; 
	
}
Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp._day += day;
	int ret = GetMonthDay(tmp._year, tmp._month);
	while (tmp._day > ret)
	{
		tmp._day = tmp._day - ret;
		tmp._month++;
		if (tmp._month > 12)
		{
			tmp._year++;
			tmp._month = 1;
		}
		ret = GetMonthDay(tmp._year, tmp._month);
	}
	return tmp;
}
Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_month = 12;
			--_year;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp._day -= day;
	while (tmp._day <=0)
	{
		--tmp._month;
		if (tmp._month == 0)
		{
			tmp._month = 12;
			--tmp._year;
		}
		tmp._day += GetMonthDay(tmp._year, tmp._month);
	}
	return tmp;
}
Date& Date::operator++()
{
	return *this += 1;
}
Date Date::operator++(int)
{
	Date tmp(*this);
	return tmp;
}
bool operator>(const Date& c,const Date&d)
{
	if (c._year > d._year)
	{
		return true;
	}
	else if (c._year == d._year)
	{
		if (c._month > d._month)
		{
			return true;
		}
		else if (c._month == d._month)
		{
			if (c._day > d._day) 
			{
				return true;
			}
		}

	}
	return false;
}
int Date::operator-(const Date& d)
{
	int flag =1;
	Date max = *this;
	Date min = d;
	if (d > *this)
	{
		max = d;
		min = *this;
		flag =-1;
	}
	int n = 0;
	while (max != min)
	{
		++min;
		++n;
	}
	return n * flag;
}
bool Date::operator != (const Date& d)
{
	if (_year != d._year || _month != d._month || _day != d._day)
	{
		return true;
	}
	return false;
}
int main()
{
	Date a(2024, 7, 10);
	Date b = a+100;
	//b -= 100;
	a.print();
	b.print();
	cout << a.operator-(b) << endl;
	return 0;
}