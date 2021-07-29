
//=============================================================================
// FILE NAME  : Chapte13/13_3_OOP_PROJECT/BoundCheckArray.h
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/24/2021 : Create.
//=============================================================================
#ifndef __BOUNDCHECKARRAY__H__
#define __BOUNDCHECKARRAY__H__
#include"Account.h"


template <typename T>
class BoundCheckArray 
{
private:
	T * arr;
	int arrlen;

	BoundCheckArray(const BoundCheckArray& arr) { }
	BoundCheckArray& operator=(const BoundCheckArray& arr) { return *this; }

public:
	BoundCheckArray(int len=100);
	T& operator[] (int idx);
	T operator[] (int idx) const ;
	int GetArrLen() const ;
	~BoundCheckArray();

};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len) :arrlen(len)
{
    arr=new T[len];
}

template <typename T>
T& BoundCheckArray<T>::operator[] (int idx)
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array index out of bound exception"<<endl;
        exit(1);
    }
    return arr[idx];
}

template <typename T>
T BoundCheckArray<T>::operator[] (int idx) const 
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array index out of bound exception"<<endl;
        exit(1);
    }
    
    return arr[idx];
}
template <typename T>
int BoundCheckArray<T>::GetArrLen() const 
{
    return arrlen;
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray()
{
    delete []arr;
}
#endif