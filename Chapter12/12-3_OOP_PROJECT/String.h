
//=============================================================================
// FILE NAME  : Chapte12/12_3_OOP_PROJECT/String.h
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/22/2021 : Create.
//=============================================================================
#ifndef __STRING__H__
#define __STRING__H__
#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
	int len;
	char * str;
public:
	String();
	String(const char * s);
	String(const String& s);
	~String();
	String& operator= (const String& s);
	String& operator+= (const String& s);
	bool operator== (const String& s);
	String operator+ (const String& s);

	friend ostream& operator<< (ostream& os, const String& s);
	friend istream& operator>> (istream& is, String& s);
};

#endif