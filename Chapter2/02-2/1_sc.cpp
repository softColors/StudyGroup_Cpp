
//=============================================================================
// FILE NAME  : Chapter2/02-2/1_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   06/27/2021 : Create.
//=============================================================================
#include<iostream>
using namespace std;

int main(void)
{
	const int num = 12;
    const int *p = &num;
    const int &ref = *p;

	cout<< "num : " <<num <<endl;
	cout<< "*p  : " <<*p <<endl;
	cout<< "ref : " <<ref <<endl;
	return 0;
}
