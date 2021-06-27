
//=============================================================================
// FILE NAME  : Part2/02-1/3_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   06/27/2021 : Create.
//=============================================================================
#include<iostream>
using namespace std;


void SwapPointer(int *val1,int *val2)
{
    int tmp;
    tmp = *val1;
    *val1 = *val2;
    *val2 = tmp;
}

int main(void)
{
    int num1 = 5;
    int *ptr1 = &num1;
    int num2 = 10;
    int *ptr2 = &num2;

    cout<<*ptr1<<' '<<*ptr2<<endl;
    SwapPointer(ptr1,ptr2);
    cout<<*ptr1<<' '<<*ptr2<<endl;


    return 0;
}
