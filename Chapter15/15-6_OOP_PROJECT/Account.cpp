
//=============================================================================
// FILE NAME  : Chapte15/15_6_OOP_PROJECT/Account.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/29/2021 : Create.
//=============================================================================
#include"Account.h"

using namespace std;

Account::Account(String name,int id, int balance)
{
    this->name = name;
    this->id = id;
    this->balance = balance;
}
Account::Account(const Account & ref) : id(ref.id),balance(ref.balance)
{
    name = ref.name;
}

Account& Account::operator=(const Account & ref) 
{
    id = ref.id;
    balance = ref.balance;
    // delete []name; 
    name = ref.name;
    return *this;
}
Account::~Account()
{
    // delete []name; 
}

int Account::ResponceID(void) const {  return id;   } 

void Account::Deposit(int deposit_money)
{
    balance += deposit_money;
}

int Account::Withdraw(int withdraw_money)
{
    if(balance < withdraw_money) return FAIL;
    
    balance -= withdraw_money;
    return balance;
}

int Account::BalanceInquiry(void)
{
    return balance;
}
void Account::ShowAccoutInfo(void) const
{
    cout<<"ID: "<< id<<endl;
    cout<<"name: "<< name<<endl;
    cout<<"Account: "<< balance<<endl;
}