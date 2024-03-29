/*
DISCLAIMER
This is a series of stupid C++isms that are designed to show the basics of coding in C++
None of this code is actually meant to do anything.  

My recommendation is to start from this file and read all the way through main.
*/

//How we include things from linked files.  C and C++ standard libraries are automatically linked.  
//These are resolved at Compile time, so these statements do NOT link the files.  THey only say that we are plannig on using them.
//Because foo is in the same project (thus the same directory), we do not need to explicitly link it.
//But if we are trying to link to functionality from different projects (say something in a static or dynamic library, we need to link)
#include "pch.h"
#include <iostream>
#include "foo.h"

//define the same function inside rwo namespaces
//Prove that scope works!!!
namespace std { //std is the generic C++ namespce.  Among other things, it includes cout.  And String, Vector... Lots of stuff
	namespace foo0 {//This is a random namespace I declare.  It is in std, so it can use all of stds stuff without putting std:: in front of everything
		void bar() {
			cout << "namespace foo" << endl;
		}
	}
	namespace foo1 {
		void bar() {
			cout << "namespace foo1" << endl;
		}
	}
}

#define _FRED true

#ifndef byte
	#define byte unsigned char
#endif // !byte

//function predeclarations.  These need to be here, unless I define these functions up above^
//This is part of c++'s static typing.  We need to declare EVERYTHING before it is used.
//That and C++ does not construct its function tables before compilation, so if we don't at least say a function exists
//before we try to use it, then the compiler doesn't know where the function could possibly be.
void increment(int *p);
void increment(int &p);


//All C++ program execution starts from a main program.  There can only be a single main per project (unlike Java)
int main()
{
	//Hello World :)
	//This does a few things.  We are creating a string stream and sending it to cout, from the std namespace
	//Because this is a console application, cout is specifically a command line console.  
	//But cout can be specified when you compile your project.  
    std::cout << "Hello World!\n"<<std::endl; 

	//namespaces
	//Think of namespaces like packages in Java.  They 
	std::foo0::bar();
	std::foo1::bar();
	//we don't want to type out std::foo all the time, so...
	namespace te = std::foo0; 
	te::bar();

	byte t = 3;
	if (_FRED)
		std::cout << "calling function is: " << __FUNCTION__ <<"\t"<<t<< std::endl;
	int k = 0;

	//pass by value (traditional C)
	increment(&k);
	std::cout << k << std::endl;

	//pass by reference (C++)
	increment(k);
	std::cout << k << std::endl;

	//create a static foo object
	test::foo staticf = test::foo();
	//To access, simply use the . operator
	std::cout << staticf.theTruth << std::endl;

	//create dynamic foo and bar objects to test them out
	//Remeber, if you use new, malloc, or calloc, YOU are responsible to call delete or free
	test::foo * f = new test::foo();
	test::bar * b = new test::bar();

	//To access member of these instances, use the -> operator
	std::cout << f->theTruth << "\t\t"  << std::endl;//Note that b's theTruth is inaccessible.
													 //Why? because it is only ever inheritted.  Never explicitly stated to be public in b

	//play with the template functions
	auto typed = b->doStuff(42); //this should return an int
	auto typeb = b->doStuff('c'); // this should return a char
	std::cout << typeid(typed).name() << "\t" << typed << std::endl;
	std::cout << typeid(typeb).name() << "\t" << typeb << std::endl;

	//Now to mess with our template class
	test::random<char> * r = new test::random<char>('c');
	r->print();

	//Then detroy them
	std::cout << "We are reponsibly freeing up the heap space we stole for foo and bar." << std::endl;
	if (f)delete f;
	if (b)delete b;
	if (r)delete r;
	

	std::cout << "ENDING EXECUtION" << std::endl;
	
}


//function declarations
void increment(int * p) //we take in a pointer to p
{
	(*p)++;
}

void increment(int & p)//we take the reference to p
{
	p++;
}
