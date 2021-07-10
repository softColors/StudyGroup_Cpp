
//=============================================================================
// FILE NAME  : Chapter8/08-1/1_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/10/2021 : Create.
//=============================================================================
#include<iostream>
#include<cstring>
using namespace std;


namespace RISK_LEVEL
{
	enum{RISK_A=30,RISK_B=20,RISK_C=10};
}


class Employee
{
private : 
	char name[100];
public:
	Employee(char *name)
	{	strcpy(this->name,name);	}
	void ShowYourname() const {cout<<"name :"<<name<<endl;}
	virtual int GetPay() const =0;
	virtual void ShowSalaryInfo() const =0;
};

class PermanentWorker :public Employee
{
private:
	int salary;
public:
	PermanentWorker(char *name,int money)
		 : Employee (name),salary(money) {}
	
	int GetPay() const 	{  return salary ; }

	void ShowSalaryInfo() const
	{
 		 ShowYourname();
 		cout<<"salary: "<<GetPay() <<endl<<endl;
	}
};

class TemporaryWoker :public Employee
{
private:
	int worktime;
	int payPerHour;
public:
	TemporaryWoker (char *name, int pay) 
		: Employee (name),worktime(0), payPerHour(pay) {}

	void AddWorkTime(int time) { worktime+=time;}	

	int GetPay() const 	{  return worktime *payPerHour ; }

	void ShowSalaryInfo() const
	{
 		 ShowYourname();
 		cout<<"salary: "<<GetPay() <<endl<<endl;
	}
};

class SalesWorker :public PermanentWorker
{
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker (char *name, int money, double ratio) 
         : PermanentWorker(name,money), salesResult(0), bonusRatio(ratio) {}

	void AddSlaesResult(int value) {salesResult += value;}	

	int GetPay() const 	
        { return (PermanentWorker::GetPay() +  (int)(salesResult* bonusRatio)) ; }

	void ShowSalaryInfo() const
	{
 		 ShowYourname();
 		cout<<"salary: "<<GetPay() <<endl<<endl;
	}
};

class ForegnSalesWorker : public SalesWorker
{
private:

	int risk_type;
public:
	ForegnSalesWorker (char *name, int money, double ratio, int type) 
         : SalesWorker(name,money,ratio), risk_type(type) {}

	int RiskPay() const  	
    { 
		return (int)(SalesWorker::GetPay()*(risk_type/100.0));		
	}
	int GetPay() const 	
    { return SalesWorker::GetPay() + RiskPay() ; }

	void ShowSalaryInfo() const
	{
 		ShowYourname();
		cout<<"salary: "<<SalesWorker::GetPay() <<endl;
		cout<<"risk pay: "<<RiskPay()  <<endl;
 		cout<<"sum: "<<GetPay() <<endl<<endl;
	}
};

class EmployeeHandler
{
private:
	 Employee *empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) {}
	
	void AddEmployee( Employee * emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for(int i=0; i<empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i=0; i<empNum ; i++)
			sum += empList[i]->GetPay();
 		cout<<"salary sum: "<<sum<<endl;
	}
	~EmployeeHandler()
	{
		for(int i=0; i<empNum; i++)
			delete empList[i];	
	}
};

int main(void)
{
	EmployeeHandler handler;

	ForegnSalesWorker * fsleer1 = new ForegnSalesWorker("Hong",1000,0.1,RISK_LEVEL::RISK_A);
	fsleer1 -> AddSlaesResult(7000);
	handler.AddEmployee(fsleer1);


	ForegnSalesWorker * fsleer2 = new ForegnSalesWorker("Yoon",1000,0.1,RISK_LEVEL::RISK_B);
	fsleer2 -> AddSlaesResult(7000);
	handler.AddEmployee(fsleer2);

	ForegnSalesWorker * fsleer3 = new ForegnSalesWorker("Lee",1000,0.1,RISK_LEVEL::RISK_C);
	fsleer3 -> AddSlaesResult(7000);
	handler.AddEmployee(fsleer3);

	handler.ShowAllSalaryInfo();


	// handler.AddEmployee(new PermanentWorker("KIM",1000));
	// handler.AddEmployee(new PermanentWorker("LEE",1500));

	// TemporaryWoker * alba = new TemporaryWoker("Jung",700);
	// alba -> AddWorkTime(5);
	// handler.AddEmployee(alba);


	// SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
	// seller-> AddSlaesResult(7000);
	// handler.AddEmployee(seller);

	// handler.ShowAllSalaryInfo();
	// handler.ShowTotalSalary();

	return 0;
}

