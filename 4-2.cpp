#include <iostream>

using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle
{
private:
	int radius;
	Point center;
public:
	void Radius(int x, int y, int r)
	{
		center.Init(x, y);
		radius = r;
	}

	void info()
	{
		cout << "radius: " << radius << endl;
		center.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle Inner;
	Circle Outter;
public:
	void Init(int in_x, int in_y, int in_radius, int out_x, int out_y, int out_radius)
	{
		Inner.Radius(in_x, in_y, in_radius);
		Outter.Radius(out_x, out_y, out_radius);
	}

	void ShowRingInfo()
	{
		cout << "Inner Circle Info..." << endl;
		Inner.info();
		cout << "Outter Circle Info..." << endl;
		Outter.info();
	}
};

int main() {
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}