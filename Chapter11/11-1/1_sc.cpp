
//=============================================================================
// FILE NAME  : Chapter11/11-1/1_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/16/2021 : Create.
//=============================================================================
#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;    	// ������ �Ѿ��� ��
public:
	Gun(int bnum) : bullet(bnum)
	{ }
	void Shut()
	{
		cout<<"BBANG!"<<endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;    // ������ ������ ��
	Gun * pistol;     // �����ϰ� �ִ� ����
public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff)
	{
		if(bnum>0)
			pistol=new Gun(bnum);
		else
			pistol=NULL;
	}
	Police(Police &ref)
		: handcuffs(ref.handcuffs)
	{
		if(ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));
		else
			pistol = NULL;
	}
	void PutHandcuff() 
	{
		cout<<"SNAP!"<<endl;
		handcuffs--;
	}
	void Shut()
	{
		if(pistol==NULL)
			cout<<"Hut BBANG!"<<endl;
		else
			pistol->Shut();
	}
	Police &operator=(Police &ref)
	{
		handcuffs = ref.handcuffs;
		if(ref.pistol != NULL)
			pistol =new Gun( *(ref.pistol));
		else
			pistol = NULL;
		return *this;
	}
	~Police()
	{
		if(pistol!=NULL)
			delete pistol;
	}
};

int main(void)
{
	Police pman1(10, 3);
	Police pman2= pman1;

	pman2.Shut();
	pman2.PutHandcuff();

	Police pman3(2, 4);
	pman3 = pman1;
	pman3.Shut();
	pman3.PutHandcuff();
	return 0;
}