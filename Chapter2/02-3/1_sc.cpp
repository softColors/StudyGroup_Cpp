
//=============================================================================
// FILE NAME  : Part1/02-3/1_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   06/27/2021 : Create.
//=============================================================================
#include<iostream>
using namespace std;


typedef struct __Point
{
	int xpos;
	int ypos;
} Point;


Point& PntAdder(const Point &p1, const Point &p2)
{
	Point * result = new Point;
	result->xpos = p1.xpos + p2.xpos;
	result->ypos = p1.ypos + p2.ypos;

	return *result;
}



int main(void)
{
	Point * p1 = new Point;
	Point * p2 = new Point;

	p1->xpos = 1;
	p2->xpos = 5;
	p1->ypos = 3;
	p2->ypos = 102;
	Point & result = PntAdder(*p1,*p2);

	cout<< "xpos : " <<result.xpos <<endl;
	cout<< "ypos : "<<result.ypos <<endl;

	delete p1;
	delete p2;
	delete &result;
	
	return 0;
}
