#pragma once
#include "Cats.h"

namespace all_dogs {
	class Dogs
	{
	public:
		Dogs();
		virtual ~Dogs();

	protected:
		const char * bark;
		const char * color;
		virtual bool chaseCat(all_cats::Cats cat);
	private:

	};


	//a quick example of the diamond inheritance problem.  
	class Poodle :public Dogs {
	public:
		Poodle();
		virtual ~Poodle();
	protected:
		bool chaseCat(all_cats::Cats cat);
	};

	class Labrador :public Dogs {
		Labrador();
		virtual ~Labrador();
	};

	class Labradoodle : public Poodle, public Labrador {
		Labradoodle();
		~Labradoodle();
	};

}

