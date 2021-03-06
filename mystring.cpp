#include <cstring>
#include <cstdio>

#include "mystring.h"

// default constructor

MyString::MyString() 
{
#ifdef BASIC4TRACE
    fprintf(stderr, "BASIC4TRACE: (%p)->MyString()\n", this);
#endif

    data = new char[1];
    data[0] = '\0';
    
    len = 0;
}

// constructor

MyString::MyString(const char* p)
{
#ifdef BASIC4TRACE
    fprintf(stderr, "BASIC4TRACE: (%p)->MyString(const char *)\n", this);
#endif

    if (p) {
	len = strlen(p);
	data = new char[len+1];
	strcpy(data, p);
    } else {
	data = new char[1];
	data[0] = '\0';
	len = 0;
    }
}

// destructor

MyString::~MyString() 
{
#ifdef BASIC4TRACE
    fprintf(stderr, "BASIC4TRACE: (%p)->~MyString()\n", this);
#endif

    delete[] data;
}

// copy constructor 

MyString::MyString(const MyString& s) 
{
#ifdef BASIC4TRACE
    fprintf(stderr, "BASIC4TRACE: (%p)->MyString(const MyString&)\n", this);
#endif

    len = s.len;
    
    data = new char[len+1];
    strcpy(data, s.data);
}

// assignment operator

MyString& MyString::operator=(const MyString& rhs)
{
#ifdef BASIC4TRACE
    fprintf(stderr, "BASIC4TRACE: (%p)->op=(const MyString&)\n", this);
#endif

    if (this == &rhs) {
	return *this;
    }

    // first, deallocate memory that 'this' used to hold

    delete[] data;

    // now copy from rhs
    
    len = rhs.len;

    data = new char[len+1];
    strcpy(data, rhs.data);

    return *this;
}

// operator+

MyString operator+(const MyString& s1, const MyString& s2)
{
#ifdef BASIC4TRACE
    fprintf(stderr, 
	    "BASIC4TRACE: op+(const MyString&, const MyString&)\n");
#endif


    	MyString temp; //create MyString stack variable with default constructor. Default destr will be called after return.

	temp+=s1; temp+=s2;   //call += twice

    return temp;       //return temp by copy since we want + operator to yield an lvalue in practice 
}

// put-to operator

ostream& operator<<(ostream& os, const MyString& s)
{
    os << s.data;
    return os;
}

// get-from operator

istream& operator>>(istream& is, MyString& s)
{
    // this is kinda cheating, but this is just to illustrate how this
    // function can work.
    
    string temp;
    is >> temp;

    delete[] s.data;

    s.len = strlen(temp.c_str());
    s.data = new char[s.len+1];
    strcpy(s.data, temp.c_str());

    return is;
}

// operator[] - in real life this function should be declared inline

char& MyString::operator[](int i) 
{
    return data[i];
}

// operator[] const - in real life this should be inline

const char& MyString::operator[](int i) const
{
    // illustration of casting away constness
    return ((MyString&)*this)[i];
}

/*
*/

/*
*/

//operator< not a member function of MyString so do not use scope operator on name
int operator<(const MyString& l,const MyString& r) 
{
//comparison should be lexicographical
//convert l to MyString temporarily

//compare lexicographically for the longest string
if(l.len > r.len)
{
	for(int i=0; i<l.len; i++)
	{	
		if(l[i]<r[i])
		return 1;   //lhs IS less than rhs
		
		else if(l[i]>r[i])
		return 0;  //lhs IS greater than rhs
		//otherwise keep iterating if elements of two strings are equal
	}
}

else if(r.len >= l.len)
{
	for(int i=0; i<r.len; i++)
	{
		if(l[i]<r[i])
		return 1;   //lhs IS less than rhs
	
		else if(l[i]>r[i])
		return 0;  //lhs IS greater than rhs

		//otherwise keep iterating if elements of two strings are equal
	}
}
//if all elements are the same , return false ,0
return 0;
}



/*
*/

/*
*/

//operator< not a member function of MyString so do not use scope operator on name
int operator>(const MyString& l,const MyString& r) 
{
//comparison should be lexicographical
//convert l to MyString temporarily

//compare lexicographically for the longest string
if(l.len > r.len)
{
	for(int i=0; i<l.len; i++)
	{	
		if(l[i]>r[i])
		return 1;   //lhs IS less than rhs
		
		else if(l[i]<r[i])
		return 0;  //lhs IS greater than rhs
		//otherwise keep iterating if elements of two strings are equal
	}
}

else if(r.len >= l.len)
{
	for(int i=0; i<r.len; i++)
	{
		if(l[i]>r[i])
		return 1;   //lhs IS less than rhs
	
		else if(l[i]<r[i])
		return 0;  //lhs IS greater than rhs

		//otherwise keep iterating if elements of two strings are equal
	}
}
//if all elements are the same , return false ,0
return 0;
}
/*
*/

/*
*/

//operator ==
int operator==(const MyString& l,const MyString& r)
{

	if(l.len!=r.len) return 0;   //length is different, strings cant be equal

	for(int i=0; i<l.len; i++)
	{
		if(l[i]!=r[i])return 0;
	}

return 1; //strings are equal if they are same size and all characters are equal individually
}

/*
*/

/*
*/

//operator !=
int operator!=(const MyString& l,const MyString& r)
{

	int a=0;
	if(l.len!=r.len) return 1;   //length is different, strings cant be equal
	
	for(int i=0; i<l.len; i++)
	{
		if(l[i]==r[i])a++;
	}
if(a==l.len) return 0;

return 1; //strings are equal if they are same size and all characters are equal individually
}

/*
*/

/*
*/

//operator< not a member function of MyString so do not use scope operator on name
int operator<=(const MyString& l,const MyString& r) 
{
//comparison should be lexicographical
//convert l to MyString temporarily

//compare lexicographically for the longest string
if(l.len > r.len)
{
	for(int i=0; i<l.len; i++)
	{	
		if(l[i]<r[i])
		return 1;   //lhs IS less than rhs
		
		else if(l[i]>r[i])
		return 0;  //lhs IS greater than rhs
		//otherwise keep iterating if elements of two strings are equal
	}
}

else if(r.len >= l.len)
{
	for(int i=0; i<r.len; i++)
	{
		if(l[i]<r[i])
		return 1;   //lhs IS less than rhs
	
		else if(l[i]>r[i])
		return 0;  //lhs IS greater than rhs

		//otherwise keep iterating if elements of two strings are equal
	}
}
//if all elements are the same , return false ,0
return 1;
}



/*
*/


/*
*/


//operator< not a member function of MyString so do not use scope operator on name
int operator>=(const MyString& l,const MyString& r) 
{
//comparison should be lexicographical
//convert l to MyString temporarily

//compare lexicographically for the longest string
if(l.len > r.len)
{
	for(int i=0; i<l.len; i++)
	{	
		if(l[i]>r[i])
		return 1;   //lhs IS less than rhs
		
		else if(l[i]<r[i])
		return 0;  //lhs IS greater than rhs
		//otherwise keep iterating if elements of two strings are equal
	}
}

else if(r.len >= l.len)
{
	for(int i=0; i<r.len; i++)
	{
		if(l[i]>r[i])
		return 1;   //lhs IS less than rhs
	
		else if(l[i]<r[i])
		return 0;  //lhs IS greater than rhs

		//otherwise keep iterating if elements of two strings are equal
	}
}
//if all elements are the same , return false ,0
return 1;
}



MyString& MyString::operator+=(const MyString& r)
{

	if(len==0)
	{*this=r; return *this;}
	
	else
	{
	char* temp = new char[strlen(data)+1];   //store existing data from lhs in temp var
	strcpy(temp,data);

	delete[] data;   //make data large enough to hold concatenated string by erasing lhs data
	int clen= strlen(temp) + strlen(r.data);
	data = new char[clen+1]; //recreate data via empty heap allocation of proper no. bytes
	strcpy(data,temp); 	//first copy temp into data since data contains garbage values (uninitialized)
				//strcat assumes data is large enoguh memory block to fit concatenated string
	strcat(data,r.data);
	len=strlen(data);

	delete[] temp;

	return *this;
	}
}
