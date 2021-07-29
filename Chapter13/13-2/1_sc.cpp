
//=============================================================================
// FILE NAME  : Chapter13/13-2/1_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/24/2021 : Create.
//=============================================================================
#include <iostream>
#include <cstring>
using namespace std;



class Point
{
private:
    int xpos, ypos;
public:
    Point (int x=0, int y=0) : xpos(x), ypos(y) {}
    void SetPos(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    void ShowPosition() const
    {
        cout<<"["<<xpos<<","<<ypos<<']'<<endl;
    }
};


template <typename T>
class SmartPtr
{
private:
    T * posptr;
public:
    SmartPtr(T *ptr): posptr(ptr){}
    //SmarPtr(T ptr): posptr(ptr){}

    T & operator*() const {return *posptr;}
    T * operator->() const {return posptr;}
    ~SmartPtr() {delete posptr;}
};


int main()
{
    SmartPtr<Point> sptr1(new Point(1,2));
    SmartPtr<Point> sptr2(new Point(3,4));

    sptr1->ShowPosition();
    sptr2->ShowPosition();

    
    sptr1->SetPos(10,20);
    sptr2->SetPos(30,40);
    
    sptr1->ShowPosition();
    sptr2->ShowPosition();

    return 0;
}