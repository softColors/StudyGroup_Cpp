
//=============================================================================
// FILE NAME  : Chapte11/11_4_OOP_PROJECT/Account.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/18/2021 : Create.
//=============================================================================
#include"Account.h"

using namespace std;

Account::Account(char *name,int id, int balance)
{
    this->name = new char[strlen(name)+1];
    strcpy(this->name,name);
    this->id = id;
    this->balance = balance;
}
Account::Account(const Account & ref) : id(ref.id),balance(ref.balance)
{
    name = new char [strlen(ref.name)+1];
    strcpy(name, ref.name);
}

Account& Account::operator=(const Account & ref) 
{
    id = ref.id;
    balance = ref.balance;
    delete []name; 
    name = new char [strlen(ref.name)+1];
    strcpy(name, ref.name);
    return *this;
}
Account::~Account()
{
    delete []name; 
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
void Account::ShowAccoutInfo(void) const
{
    cout<<"ID: "<< id<<endl;
    cout<<"name: "<< name<<endl;
    cout<<"Account: "<< balance<<endl;
}