
//=============================================================================
// FILE NAME  : Chapter7/07-1/2_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/05/2021 : Create.
//=============================================================================
#include<iostream>
#include<cstring>
using namespace std;

class MyFriendInfo
{
private :  
	char * name;
	int age;
public : 
	MyFriendInfo(const char * name, int age)
	{
		strcpy(this->name, name);
		this->age = age;

	}
	~MyFriendInfo()
	{
		delete []name;
		cout<<"parent closed"<<endl;

	}
	void ShowMyFriendInfo()
	{
		cout<<"name :"<<name<<endl;
		cout<<"age  :"<<age<<endl;
	}
};


class MyFriendDetailInfo : public MyFriendInfo
{
private :  
	char * addr;
	char * phone;
public : 
	MyFriendDetailInfo(const char * name, int age,const char *addr, const char *phone) 
		: MyFriendInfo(name,age)
	{
		this->addr = new char [strlen(addr)+1];
		this->phone = new char [strlen(phone)+1];

		strcpy(this->addr, addr);
		strcpy(this->phone, phone);

	}
	~MyFriendDetailInfo()
	{
		delete []addr;
		delete []phone;
		cout<<"chiled closed"<<endl;
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout<<"address :"<<addr<<endl;
		cout<<"phone   :"<<phone<<endl;
	}
};


int main(void) 
{

	MyFriendDetailInfo friend1("Jung",27,"Hell","010-1234-4567");
		
	friend1.ShowMyFriendDetailInfo();
	return 0;
}