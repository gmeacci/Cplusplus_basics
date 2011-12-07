
John Terzis
jt2514
lab 9



Part1a:

BASIC4TRACE: (0x7fff226c3770)->MyString(const char *)
expression: MyString s1("one); variable: s1

BASIC4TRACE: (0x7fff226c3760)->MyString(const char *)
expression: MyString s2("two"); variable: s2

BASIC4TRACE: (0x7fff226c3730)->MyString(const MyString&)
expression: MyString s3 = add(s1,s2); variable: s1

BASIC4TRACE: (0x7fff226c3740)->MyString(const MyString&)
expression: MyString s3 = add(s1,s2); variable: s2

BASIC4TRACE: (0x7fff226c36f0)->MyString(const char *)
expression: MyString temp(" and "); variable: temp

BASIC4TRACE: op+(const MyString&, const MyString&)
expression: return s1 + temp + s2; variable: plus operator called on s1 and temp variable,which returns a new MyString variable by value

BASIC4TRACE: (0x7fff226c3690)->MyString()
expression: return s1 + temp + s2; variable: temp created within operator+ function call as a function scope stack variable and default constructor called.

BASIC4TRACE: (0x7fff226c36e0)->MyString(const MyString&)
expression: return s1 + temp + s2; variable: temp returned by value within operator+ function which means copy constructor must be called to create copy

BASIC4TRACE: (0x7fff226c3690)->~MyString()
expression: return s1 + temp + s2; variable: temp out of scope after operator+ returns so default destructor called to do garbage collection!

BASIC4TRACE: op+(const MyString&, const MyString&)
expression: return s1 + temp + s2; variable: operator+(s1+temp, s2) called

BASIC4TRACE: (0x7fff226c3690)->MyString()
expression: return s1 + temp + s2; variable: temp variable created within operator+ function call as a function scope stack variable and default constructor called. 

BASIC4TRACE: (0x7fff226c36d0)->MyString(const MyString&)
expression: return s1 + temp + s2; variable: temp returned by value which means copy constructor must be called.

BASIC4TRACE: (0x7fff226c3690)->~MyString()
expression: return s1 + temp + s2; variable: temp out of scope after operator+ returns so default destructor called to do garbage collection.

BASIC4TRACE: (0x7fff226c3720)->MyString(const MyString&)
expression: return s1 + temp + s2; variable: s1+temp+s2 returned by value from add function so copy constructor called to facilitate copy.

BASIC4TRACE: (0x7fff226c36d0)->~MyString()
expresion: return s1 + temp + s2; variable: temp copy is out of scope after add returns so default destructor called to do garbage collection.

BASIC4TRACE: (0x7fff226c36e0)->~MyString()
expresion: return s1 + temp + s2; variable: temp copy is out of scope after add returns so default destructor called to do garbage collection.

BASIC4TRACE: (0x7fff226c36f0)->~MyString()
expresion: MyString temp(" and "); variable: temp stack variable created within add function is out of scope after add returns so default destructor called to do garbage collection.

BASIC4TRACE: (0x7fff226c3750)->MyString(const MyString&)
expression: MyString s3 = add(s1,s2); variable: s3 . copy constructor called to copy returned value from add(s1,s2) into new stack variable declared as MyString s3.

BASIC4TRACE: (0x7fff226c3720)->~MyString()
expression: MyString s3=add(s1,s2); variable: s1+temp+s2, was returned by value thus copied. copy constructor calls constructor so default constructor called when s1+temp+s2 went out of scope which occured after it was returned.
BASIC4TRACE: (0x7fff226c3740)->~MyString()
expression: MyString s3 = add(s1,s2); variable: s2 , destructor called when copied version of s2 went out of scope after add returned
BASIC4TRACE: (0x7fff226c3730)->~MyString()
expression: MyString s3 = add(s1,s2); variable: s1 , destructor called when copied version of s1 went out of scope after add returned
one and two
expression: cout << s3 << endl; variable: s3
BASIC4TRACE: (0x7fff226c3750)->~MyString()
expression: MyString s3 = add(s1,s2); variable: s3
BASIC4TRACE: (0x7fff226c3760)->~MyString()
expression: MyString s2("two"); variable: s2
BASIC4TRACE: (0x7fff226c3770)->~MyString()
expression: MyString s1("one"); variable: s1




Part 1b:

BASIC4TRACE: (0x7fffb339ded0)->MyString(const char *)
BASIC4TRACE: (0x7fffb339dec0)->MyString(const char *)
BASIC4TRACE: (0x7fffb339de70)->MyString(const char *)
BASIC4TRACE: op+(const MyString&, const MyString&)
BASIC4TRACE: (0x7fffb339de10)->MyString()
BASIC4TRACE: (0x7fffb339de60)->MyString(const MyString&)
BASIC4TRACE: (0x7fffb339de10)->~MyString()
BASIC4TRACE: op+(const MyString&, const MyString&)
BASIC4TRACE: (0x7fffb339de10)->MyString()
BASIC4TRACE: (0x7fffb339de50)->MyString(const MyString&)
BASIC4TRACE: (0x7fffb339de10)->~MyString()
BASIC4TRACE: (0x7fffb339dea0)->MyString(const MyString&)
BASIC4TRACE: (0x7fffb339de50)->~MyString()
BASIC4TRACE: (0x7fffb339de60)->~MyString()
BASIC4TRACE: (0x7fffb339de70)->~MyString()
BASIC4TRACE: (0x7fffb339deb0)->MyString(const MyString&)
BASIC4TRACE: (0x7fffb339dea0)->~MyString()
BASIC4TRACE: (0x7fffb339deb0)->~MyString()
BASIC4TRACE: (0x7fffb339dec0)->~MyString()
BASIC4TRACE: (0x7fffb339ded0)->~MyString()

By passing s1 and s2 into add() by reference, we are eliminating 4 calls to basic4 functions, specifically, we do not need lines 3 and 4 from the original BASIC4TRACE output and the we do not need the associated 2 calls to the destructor later on.  We do not pass s1 and s2 by copy meaning we do not create new stack variables to represent them when calling add(s1,s2) and we also do not need to call destructors on s1 and s2 to clean up. By passing them in as const, we are implicitly ensuring that we will not alter the parameters within the function since we now have the power to do so given we are passing synonyms for the original variables into the function. 


Part 1c
-fno-elide-constructors specification causes the compiler to not omit constructors in
ambiguous situations where different options are available. For instance, if
you are declaring and initializing a variable to the return value of a function foo() then
by including this specification, the compiler (1) initializes the variable by calling the appropriate constructor for its type (2) assigns the return value of foo to a temporary variable (3) replaces the initial value of the variable in (1) with the temporary.  

Omit -fno-elide-constructors from Makefile

BASIC4TRACE: (0x7fff660dd010)->MyString(const char *)
BASIC4TRACE: (0x7fff660dd000)->MyString(const char *)
BASIC4TRACE: (0x7fff660dcfc0)->MyString(const char *)
BASIC4TRACE: op+(const MyString&, const MyString&)
BASIC4TRACE: (0x7fff660dcfb0)->MyString()
BASIC4TRACE: op+(const MyString&, const MyString&)
BASIC4TRACE: (0x7fff660dcff0)->MyString()
BASIC4TRACE: (0x7fff660dcfb0)->~MyString()
BASIC4TRACE: (0x7fff660dcfc0)->~MyString()
BASIC4TRACE: (0x7fff660dcff0)->~MyString()
BASIC4TRACE: (0x7fff660dd000)->~MyString()
BASIC4TRACE: (0x7fff660dd010)->~MyString()

Four copy constructor calls and four resulting destructor calls were excluded when omitting 
this specification from Makefile. Specifically, the two copy constructors from the two calls to operator+ were ommitted, the copy constructor from the return value of add() was ommitted, and the copy constructor from the copy of the return value of add into s3 were ommited.
This should work without any memory leak.





Part 2 VALGRIND TESTING

==6782== Memcheck, a memory error detector
==6782== Copyright (C) 2002-2009, and GNU GPL'd, by Julian Seward et al.
==6782== Using Valgrind-3.6.0.SVN-Debian and LibVEX; rerun with -h for copyright info
==6782== Command: ./mytest
==6782== 
BASIC4TRACE: (0x7ff000970)->MyString(const char *)
BASIC4TRACE: (0x7ff000960)->MyString(const char *)
BASIC4TRACE: (0x7ff000950)->MyString(const char *)
BASIC4TRACE: (0x7ff000940)->MyString(const char *)
BASIC4TRACE: (0x7ff000940)->~MyString()
BASIC4TRACE: (0x7ff000930)->MyString(const char *)
BASIC4TRACE: (0x7ff000930)->~MyString()
BASIC4TRACE: (0x7ff000920)->MyString(const char *)
BASIC4TRACE: (0x7ff000920)->~MyString()
BASIC4TRACE: (0x7ff000910)->MyString(const char *)
BASIC4TRACE: (0x7ff000910)->~MyString()
BASIC4TRACE: (0x7ff000900)->MyString(const char *)
BASIC4TRACE: (0x7ff000900)->~MyString()
BASIC4TRACE: (0x7ff0008f0)->MyString(const char *)
BASIC4TRACE: (0x7ff0008f0)->~MyString()
BASIC4TRACE: (0x7ff0008e0)->MyString(const char *)
BASIC4TRACE: (0x7ff0008e0)->~MyString()
BASIC4TRACE: (0x7ff0008d0)->MyString(const char *)
BASIC4TRACE: (0x7ff0008d0)->~MyString()
BASIC4TRACE: (0x7ff0008c0)->MyString(const char *)
BASIC4TRACE: (0x7ff0008c0)->~MyString()
BASIC4TRACE: (0x7ff0008b0)->MyString(const char *)
BASIC4TRACE: (0x7ff0008b0)->~MyString()
BASIC4TRACE: (0x7ff0008a0)->MyString(const char *)
BASIC4TRACE: (0x7ff0008a0)->~MyString()
BASIC4TRACE: (0x7ff000890)->MyString(const char *)
BASIC4TRACE: (0x7ff000880)->MyString(const char *)
BASIC4TRACE: (0x7ff000870)->MyString()
BASIC4TRACE: (0x7ff000780)->MyString(const char *)
BASIC4TRACE: op+(const MyString&, const MyString&)
BASIC4TRACE: (0x7ff000770)->MyString()
BASIC4TRACE: (0x7ff000770)->op=(const MyString&)
BASIC4TRACE: (0x7ff0007a0)->MyString(const char *)
BASIC4TRACE: (0x7ff0007d0)->MyString(const char *)
BASIC4TRACE: op+(const MyString&, const MyString&)
BASIC4TRACE: (0x7ff0007c0)->MyString()
BASIC4TRACE: (0x7ff0007c0)->op=(const MyString&)
BASIC4TRACE: op+(const MyString&, const MyString&)
BASIC4TRACE: (0x7ff0007b0)->MyString()
BASIC4TRACE: (0x7ff0007b0)->op=(const MyString&)
BASIC4TRACE: op+(const MyString&, const MyString&)
BASIC4TRACE: (0x7ff000790)->MyString()
BASIC4TRACE: (0x7ff000790)->op=(const MyString&)
BASIC4TRACE: (0x7ff0007f0)->MyString(const char *)
BASIC4TRACE: (0x7ff000810)->MyString(const char *)
BASIC4TRACE: op+(const MyString&, const MyString&)
BASIC4TRACE: (0x7ff000800)->MyString()
BASIC4TRACE: (0x7ff000800)->op=(const MyString&)
BASIC4TRACE: op+(const MyString&, const MyString&)
BASIC4TRACE: (0x7ff0007e0)->MyString()
BASIC4TRACE: (0x7ff0007e0)->op=(const MyString&)
BASIC4TRACE: (0x7ff000840)->MyString(const char *)
BASIC4TRACE: (0x7ff000860)->MyString(const char *)
BASIC4TRACE: op+(const MyString&, const MyString&)
BASIC4TRACE: (0x7ff000850)->MyString()
BASIC4TRACE: (0x7ff000850)->op=(const MyString&)
BASIC4TRACE: op+(const MyString&, const MyString&)
BASIC4TRACE: (0x7ff000830)->MyString()
BASIC4TRACE: (0x7ff000830)->op=(const MyString&)
BASIC4TRACE: op+(const MyString&, const MyString&)
BASIC4TRACE: (0x7ff000820)->MyString()
BASIC4TRACE: (0x7ff000820)->op=(const MyString&)
BASIC4TRACE: (0x7ff000870)->op=(const MyString&)
BASIC4TRACE: (0x7ff000820)->~MyString()
BASIC4TRACE: (0x7ff000830)->~MyString()
BASIC4TRACE: (0x7ff000850)->~MyString()
BASIC4TRACE: (0x7ff000860)->~MyString()
BASIC4TRACE: (0x7ff000840)->~MyString()
BASIC4TRACE: (0x7ff0007e0)->~MyString()
BASIC4TRACE: (0x7ff000800)->~MyString()
BASIC4TRACE: (0x7ff000810)->~MyString()
BASIC4TRACE: (0x7ff0007f0)->~MyString()
BASIC4TRACE: (0x7ff000790)->~MyString()
BASIC4TRACE: (0x7ff0007b0)->~MyString()
BASIC4TRACE: (0x7ff0007c0)->~MyString()
BASIC4TRACE: (0x7ff0007d0)->~MyString()
BASIC4TRACE: (0x7ff0007a0)->~MyString()
BASIC4TRACE: (0x7ff000770)->~MyString()
BASIC4TRACE: (0x7ff000780)->~MyString()
BASIC4TRACE: (0x7ff000870)->~MyString()
BASIC4TRACE: (0x7ff000880)->~MyString()
BASIC4TRACE: (0x7ff000890)->~MyString()
BASIC4TRACE: (0x7ff000950)->~MyString()
BASIC4TRACE: (0x7ff000960)->~MyString()
BASIC4TRACE: (0x7ff000970)->~MyString()
==6782== 
==6782== HEAP SUMMARY:
==6782==     in use at exit: 0 bytes in 0 blocks
==6782==   total heap usage: 69 allocs, 69 frees, 467 bytes allocated
==6782== 
==6782== All heap blocks were freed -- no leaks are possible
==6782== 
==6782== For counts of detected and suppressed errors, rerun with: -v
==6782== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 4 from 4)
