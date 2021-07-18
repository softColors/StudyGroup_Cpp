
//=============================================================================
// FILE NAME  : Chapte11/11_4_OOP_PROJECT/Account.h
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/18/2021 : Create.
//=============================================================================
#ifndef __ACCOUNT__H__
#define __ACCOUNT__H__

#include<iostream>
#include<cstring>

// -----------------------global-----------------------------------------------
#define FAIL -1
// ============================================================================

class Account
{
private:
    char *name;
    int id;
    int balance;

public:

    Account(char *name,int id, int balance);
    Account(const Account & ref);
    Account& operator=(const Account & ref);

    virtual ~Account();
    int ResponceID(void) const;
    virtual void Deposit(int deposit_money);
    int Withdraw(int withdraw_money);
    void ShowAccoutInfo(void) const;
    
};

#endif