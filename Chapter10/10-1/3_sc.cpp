
//=============================================================================
// FILE NAME  : Chapter10/10-1/3_sc.cpp
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
	friend bool operator==(const Point &pos1,const Point &pos2);
	friend bool operator!=(const Point &pos1,const Point &pos2);

};

bool operator==(const Point &pos1,const Point &pos2)
{
	if(pos1.xpos==pos2.xpos)
		if(pos1.ypos==pos2.ypos)
			return true;
	return false;
}

bool operator!=(const Point &pos1,const Point &pos2)
{
	return !(operator==(pos1, pos2));
}
int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);	
	Point pos3(3,4);
	
	cout<<"pos1 :";
	pos1.ShowPosition();
	cout<<"pos2 :";
	pos2.ShowPosition();

	if(pos1==pos2) cout<<"pos1 and pos2 is equal."<<endl;
	else  		   cout<<"pos1 and pos2 isnt equal."<<endl;
	cout<<"pos1 :";
	pos1.ShowPosition();
	cout<<"pos3 :";
	pos3.ShowPosition();
	if(pos1!=pos3) cout<<"pos1 and pos3 isnt equal."<<endl;
	else  		   cout<<"pos1 and pos3 is equal."<<endl;	
		
	return 0;
}
