#pragma once
#include "Dogs.h"


namespace all_cats {

	class Cats
	{
		friend void printFullCat(Cats cat);
		//This is so that our Dogs can see everything about our Cats.  Because Dogs care about Cats. 
		//But Cats don't reciprocate. The Cats class is no friend to the Dogs class.  They only see a Dog.  They don't care about anything else.
		friend class all_dogs::Dogs;
		public:
			Cats();
			virtual ~Cats();
			virtual void printCat();

		protected:
			//some variadic declarations
			void allthefish(...);

			//variadic template function
			template <typename First, typename ...T>
			void anyFood(First f, T... allFood) {
				anyFood(f);
				anyFood(allFood...);
			}


			bool isEvil;
			const char * meow;
			const char * color;

		private:
			bool claws;

	};
	//A derived class.  When the keyword public is used, bigCat inherits all of Cats' public and protected members.  
	//A child class that does not specify public is weakly related, and does not explicitly inherit its parent's stuff.
	class bigCats : public Cats
	{
	//Note that friends are NOT inheritted.  So bigCats needs to befriend our function, too
	friend void printFullCat(Cats cat);
	public:
		bigCats();
		~bigCats();

	protected:
		virtual void printCat();

	};

	class lion : public bigCats
	{
	public:
		friend void printFullCat(Cats cat);
		lion();
		~lion();
	protected:
		void printCat();

	};
	class tiger : public bigCats
	{
	public:
		tiger();
		~tiger();
	protected:
		void printCat();

	};

	//This function demonstrates 2 things.  
	//	1.It is a friend function.  It can access Cats' protected and private memeber
	//	2.Polymorphism.  Any child Cats object may be passed in to it.
	void printFullCat(Cats cat);
}

