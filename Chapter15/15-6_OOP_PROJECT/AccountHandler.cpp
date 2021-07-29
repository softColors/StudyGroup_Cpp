
//=============================================================================
// FILE NAME  : Chapte15/15_6_OOP_PROJECT/AccountArray.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/29/2021 : Create.
//=============================================================================
#include "Account.h"
#include "AccountHandler.h"
#include "NomalAccount.h"
#include "HighCreditAccount.h"
#include "BankingCommonDec1.h"


using namespace std;

AccountHandler::AccountHandler() : current_accNum(0)
{}


AccountHandler::~AccountHandler()
{
    for(int i=0;i<current_accNum;i++)
        delete Acc[i];
}

void AccountHandler::printInfo(void) 
{
    cout<<"-----Menu-----"<<endl;
    cout<<OPEN<<". Open Account"<<endl;
    cout<<DEPOSIT<<". Deposit"<<endl;
    cout<<WITHDRAW<<". Withdraw"<<endl;
    cout<<INQUIRY<<". Print all of the Account Info"<<endl;
    cout<<END<<". Close"<<endl;
}

int AccountHandler::customerChoice(void)
{
    int select; 
    cout<<"Choice: "; cin>>select;
    return select;
}

void AccountHandler::OpenAccount_NomalAcc(void)
{
    int id;
    String name;
    int balance;
    int interest_rate;

    cout<<"[Open Nomal Account]"<<endl;
    cout<<"Account ID   : "; cin>>id;
    cout<<"Name         : "; cin>>name;
    cout<<"Deposit money: "; cin>>balance;
    cout<<"interest rate: "; cin>>interest_rate;

    Acc[current_accNum] = new NomalAccount(name,id,balance,interest_rate);
}

void AccountHandler::OpenAccount_NomalHighCredit(void)
{
    int id;
    String name;
    int balance;
    int interest_rate;
    int credit_type;
    cout<<"[Open High Credit Account]"<<endl;
    cout<<"Account ID   : "; cin>>id;
    cout<<"Name         : "; cin>>name;
    cout<<"Deposit money: "; cin>>balance;
    cout<<"interest rate: "; cin>>interest_rate;
    cout<<"Credit Type[1toA, 2toB, 3toC]: "; cin>>credit_type;
    switch (credit_type)
    {
    case 1:
        Acc[current_accNum] = new HighCreditAccount(name,id,balance,interest_rate,CREDIT_TYPE::TYPE_A);
        break;
    case 2:
        Acc[current_accNum] = new HighCreditAccount(name,id,balance,interest_rate,CREDIT_TYPE::TYPE_B);
        break;

    case 3:
        Acc[current_accNum] = new HighCreditAccount(name,id,balance,interest_rate,CREDIT_TYPE::TYPE_C);
        break;        
    default:
        cout<<"[ERROR] Wrong Credit Type"<<endl;
        break;
    }
}

void AccountHandler::OpenAccount(int type)
{   
    switch (type)
    {
    case NOMAL_ACC:
        OpenAccount_NomalAcc();
        current_accNum++;
        break;

    case HIGH_CREDIT_ACC:
        OpenAccount_NomalHighCredit();
        current_accNum++;
        break;        

    default:
        cout<<"[ERROR] WRONG Num "<<endl;
        break;
    }
}

int AccountHandler::SearchAccountID(int account_id)
{
    for(int i = 0;i<current_accNum;i++)
    {
        if(Acc[i]->ResponceID() == account_id) return i;
    }
    return FAIL;

}

void AccountHandler::DepositAccount(void)
{
    int id;
    int deposit_money;
    int account_num;
    
    cout<<"[Deposit]"<<endl;

    cout<<"Account ID: "; cin>>id;
    account_num = SearchAccountID(id);  // Check the Account ID
    if(account_num ==FAIL ){cout<<"Wrong ID"<<endl;return;}
   
    while(1)
    {
        cout<<"Deposit money: "; cin>>deposit_money;
        try
        {
            if(deposit_money<=0) throw MinusException(deposit_money);
            Acc[account_num]->Deposit(deposit_money);
            cout<<"Success Deposit.."<<endl;
            return;
        }
        catch(MinusException &deposit_err)
        {
            deposit_err.ShowException();
            cout<<"Please reenter deposit money"<<endl;
        }
    }
}

void AccountHandler::WithdrawAccount(void)
{
    int id;
    int withdraw_money;
    int account_num;
    int balance;
    cout<<"[Withdraw]"<<endl;
    cout<<"Account ID: "; cin>>id;
    account_num = SearchAccountID(id);     // Check the Account ID
    if(account_num ==FAIL ){cout<<"[ERROR] Wrong ID..!"<<endl;return;}


    while(1)
    {

        try
        {
            cout<<"Withdraw money: "; cin>>withdraw_money;
            // check the minus
            if(withdraw_money<=0) throw  MinusException(withdraw_money);
            balance = Acc[account_num]->Withdraw(withdraw_money);
            // check the effectiveness
            if(balance == FAIL)
                throw  ExcessBalance(Acc[account_num]->BalanceInquiry(),withdraw_money);
            else
                cout<<"Success withdraw.."<<endl;
            return;
        }
        catch(MinusException &withdraw_minuserr)
        {
            withdraw_minuserr.ShowException();
            cout<<"Please reenter withdraw money"<<endl;
        }
        catch(ExcessBalance &withdraw_exesserr)
        {
            withdraw_exesserr.ShowException();
            cout<<"Please reenter withdraw money"<<endl;
        }

    }

    



}


void AccountHandler::InquiryAccount(void)
{
    int id;
    int deposit_money;
    int num=0;

    for(int i=0;i<current_accNum;i++)
    {
        cout<<"---------------------------------"<<endl;
        Acc[i]->ShowAccoutInfo();
    }
}

void AccountHandler::CloseProgram(void)
{
    for(int i=0;i<current_accNum;i++)
    {
        delete Acc[i];
    }
}