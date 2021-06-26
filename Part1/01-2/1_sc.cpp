
//=============================================================================
// FILE NAME  : Part1/01-2/1_dan.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   06/26/2021 : Create.
//=============================================================================
#include<iostream>

void swap(int *num1,int *num2)
{
    int swap_num;
    swap_num = *num1;
    *num1 = *num2;
    *num2 = swap_num;
}

void swap(char *ch1,char *ch2)
{
    char swap_ch;
    swap_ch = *ch1;
    *ch1 = *ch2;
    *ch2 = swap_ch;
}

void swap(double *dbl1,double *dbl2)
{
    double swap_dbl;
    swap_dbl = *dbl1;
    *dbl1 = *dbl2;
    *dbl2 = swap_dbl;
}

int main(void)
{
    int num1=20,num2=30;
    swap(&num1,&num2);
    std::cout<<num1<<' '<<num2<<std::endl;

    char ch1='A',ch2='Z';
    swap(&ch1,&ch2);
    std::cout<<ch1<<' '<<ch2<<std::endl;

    double dbl1=1.111,dbl2=2.2222;
    swap(&dbl1,&dbl2);
    std::cout<<dbl1<<' '<<dbl2<<std::endl;
    return 0;    
}