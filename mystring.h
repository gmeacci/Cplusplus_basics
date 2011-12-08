#ifndef __MYSTRING_H__
#define __MYSTRING_H__

using namespace std;

#include <iostream>

class MyString {

    public:

	// default constructor
	MyString();

	// constructor
	MyString(const char* p);

	// destructor
	~MyString();

	// copy constructor 
	MyString(const MyString& s);

	// assignment operator
	MyString& operator=(const MyString& s);

	//+= operator

	MyString& operator+=(const MyString& r);


	// returns the length of the string
	int length() const { return len; }
	
	// operator+
	friend MyString operator+(const MyString& s1, const MyString& s2);

	// put-to operator
	friend ostream& operator<<(ostream& os, const MyString& s);

	// get-from operator
	friend istream& operator>>(istream& is, MyString& s);

	// < operator


	friend int operator<(const MyString& l,const MyString& r); 

	// >operator
	friend int operator>(const MyString& l,const MyString& r); 



        // ==operator
	
	friend int operator==(const MyString& l,const MyString& r);
	
	
	// !=operator
	friend int operator!=(const MyString& l,const MyString& r);



	// <=operator 
	
	
	friend int operator<=(const MyString& l,const MyString& r); 

	// >=operator


	friend int operator>=(const MyString& l,const MyString& r); 
	

	// operator[]
	char& operator[](int i);

	// operator[] const
	const char& operator[](int i) const;

    private:

	char* data;

	int len;
};

#endif
