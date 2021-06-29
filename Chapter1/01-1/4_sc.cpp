
//=============================================================================
// FILE NAME  : Chapter1/01-1/4_scn.cpp
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

    while(1)
    {
        std::cout<<"판매 금액을 만원단위로 입력(-1 to end): ";
        std::cin>>num;
        if(num == -1) break;

        std::cout<<"이번달 급여:"<<50+num*0.12<<std::endl;
    }
    std::cout<<"프로그램을 종료합니다. "<<std::endl;

    return 0;    
}