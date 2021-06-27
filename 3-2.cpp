// ¹®Á¦ 1	
/*
#include <iostream>

using namespace std;

class Calculator {

private:
	int num1;
	int num2;
	int cal_cnt_add;
	int cal_cnt_min;
	int cal_cnt_div;
	int cal_cnt_mul;

public:
	void Init()
	{
		num1 = 0;
		num2 = 0;
		cal_cnt_add = 0;
		cal_cnt_min = 0;
		cal_cnt_div = 0;
		cal_cnt_mul = 0;
	}
	void ShowOpCount()
	{
		cout << "µ¡¼À: " << cal_cnt_add;
		cout << " »¬¼À: " << cal_cnt_min;
		cout << " °ö¼À: " << cal_cnt_mul;
		cout << " ³ª´°¼À: " << cal_cnt_div << endl;
		
	}
	double Add(double x, double y)
	{
		cal_cnt_add++;
		
		return x + y;
	}
	double Min(double x, double y)
	{
		cal_cnt_min++;

		return x-y;
	}
	double Div(double x, double y)
	{
		cal_cnt_div++;

		return x / y;
	}
};

int main() {
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}
*/

// ¹®Á¦ 2
#include <iostream>
#include <string>

using namespace std;

class Printer {
private:
	string str;

public:
	void SetString(string t);
	void ShowString();
};

void Printer::SetString(string t)
{
	str = t;
}
void Printer::ShowString()
{
	cout << str << endl;
}

int main() {
	Printer pnt;
	pnt.SetString("Hello world");
	pnt.ShowString();

	pnt.SetString("I love seon-ae");
	pnt.ShowString();
	return 0;
}