
//=============================================================================
// FILE NAME  : Part1/01-6/1_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   06/26/2021 : Create.
//=============================================================================
#include<iostream>
using namespace std;

// -----------------------global-----------------------------------------------
#define MAX_ACCOUNT_NUM 100

enum{OPEN=1, DEPOSIT, WITHDRAW, INQUIRY, END};

typedef struct 
{
    unsigned int id;
    char name[20];
    unsigned int balance;
}Account;

Account st_acc[MAX_ACCOUNT_NUM];

// ============================================================================
void printInfo(void)
{
    cout<<"-----Menu-----"<<endl;
    cout<<"1. 계좌개설"<<endl;
    cout<<"2. 입 금"<<endl;
    cout<<"3. 출 금"<<endl;
    cout<<"4. 계좌정보 전체 출력"<<endl;
    cout<<"5. 프로그램 종료"<<endl;
}

int customerChoice(void)
{
    int select; 
    cout<<"선택: "; cin>>select;
    return select;
}

void OpenAccount(void)
{
    static int i_acc_num = 0;
   
    cout<<"[계좌개설]"<<endl;
    cout<<"계좌ID: "; cin>>st_acc[i_acc_num].id;
    cout<<"이름  : "; cin>>st_acc[i_acc_num].name;
    cout<<"입금액: "; cin>>st_acc[i_acc_num].balance;
    i_acc_num++;
}


int SearchAccountID(int account_id)
{
    int account_num=0;

    while(account_num<MAX_ACCOUNT_NUM)
    {
        if(st_acc[account_num].id == account_id) break;
        account_num++;
    }

    return account_num;
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
    st_acc[account_num].balance +=deposit_money;
    cout<<"입금완료"<<endl;


}

void WithdrawAccount(void)
{
    int id;
    int withdraw_money;
    int account_num;
    cout<<"[출  금]"<<endl;
    cout<<"계좌ID: "; cin>>id;
    cout<<"출금액: "; cin>>withdraw_money;

    account_num = SearchAccountID(id);
    if(st_acc[account_num].balance < withdraw_money)
    {
        cout<<"출금실패: 잔액부족"<<endl;
    }
    else
    {
        st_acc[account_num].balance -=withdraw_money;
        cout<<"출금완료"<<endl;
    }
}


void InquiryAccount(void)
{
    int id;
    int deposit_money;
    int account_num=0;

    while(st_acc[account_num].id != 0)
    {
        cout<<"---------------------------------"<<endl;
        cout<<"계좌ID: "<< st_acc[account_num].id<<endl;
        cout<<"이름  : "<< st_acc[account_num].name<<endl;
        cout<<"잔액  : "<< st_acc[account_num].balance<<endl;

        account_num++;
    }
}


int main(void)
{
    int select;

    while(1)
    {
        printInfo();
        select = customerChoice();
        switch(select)
        {
            case OPEN: 
                OpenAccount();
            break;
            case DEPOSIT: 
                DepositAccount();
            break;            
            case WITHDRAW: 
                WithdrawAccount();
            break;
            case INQUIRY: 
                InquiryAccount();
            break;            
            case END: 
                cout<<"끝!";
            return 0;
        }

    }

}
