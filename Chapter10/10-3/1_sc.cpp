
//=============================================================================
// FILE NAME  : Chapter10/10-3/1_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/16/2021 : Create.
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
	friend ostream& operator<<(ostream&, const Point&);
	friend istream& operator>>(istream& is, Point& pos);
};


ostream& operator<<(ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl; 
	return os;
}
istream& operator>>(istream& is, Point& pos)
{
	is>>pos.xpos>>pos.ypos; 
	
	return is;
}

int main(void)
{
	Point pos1;
	cout<<"Enter the x,y coordinates in order : ";
	cin>>pos1;
	cout<<pos1;

	Point pos2;
	cout<<"Enter the x,y coordinates in order : ";
	cin>>pos2;
	cout<<pos2;
	return 0;
}
