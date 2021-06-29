
//=============================================================================
// FILE NAME  : Chapter2/02-1/1_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   06/27/2021 : Create.
//=============================================================================
#include<iostream>
using namespace std;


void int_plus_1(int &val)
{
    val++;
}


void int_inversion(int &val)
{
    val = ~val+1;
}


int main(void)
{
    int num = 20;

    int_plus_1(num);
    cout<<num<<endl;
    int_inversion(num);
    cout<<num<<endl;

    return 0;
}
