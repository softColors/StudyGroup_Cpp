
//=============================================================================
// FILE NAME  : Chapte12/12_3_OOP_PROJECT/HighCreditAccount.h
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/22/2021 : Create.
//=============================================================================
#ifndef __HIGHCREDITACCOUNT__H__
#define __HIGHCREDITACCOUNT__H__
#include "NomalAccount.h" 

class HighCreditAccount : public NomalAccount
{
private:
    int credit_type;

public:
    HighCreditAccount(String name,int id, int balance,int value,int type) 
       : NomalAccount(name,id,balance,value), credit_type(type)
       {}

    virtual void Deposit(int deposit_money)
    {
        NomalAccount::Deposit(deposit_money);
        NomalAccount::Deposit((int)deposit_money*(credit_type/100.0));
    }
};


#endif