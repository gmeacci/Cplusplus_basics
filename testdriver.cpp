#include <cassert>
#include "mystring.h"
#include <iostream>


int main()
{

//test < operator , 3 different versions
	
MyString s1("abc");

MyString s2("cde");

MyString s3("fgH");


assert("a"<s1);

assert(s1<"d");

assert(s2<s3);

//test > operator , 3 different vers
assert(s3>"fff");

assert("cde">s1);

assert(s2>s1);

assert(s3>s2);

//test == operator , 3 diff versions
assert("abc"==s1);

assert(s3=="fgH");

assert(s1==s1);

//terst != op

assert("John"!=s2);

assert(s2!="John");

assert(s1!=s3);

//test <= operator

assert("a"<=s1);
assert("abc"<=s1);
assert("abc">=s1);
assert(s2>=s1);
assert(s1<=s3);



//test op+=() and op+()
MyString sp(" ");
MyString period(".");
MyString str;

str+= "This" + sp + "should" + sp
+= "work" + sp + "without"
+= sp + "any" + sp + "memory"
+= sp + "leak" 
+= period;

cout << str << endl; 
return 0;
}

