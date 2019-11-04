#include "pch.h"
#include "foo.h"
#include <iostream>

namespace test { //Our headers are in the test namespace, so this is necessary.
	foo::foo()
	{
		std::cout << "FROM test::foo constructing foo" << std::endl;
	}


	foo::~foo()
	{
		std::cout << "FROM test::foo destroying foo" << std::endl;
	}
	void foo::print()
	{
		std::cout << "FROM test::foo printing foo" << std::endl;
	}
}
	//for the heck of it, you can also define class functions in a namespace with this syntax:
	test::bar::bar()
	{
		std::cout << "FROM test::bar creating bar" << std::endl;
	}

	test::bar::~bar()
	{
		std::cout << "FROM test::bar destroying bar" << std::endl;
	}

	void test::bar::print()
	{
		std::cout << "FROM test::bar printing bar" << std::endl;
	}
