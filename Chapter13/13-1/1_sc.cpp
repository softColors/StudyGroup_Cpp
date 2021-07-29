
//=============================================================================
// FILE NAME  : Chapter13/13-1/1_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/23/2021 : Create.
//=============================================================================
#include <iostream>
#include <cstring>
using namespace std;

template <class T>

void SwapData(T &x1, T &x2)
{
    T tmp= x1;
    x1 = x2;
    x2 = tmp;
}

class Point
{
private:
    int xpos, ypos;
public:
    Point (int x=0, int y=0) : xpos(x), ypos(y)
    {}
    void ShowPosition() const
    {
        cout<<"["<<xpos<<","<<ypos<<']'<<endl;
    }
};

int main()
{
    Point x1(1,3);
    Point x2(7,9);

    SwapData(x1,x2);
    x1.ShowPosition();
    x2.ShowPosition();

}