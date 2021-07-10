
//=============================================================================
// FILE NAME  : Chapter9/09-3_OOP_PROJECT/AccountHandler.h
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/10/2021 : Create.
//=============================================================================
#ifndef __ACCOUNTHANDLER__H__
#define __ACCOUNTHANDLER__H__
#include"Account.h"

#define MAX_ACCOUNT_NUM 100

class AccountHandler
{
private:
    int current_accNum = 0;
    Account *Acc[MAX_ACCOUNT_NUM];
public:
    ~AccountHandler();
    void printInfo(void) ;
    int customerChoice(void);   
    void OpenAccount_NomalAcc(void);
    void OpenAccount_NomalHighCredit(void);
    void OpenAccount(int type);   
    int SearchAccountID(int account_id);
    void DepositAccount(void);
    void WithdrawAccount(void);
    void InquiryAccount(void);
    void CloseProgram(void);
   
};

#endif