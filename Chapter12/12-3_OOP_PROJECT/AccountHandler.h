
//=============================================================================
// FILE NAME  : Chapte12/12_3_OOP_PROJECT/AccountHandler.h
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/22/2021 : Create.
//=============================================================================
#ifndef __ACCOUNTHANDLER__H__
#define __ACCOUNTHANDLER__H__
#include"Account.h"
#include"AccountArray.h"

#define MAX_ACCOUNT_NUM 100

class AccountHandler
{
private:
    int current_accNum = 0;
    BoundCheckPointPtrArray Acc;
public:
    AccountHandler();
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