
//=============================================================================
// FILE NAME  : Chapte12/12_3_OOP_PROJECT/AccountArray.h
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/22/2021 : Create.
//=============================================================================
#ifndef __ACCOUNTARRAY__H__
#define __ACCOUNTARRAY__H__
#include"Account.h"

typedef Account * ACCOUNT_PTR;

class BoundCheckPointPtrArray 
{
private:
	ACCOUNT_PTR * arr;
	int arrlen;

	BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) { }
	BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr) { return *this; }

public:
	BoundCheckPointPtrArray(int len=100);
	ACCOUNT_PTR& operator[] (int idx);
	ACCOUNT_PTR operator[] (int idx) const ;
	int GetArrLen() const ;
	~BoundCheckPointPtrArray();

};


#endif