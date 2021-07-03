
//=============================================================================
// FILE NAME  : Chapter6/06-4_OOP_PROJECT/OOP_project.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/03/2021 : Create.
//=============================================================================
#include<iostream>
#include<cstring>
using namespace std;

// -----------------------global-----------------------------------------------
#define MAX_ACCOUNT_NUM 100
#define MAX_NAME_LEN 30
#define FAIL -1

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
// -----------------------global-----------------------------------------------

Account *Acc[MAX_ACCOUNT_NUM];
// ============================================================================

namespace FUNCTION
{
    static int current_accNum = 0;
    enum{OPEN=1, DEPOSIT, WITHDRAW, INQUIRY, END};

    void printInfo(void) 
    {
        cout<<"-----Menu-----"<<endl;
        cout<<OPEN<<". 계좌개설"<<endl;
        cout<<DEPOSIT<<". 입 금"<<endl;
        cout<<WITHDRAW<<". 출 금"<<endl;
        cout<<INQUIRY<<". 계좌정보 전체 출력"<<endl;
        cout<<END<<". 프로그램 종료"<<endl;
    }

    int customerChoice(void)
    {
        int select; 
        cout<<"선택: "; cin>>select;
        return select;
    }

    void OpenAccount(void)
    {   
        int id;
        char name[MAX_NAME_LEN];
        int balance;
        cout<<"[계좌개설]"<<endl;
        cout<<"계좌ID: "; cin>>id;
        cout<<"이름  : "; cin>>name;
        cout<<"입금액: "; cin>>balance;
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
        cout<<"[입  금]"<<endl;
        cout<<"계좌ID: "; cin>>id;
        cout<<"입금액: "; cin>>deposit_money;

        account_num = SearchAccountID(id);
        if(account_num ==FAIL ){cout<<"Wrong ID"<<endl;return;}

        Acc[account_num]->Deposit(deposit_money);
        cout<<"입금완료"<<endl;


    }

    void WithdrawAccount(void)
    {
        int id;
        int withdraw_money;
        int account_num;
        int balance;
        cout<<"[출  금]"<<endl;
        cout<<"계좌ID: "; cin>>id;
        cout<<"출금액: "; cin>>withdraw_money;

        account_num = SearchAccountID(id);
        if(account_num ==FAIL ){cout<<"[ERROR] Wrong ID..!"<<endl;return;}

        balance = Acc[account_num]->Withdraw(withdraw_money);
        if(balance == FAIL)
            cout<<"출금실패: 잔액부족"<<endl;
        else
            cout<<"출금완료"<<endl;
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
}

int main(void)
{
    int select;

    while(1)
    {
        FUNCTION::printInfo();
        select = FUNCTION::customerChoice();
        switch(select)
        {
            case FUNCTION::OPEN: 
                FUNCTION::OpenAccount();
            break;
            case FUNCTION::DEPOSIT: 
                FUNCTION::DepositAccount();
            break;            
            case FUNCTION::WITHDRAW: 
                FUNCTION::WithdrawAccount();
            break;
            case FUNCTION::INQUIRY: 
                FUNCTION::InquiryAccount();
            break;            
            case FUNCTION::END: 
                FUNCTION::CloseProgram();
                cout<<"End!";
            return 0;
        }
    }
}
