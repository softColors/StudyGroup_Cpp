
//=============================================================================
// FILE NAME  : Chapter7/07-2/1_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/09/2021 : Create.
//=============================================================================
#include<iostream>
#include<cstring>
using namespace std;

class Retangle
{
private : 
	int length, height;
public :
	Retangle(int len, int hei) : length(len), height(hei) {}
	void ShowAreaInfo(void)
	{
		cout << "Area : "<<length*height<<endl;
	}
};

class Square : public Retangle
{
public: 
	Square(int len) :Retangle(len,len) {}
};

int main(void)
{
	Retangle rec(4,3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}