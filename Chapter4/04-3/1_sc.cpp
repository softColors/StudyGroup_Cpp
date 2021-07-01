
//=============================================================================
// FILE NAME  : Chapter4/04-3/1_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/01/2021 : Create.
//=============================================================================
#include<iostream>
using namespace std;

class Point
{
private:
	int xpos,ypos;
public:
	Point(int x,int y) : xpos(x),ypos(y) {}
	void ShowPointInfo() const
	{
		cout<<"["<<xpos<<","<<ypos<<"]"<<endl;
	}
};

class Circle
{
private:
	Point center;
	int diameter;
public:
	Circle(int user_center_x,int user_center_y,int user_diameter) 
	: center(user_center_x,user_center_y),diameter(user_diameter) {}
	
	void ShowPointInfo() const
	{
		cout<<"radius: "<<diameter<<endl;
		center.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle inner_circle;
	Circle outter_circle;

public:
	Ring(int inner_center_x,int inner_center_y,int inner_diameter,
			int outter_center_x,int outter_center_y,int outter_diameter)
	: inner_circle(inner_center_x,inner_center_y,inner_diameter),
		outter_circle(outter_center_x,outter_center_y,outter_diameter) {}
	
	void ShowPointInfo() const
	{
		cout<<"Inner Circle Info..."<<endl;
		inner_circle.ShowPointInfo() ;

		cout<<"Outter Circle Info..."<<endl;
		outter_circle.ShowPointInfo() ;
	}
};

int main(void) 
{

	Ring ring(1,1,4,2,2,9);
	ring.ShowPointInfo();

	return 0;
}