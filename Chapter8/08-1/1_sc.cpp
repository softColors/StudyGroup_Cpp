
//=============================================================================
// FILE NAME  : Chapter7/07-1/1_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/05/2021 : Create.
//=============================================================================
#include<iostream>
#include<cstring>
using namespace std;

class Car
{
private :  
	int gasolineGauge;
public : 
	Car (int gasoline) : gasolineGauge(gasoline) {}
	int GetGasGauge()
	{
		return gasolineGauge;
	}
};


class Hybridcar : public Car
{
private :  
	int electricGague;
public : 
	Hybridcar (int gasoline, int electricGague) 
		: Car(gasoline),electricGague(electricGague) {}
	
	int GetElecGauge()
	{
		return electricGague;
	}
};


class HybridWatercar : public Hybridcar
{
private :  
	int waterGauge;
public : 

	HybridWatercar(int gasoline, int electricm, int water) 
		:Hybridcar(gasoline,electricm),waterGauge(water) {}

	void ShowCurrentGauge()
	{
		cout<<"residual gasoline :"<<GetGasGauge()<<endl;
		cout<<"residual electric :"<<GetElecGauge()<<endl;
		cout<<"residual water    :"<<waterGauge<<endl;
	}
};



int main(void) 
{

	HybridWatercar watercar1(100,200,300);
		
	watercar1.ShowCurrentGauge();
	return 0;
}