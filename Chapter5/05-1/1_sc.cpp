
//=============================================================================
// FILE NAME  : Chapter5/05-1/1_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/02/2021 : Create.
//=============================================================================
#include<iostream>
#include<cstring>
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
	NameCard(const NameCard &copy ) 
	{
		name = new char [strlen(copy.name)+1];
		workplace = new char [strlen(copy.workplace)+1];
		phone_num = new char [strlen(copy.phone_num)+1];
		position = copy.position;

		strcpy(const_cast<char*>(name),copy.name); //removal  const "const_cast<char*>(const char name)"
		strcpy(const_cast<char*>(workplace),copy.workplace);
		strcpy(const_cast<char*>(phone_num),copy.phone_num);

	}
	void ShowNameCardInfo() const
	{
		cout<<"name : "<<name<<endl;
		cout<<"workplace : "<<workplace<<endl;
		cout<<"phone number : "<<phone_num<<endl;
		cout<<"position : ";COMP_POS::Printname(position);
		cout<<endl<<endl;
	}
	~NameCard()
	{
		delete []name;
		delete []workplace;
		delete []phone_num;
		cout << "free~~~dom~~~"<<endl;
	}
};

int main(void) 
{

	NameCard manClerk("Lee","ABCEng","010-1111-2222",COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR("Hong","OrangeEng","010-3333-4444",COMP_POS::SENIOR);
	NameCard copy2 =manSENIOR;

	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}