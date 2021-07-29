
//=============================================================================
// FILE NAME  : Chapte15/15_6_OOP_PROJECT/BankingSystemMain.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/29/2021 : Create.
//=============================================================================

#include "AccountHandler.h"
#include "BankingCommonDec1.h"

int main(void)
{
    int select;
    AccountHandler Handler;

    while(1)
    {
        Handler.printInfo();
        select = Handler.customerChoice();
        switch(select)
        {
            case OPEN: 
                cout<<"[Choose Account Type]"<<endl;
                cout<<NOMAL_ACC<<". Nomal Account"<<endl;
                cout<<HIGH_CREDIT_ACC<<". High Credit Account"<<endl;
                Handler.OpenAccount(Handler.customerChoice());
            break;
            case DEPOSIT: 
                 Handler.DepositAccount();
            break;            
            case WITHDRAW: 
                 Handler.WithdrawAccount();
            break;
            case INQUIRY: 
                 Handler.InquiryAccount();
            break;            
            case END: 
                Handler.CloseProgram();
                cout<<"End!";
                return 0;
            
        }
    }
}
