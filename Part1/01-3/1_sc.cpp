
//=============================================================================
// FILE NAME  : Part1/01-3/1_dan.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   06/26/2021 : Create.
//=============================================================================
#include<iostream>

/*
// ---------------- default Vaule example--------------------------------------
int BoxVolume(int length, int width=1, int height=1);

int main(void)
{
    std::cout<<"[3, 3, 3] : "<<BoxVolume(3,3,3)<<std::endl;
    std::cout<<"[5, 5, D] : "<<BoxVolume(5,5)<<std::endl;
    std::cout<<"[7, D, D] : "<<BoxVolume(7)<<std::endl;
    // std::cout<<"[D, D, D] : "<<BoxVolume()<<std::endl; //Error
}


int BoxVolume(int length, int width, int height)
{
    return length*width*height;
}
//=============================================================================
*/


int BoxVolume(int length, int width, int height)
{
    return length*width*height;
}
int BoxVolume(int length, int width)
{
    return length*width*1;
}
int BoxVolume(int length)
{
    return length*1*1;
}

int main(void)
{
    std::cout<<"[3, 3, 3] : "<<BoxVolume(3,3,3)<<std::endl;
    std::cout<<"[5, 5, D] : "<<BoxVolume(5,5)<<std::endl;
    std::cout<<"[7, D, D] : "<<BoxVolume(7)<<std::endl;
    // std::cout<<"[D, D, D] : "<<BoxVolume()<<std::endl; //Error
}
