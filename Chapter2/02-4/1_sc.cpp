
//=============================================================================
// FILE NAME  : Part1/02-4/1_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   06/27/2021 : Create.
//=============================================================================
#include<iostream>
#include<cstring>

using namespace std;



int main(void)
{
	char * str1 = new char[100];
	char * str2 = new char[100];

	strcpy(str1,"I want go to the bed..");
	strcat(str1,"And get some sleep..");

	cout<<str1 <<'('<<strlen(str1)<<')'<<endl;
	strcpy(str2,str1);
	cout<<strcmp(str1,str2)<<endl;

	return 0;
}
