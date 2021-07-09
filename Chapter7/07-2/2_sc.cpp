
//=============================================================================
// FILE NAME  : Chapter7/07-2/2_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/09/2021 : Create.
//=============================================================================
#include<iostream>
#include<cstring>
using namespace std;

class Book
{
private : 
	char *title;
	char *isbn; //book code
	int price;
public :
	Book(const char *title, const char *isbn, int price) : price(price) 
	{
		this->title = new char[strlen(title)+1];
		this->isbn = new char[strlen(isbn)+1];

		strcpy(this->title,title);
		strcpy(this->isbn,isbn);
	}
	~Book()
	{
		delete []title;
		delete []isbn;

	}
	void ShowBookInfo(void) const
	{
		cout << "Title : "<<title<<endl;
		cout << "ISBN  : "<<isbn<<endl;
		cout << "Price : "<<price<<endl;	
	}
};

class EBook : public Book
{
private : 
	char *drmkey;
public: 
	EBook(const char *title, const char *isbn, int price, const char *drmkey)
		:Book(title,isbn,price) 
	{
		this->drmkey = new char[strlen(drmkey)+1];
		strcpy(this->drmkey,drmkey);

	}
	~EBook()
	{
		delete []drmkey;
	}
	void ShowEBookInfo(void) const
	{
		ShowBookInfo();
		cout << "DRMKey: "<<drmkey<<endl;	
	}
};

int main(void)
{
	Book book("good c++","555-13245-890-0",20000);
	book.ShowBookInfo();
	cout<<endl;

	EBook ebook("good c++ ebook","555-13245-890-1",10000,"akdsjacihzux4657");
	ebook.ShowEBookInfo();
	return 0;
}