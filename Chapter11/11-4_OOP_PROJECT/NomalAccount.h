
//=============================================================================
// FILE NAME  : Chapte11/11_4_OOP_PROJECT/NomalAccount.h
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/18/2021 : Create.
//=============================================================================
#ifndef __NOMALACCOUNT__H__
#define __NOMALACCOUNT__H__

#include "Account.h"

class NomalAccount : public Account
{
private:
    int interest ;

public:
    NomalAccount(char *name,int id, int balance,int value) 
       : Account(name,id,balance), interest(value)  {}

  
    virtual void Deposit(int deposit_money)
    {
        Account::Deposit(deposit_money);
        Account::Deposit((int)deposit_money*(interest/100.0));
    }

};
#endif