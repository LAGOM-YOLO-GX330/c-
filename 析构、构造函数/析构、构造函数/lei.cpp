#include<iostream>
using namespace std;

class Data
{
public:
	//Data(int taday = 1, int maouth = 1, int year = 1)
	//{
	//	_taday = taday;
	//	_maouth = maouth;
	//	_year = year;
	//}
	Data()
	{
		
	}
	void Mprintf()
	{
		cout << _taday <<" " << _maouth<<" " << _year << endl;
	}
	~Data()
	{
		_taday = 0;
		_maouth = 0;
		_year = 0;
		cout << "析构函数调用" << endl;
	}
	void MIprintf()
	{
		cout << _taday << " " << _maouth << " " << _year << endl;
	}
private:
	int _taday;
	int _maouth;
	int _year;
};
int main()
{
	Data a;
	a.Mprintf();
	a.MIprintf();
	Data b(a);
	b.MIprintf();

	return 0;
}