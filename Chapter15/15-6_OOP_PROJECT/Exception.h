
//=============================================================================
// FILE NAME  : Chapte15/15_6_OOP_PROJECT/Exception.h
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/29/2021 : Create.
//=============================================================================
#ifndef __Exception__H__
#define __Exception__H__
#include <iostream>
using namespace std;

class MinusException
{
private : 
    int minus_num;
public :
    MinusException(int val) : minus_num(val) {}
    void ShowException() 
    {
        cout << "Wrong Deposit or Withdraw money inputed : "<<minus_num<<endl;
    }
};

class ExcessBalance
{
private : 
    int balance;
    int withdraw_money;
public :
    ExcessBalance(int balance, int withdraw_money) 
        : balance(balance), withdraw_money(withdraw_money) {}
    void ShowException() 
    {
        cout << "Overdrawing..! "<<endl;
        cout << "Your Balance : "<<balance<<endl;
    }
};


#endif