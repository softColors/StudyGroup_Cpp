
//=============================================================================
// FILE NAME  : Chapter7/07-5_OOP_PROJECT/OOP_project.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/09/2021 : Create.
//=============================================================================
#include<iostream>
#include<cstring>
using namespace std;

// -----------------------global-----------------------------------------------
#define MAX_ACCOUNT_NUM 100
#define MAX_NAME_LEN 30
#define FAIL -1
#define TRUE 1
#define FALSE 0

enum{OPEN=1, DEPOSIT, WITHDRAW, INQUIRY, END};

// ============================================================================

class Account
{
private:
    char *name;
    int id;
    int balance;

public:

    Account(char *name,int id, int balance)
    {
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
        this->id = id;
        this->balance = balance;
    }
    Account(const Account & ref) : id(ref.id),balance(ref.balance)
    {
        name = new char [strlen(ref.name)+1];
        strcpy(name, ref.name);
    }
    ~Account()
    {
        delete []name; 
    }

    int ResponceID(void) const {  return id;   } 

    int Deposit(int deposit_money)
    {
        balance += deposit_money;
        return balance;
    }

    int Withdraw(int withdraw_money)
    {
        if(balance < withdraw_money) return FAIL;
        
        balance -= withdraw_money;
        return balance;
    }
    void ShowAccoutInfo(void) const
    {
        cout<<"ID: "<< id<<endl;
        cout<<"name: "<< name<<endl;
        cout<<"Account: "<< balance<<endl;
    }

};


class AccountHandler
{
private:
    int current_accNum = 0;
    Account *Acc[MAX_ACCOUNT_NUM];
public:
    ~AccountHandler()
    {
        for(int i=0;i<current_accNum;i++)
            delete Acc[i];
    }
 
    void printInfo(void) 
    {
        cout<<"-----Menu-----"<<endl;
        cout<<OPEN<<". Open Account"<<endl;
        cout<<DEPOSIT<<". Deposit"<<endl;
        cout<<WITHDRAW<<". Withdraw"<<endl;
        cout<<INQUIRY<<". Print all of the Account Info"<<endl;
        cout<<END<<". Close"<<endl;
    }

    int customerChoice(void)
    {
        int select; 
        cout<<"Choice: "; cin>>select;
        return select;
    }

    void OpenAccount(void)
    {   
        int id;
        char name[MAX_NAME_LEN];
        int balance;
        cout<<"[Open Account]"<<endl;
        cout<<"Account ID   : "; cin>>id;
        cout<<"Name         : "; cin>>name;
        cout<<"Deposit money: "; cin>>balance;
        Acc[current_accNum] = new Account(name,id,balance);

        current_accNum++;
    }

    int SearchAccountID(int account_id)
    {
        for(int i = 0;i<current_accNum;i++)
        {
            if(Acc[i]->ResponceID() == account_id) return i;
        }
        return FAIL;

    }

    void DepositAccount(void)
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

    void WithdrawAccount(void)
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


    void InquiryAccount(void)
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

    void CloseProgram(void)
    {
        for(int i=0;i<current_accNum;i++)
        {
            delete Acc[i];
        }
    }
};

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
                 Handler.OpenAccount();
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
