
//=============================================================================
// FILE NAME  : Chapter11/11-1/2_sc.cpp
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/17/2021 : Create.
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
	Book(const Book &ref) : price(ref.price) 
	{
		title = new char[strlen(ref.title)+1];
		isbn = new char[strlen(ref.isbn)+1];

		strcpy(title,ref.title);
		strcpy(isbn,ref.isbn);
	}

	Book& operator=(const Book &ref)
	{
		delete []title;
		delete []isbn;
		title = new char[strlen(ref.title)+1];
		isbn = new char[strlen(ref.isbn)+1];

		strcpy(title,ref.title);
		strcpy(isbn,ref.isbn);
		price = ref.price;
		return *this;
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

	EBook(const EBook &ref) : Book(ref)
	{
		drmkey = new char[strlen(ref.drmkey)+1];
		strcpy(drmkey,ref.drmkey);

	}


	EBook& operator=(const EBook &ref)
	{
		Book::operator=(ref);
		delete []drmkey;
		drmkey = new char[strlen(ref.drmkey)+1];
		strcpy(drmkey,ref.drmkey);
		return *this;
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
	Book book1("good c++","555-13245-890-0",20000);
	Book book2 = book1;
	book2.ShowBookInfo();
	cout<<endl;

	EBook ebook1("good c++ ebook","555-13245-890-1",10000,"akdsjacihzux4657");
	EBook ebook2 = ebook1;
	ebook2.ShowEBookInfo();
	return 0;
}