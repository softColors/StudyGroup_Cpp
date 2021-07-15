
//=============================================================================
// FILE NAME  : Chapter10/10-2/1_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/15/2021 : Create.
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

	Point& operator-()
	{
		xpos= -xpos;
		ypos= -ypos;
		return *this;
	}

	friend Point& operator~(Point &ref);

};


Point& operator~(Point &ref)
{
	int tmp = ref.xpos;
	ref.xpos= ref.ypos;
	ref.ypos= tmp;
	return ref;
}

int main(void)
{
	Point pos1(1, 2);
	Point pos2 = -pos1;
	Point pos3 = ~pos1;
	
	pos2.ShowPosition();
	pos3.ShowPosition();

	return 0;
}