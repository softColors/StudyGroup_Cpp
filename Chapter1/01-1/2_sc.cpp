
//=============================================================================
// FILE NAME  : Part1/01-1/2_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   06/26/2021 : Create.
//=============================================================================


#include<iostream>

int main(void)
{
    char name[10];
    char phone[20];
    std::cout<<"이름을 입력하시오 : ";
    std::cin>>name;
    std::cout<<"번호를 입력하시오 : ";
    std::cin>>phone;

    std::cout<<"이름 : "<<name<<std::endl;
    std::cout<<"번호 : "<<phone<<std::endl;

    return 0;    
}