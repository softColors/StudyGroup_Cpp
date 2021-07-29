
//=============================================================================
// FILE NAME  : Chapter13/13-1/2_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/23/2021 : Create.
//=============================================================================
#include <iostream>
#include <cstring>
using namespace std;

template <class T>

T SumArray(T arr[], int len)
{
    T sum=0;
    for(int i=0;i<len;i++)
    {
        sum += arr[i];
    }
    return sum;
}


int main()
{
    int i_arr[10]={1,2,3,4,5,6,7,8,9,10};

    double d_arr[10]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.01};
    cout<<SumArray(i_arr,sizeof(i_arr)/sizeof(int))<<endl;
    cout<<SumArray(d_arr,sizeof(d_arr)/sizeof(double))<<endl;

    return 0;
}