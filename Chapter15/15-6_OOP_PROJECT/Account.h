
//=============================================================================
// FILE NAME  : Chapte15/15_6_OOP_PROJECT/Account.h
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/29/2021 : Create.
//=============================================================================
#ifndef __ACCOUNT__H__
#define __ACCOUNT__H__

#include<iostream>
#include<cstring>
#include"String.h"
// -----------------------global-----------------------------------------------
#define FAIL -1
// ============================================================================

class Account
{
private:
    String name;
    int id;
    int balance;

public:

    Account(String name,int id, int balance);
    Account(const Account & ref);
    Account& operator=(const Account & ref);

    virtual ~Account();
    int ResponceID(void) const;
    virtual void Deposit(int deposit_money);
    int Withdraw(int withdraw_money);
    int BalanceInquiry(void);

    void ShowAccoutInfo(void) const;
    
};

#endif