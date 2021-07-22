
//=============================================================================
// FILE NAME  : Chapte12/12_3_OOP_PROJECT/AccountArray.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/22/2021 : Create.
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
    cout<<"Deposit money: "; cin>>deposit_money;

    account_num = SearchAccountID(id);
    if(account_num ==FAIL ){cout<<"Wrong ID"<<endl;return;}

    Acc[account_num]->Deposit(deposit_money);
    cout<<"Success Deposit.."<<endl;


}

void AccountHandler::WithdrawAccount(void)
{
    int id;
    int withdraw_money;
    int account_num;
    int balance;
    cout<<"[Withdraw]"<<endl;
    cout<<"Account ID: "; cin>>id;
    cout<<"Withdraw money: "; cin>>withdraw_money;

    account_num = SearchAccountID(id);
    if(account_num ==FAIL ){cout<<"[ERROR] Wrong ID..!"<<endl;return;}

    balance = Acc[account_num]->Withdraw(withdraw_money);
    if(balance == FAIL)
        cout<<"[ERROR]: Overdraw"<<endl;
    else
        cout<<"Success withdraw.."<<endl;
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