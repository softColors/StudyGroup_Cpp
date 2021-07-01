
//=============================================================================
// FILE NAME  : Chapter4/04-3/2_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/01/2021 : Create.
//=============================================================================
#include<iostream>
using namespace std;

namespace COMP_POS
{
	enum{CLERK, SENIOR, ASSIST, MANAGER};
	void Printname(int compos_num)
	{
		switch(compos_num)
		{
			case CLERK   : cout<<"CLERK"; break;
			case SENIOR  : cout<<"SENIOR"; break;
			case ASSIST  : cout<<"ASSIST"; break;
			case MANAGER : cout<<"MANAGER"; break;
			default      : cout<<"UNKMOWN"; break;
		}
	}

}


class NameCard
{
private:
	const char *name;
	const char *workplace;
	const char *phone_num;
	int   position;


public:
	NameCard(const char *nm,const char *wp,const char *pn,int ps)
	   : name(nm),workplace(wp),phone_num(pn),position(ps) {}
	void ShowNameCardInfo() const
	{
		cout<<"name : "<<name<<endl;
		cout<<"workplace : "<<workplace<<endl;
		cout<<"phone number : "<<phone_num<<endl;
		cout<<"position : ";COMP_POS::Printname(position);
		cout<<endl<<endl;
	}
};

int main(void) 
{

	NameCard manClerk("Lee","ABCEng","010-1111-2222",COMP_POS::CLERK);
	NameCard manSENIOR("Hong","OrangeEng","010-3333-4444",COMP_POS::SENIOR);
	NameCard manAssist("Kim","SoGoodComp","010-5555-6666",COMP_POS::ASSIST);

	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;
}