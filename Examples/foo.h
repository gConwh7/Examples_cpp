#pragma once
#include <iostream>
namespace test {
	//A classic C struct.  
	struct friended {
		int no_ones;
	};

	//A C++ class
	class foo
	{
	friend class friended;//Proves 2 things: 
						  //	1	C++ treats classes and structs the same way even if the compiler complains about it
						  //	2	Friend classes exist.  Friends can access private members.

	public: //Everyone can see me!
		foo();
		int theTruth = 42;
		virtual ~foo();

	protected: //only my children can see this!
		virtual void print(); //A virtual class.  Means the child can take this one over.

	private: //Only I can see this.  And my friends.  
		bool notTrue = true;

	};

	class bar : foo //bar is a child of foo
	{
	public:
		bar();
		~bar();

		//a template member function.  This MUST be defined in the .h file if part of a class
		//otherwise the caller can't deal with the template
		//Types are handled at compile time (so templates are NOT a run time thing)
		template <typename T>
		T doStuff(T n) {	
			return n;
		};


	protected:
		void print();
	private:
		bool sayitaintso = false;
	};

	//a template class
	//notice that our parent does NOT need to be a template.  
	//We still steal the print function anyways
	template <typename S>
	class random : foo {
	public:
		random(S test);
		~random();
		void print();
	private:
		S mine;
		
	};
	//The actual definitions for our class again need to be inline
	template<typename S>
	inline random<S>::random(S test)
	{
		mine = test;
		std::cout << "FROM test::random creating a random" << std::endl;
	}
	template<typename S>
	inline random<S>::~random()
	{
		std::cout << "FROM test::random detroying a random" << std::endl;
	}
	template<typename S>
	inline void random<S>::print()
	{
		std::cout <<"FROM foo::random::print "<<typeid(mine).name()<< mine << std::endl;
	}
}

