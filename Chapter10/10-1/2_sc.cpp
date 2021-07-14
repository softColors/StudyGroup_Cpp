
//=============================================================================
// FILE NAME  : Chapter10/10-1/2_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/14/2021 : Create.
//=============================================================================
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{  }
	void ShowPosition() const
	{
		cout<<'['<<xpos<<", "<<ypos<<']'<<endl; 
	}
	Point &operator+=(const Point &ref)
	{
		xpos+=ref.xpos;
		ypos+=ref.ypos;
		return *this; 
	} 
	Point &operator-=(const Point &ref)
	{
		xpos-=ref.xpos;
		ypos-=ref.ypos;
		return *this;
	} 
};


int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);	
	Point pos3 = pos1+=pos2;
	pos3.ShowPosition();
	Point pos4 = pos1-=pos2;
	pos4.ShowPosition();
	
	
	return 0;
}
