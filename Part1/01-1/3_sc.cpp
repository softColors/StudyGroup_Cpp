
//=============================================================================
// FILE NAME  : Part1/01-1/3_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   06/26/2021 : Create.
//=============================================================================


#include<iostream>

int main(void)
{
    int num,i;
    std::cout<<"숫자를 입력하시오 : ";
    std::cin>>num;

    for(i=1;i<10;i++)
        std::cout<<num<<" * "<<i<<" = "<<num*i<<std::endl;

    return 0;    
}