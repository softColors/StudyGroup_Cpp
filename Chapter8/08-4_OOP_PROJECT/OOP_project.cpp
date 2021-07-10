
//=============================================================================
// FILE NAME  : Chapter8/08-4_OOP_PROJECT/OOP_project.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/10/2021 : Create.
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
enum{NOMAL_ACC=1, HIGH_CREDIT_ACC =2};
namespace CREDIT_TYPE{ enum{TYPE_A=7, TYPE_B =4, TYPE_C = 2}; }

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
    virtual ~Account()
    {
        delete []name; 
    }

    int ResponceID(void) const {  return id;   } 

    virtual void Deposit(int deposit_money)
    {
        balance += deposit_money;
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


class NomalAccount : public Account
{
private:
    int interest ;

public:
    NomalAccount(char *name,int id, int balance,int value) 
       : Account(name,id,balance), interest(value)  {}

  
    virtual void Deposit(int deposit_money)
    {
        Account::Deposit(deposit_money);
        Account::Deposit((int)deposit_money*(interest/100.0));
    }

};

class HighCreditAccount : public NomalAccount
{
private:
    int credit_type;

public:
    HighCreditAccount(char *name,int id, int balance,int value,int type) 
       : NomalAccount(name,id,balance,value), credit_type(type)
       {}

    virtual void Deposit(int deposit_money)
    {
        NomalAccount::Deposit(deposit_money);
        NomalAccount::Deposit((int)deposit_money*(credit_type/100.0));
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

    void OpenAccount_NomalAcc(void)
    {
        int id;
        char name[MAX_NAME_LEN];
        int balance;
        int interest_rate;

        cout<<"[Open Nomal Account]"<<endl;
        cout<<"Account ID   : "; cin>>id;
        cout<<"Name         : "; cin>>name;
        cout<<"Deposit money: "; cin>>balance;
        cout<<"interest rate: "; cin>>interest_rate;

        Acc[current_accNum] = new NomalAccount(name,id,balance,interest_rate);
    }

    void OpenAccount_NomalHighCredit(void)
    {
        int id;
        char name[MAX_NAME_LEN];
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

    void OpenAccount(int type)
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
