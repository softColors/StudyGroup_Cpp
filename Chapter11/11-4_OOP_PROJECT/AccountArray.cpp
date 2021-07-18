
//=============================================================================
// FILE NAME  : Chapte11/11_4_OOP_PROJECT/AccountHandler.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/18/2021 : Create.
//=============================================================================
#include "Account.h"
#include "AccountArray.h"

using namespace std;

BoundCheckPointPtrArray::BoundCheckPointPtrArray(int len) :arrlen(len)
{
    arr=new ACCOUNT_PTR[len];
}

ACCOUNT_PTR& BoundCheckPointPtrArray::operator[] (int idx)
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array index out of bound exception"<<endl;
        exit(1);
    }
    return arr[idx];
}


ACCOUNT_PTR BoundCheckPointPtrArray::operator[] (int idx) const 
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array index out of bound exception"<<endl;
        exit(1);
    }
    
    return arr[idx];
}

int BoundCheckPointPtrArray::GetArrLen() const 
{
    return arrlen;
}

BoundCheckPointPtrArray::~BoundCheckPointPtrArray()
{
    delete []arr;
}