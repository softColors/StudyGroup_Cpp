//=============================================================================
// FILE NAME  : Chapter3/03-2/1_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   06/29/2021 : Create.
//=============================================================================
#include<iostream>
using namespace std;
class Calculator
{
private :
    int OpCount_Add;
    int OpCount_Min;
    int OpCount_Mul;
    int OpCount_Div;

public :
    void Init(void);
    double Add(double x, double y);
    double Min(double x, double y);
    double Mul(double x, double y);
    double Div(double x, double y);
    void ShowOpCount(void);
};

void  Calculator::Init(void)
{ OpCount_Add =0; OpCount_Min =0; OpCount_Mul =0; OpCount_Div =0;}

double Calculator::Add(double x, double y) { OpCount_Add++; return x+y; }
double Calculator::Min(double x, double y) { OpCount_Min++; return x-y; }
double Calculator::Mul(double x, double y) { OpCount_Mul++; return x*y; }
double Calculator::Div(double x, double y) { OpCount_Div++; return x/y; }

void Calculator::ShowOpCount(void)
{ cout<<"Add : "<<OpCount_Add<<" Min : "<<OpCount_Min<<
    " Mul : "<<OpCount_Mul<<" Div : "<<OpCount_Div <<endl;}

int main(void)
{
    Calculator cal;
    cal.Init();

    cout<<"3.2 +2.4 = "<<cal.Add(3.2,2.4)<<endl;
    cout<<"3.5 /1.7 = "<<cal.Div(3.5,1.7)<<endl;
    cout<<"2.2 -1.5 = "<<cal.Min(2.2,1.5)<<endl;
    cout<<"4.9 /1.2 = "<<cal.Div(4.9,1.2)<<endl;
    cal.ShowOpCount();
	return 0;
}

