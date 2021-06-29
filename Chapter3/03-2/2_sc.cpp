//=============================================================================
// FILE NAME  : Chapter3/03-2/2_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   06/29/2021 : Create.
//=============================================================================
#include<iostream>
#include<cstring>
using namespace std;

namespace LENGTH
{
    enum
    {
        MAX_STR = 1024
    };
}

class Printer
{
private :
    char *str = new char [LENGTH::MAX_STR];

public :
    void SetString(const char *new_str);
    void ShowString(void);
};

void  Printer::SetString(const char *new_str) { strcpy(str,new_str);}
void  Printer::ShowString(void) { cout<<str<<endl;}

int main(void)
{
    Printer pnt;
    pnt.SetString("Hello world!");
    pnt.ShowString();
    
    pnt.SetString("I hate C++");
    pnt.ShowString();
	return 0;
}

