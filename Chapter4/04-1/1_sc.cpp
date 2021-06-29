
//=============================================================================
// FILE NAME  : Chapter4/04-1/1_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   06/29/2021 : Create.
//=============================================================================
#include<iostream>
using namespace std;

#define FAIL   -1

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money)
	{
   		int num = money / APPLE_PRICE;
        if(num <= 0) return 0; // U cant buy Apple..!
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult(void) const
	{
		cout << "Num of Apple: " << numOfApples << endl;
		cout << "Profit: " << myMoney << endl<< endl; 
	};
};

class FruitBuyer
{
	int myMoney;
	int numOfApples;

public:
	void InitMembers(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
        int Old_numOfApples;

        Old_numOfApples = numOfApples;
		numOfApples+=seller.SaleApples(money);
        if(Old_numOfApples != numOfApples) myMoney-=money;
	}
	void ShowBuyResult(void) const
	{
		cout << "Current Balance: " << myMoney << endl;
		cout << "Num of Apple: " << numOfApples << endl << endl;
	}
};

int main() {
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, -1000);
	buyer.BuyApples(seller, 800);

	cout << "[Fruit Seller]" << endl;
	seller.ShowSalesResult();
	cout << "[Fruit Buyer]" << endl;
	buyer.ShowBuyResult();

	return 0;
}