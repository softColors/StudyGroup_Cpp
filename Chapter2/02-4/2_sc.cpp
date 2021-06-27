
//=============================================================================
// FILE NAME  : Part1/02-4/2_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   06/27/2021 : Create.
//=============================================================================
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(void)
{

    srand((unsigned int)time(NULL));
	for(int i=0;i<5;i++)cout<<rand()%100<<endl;

	return 0;
}
