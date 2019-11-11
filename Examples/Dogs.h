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

	class Pyrannese :public Dogs {
	public:
		Pyrannese();
		 ~Pyrannese();
	protected:
		bool chaseCat(all_cats::Cats cat);
	};

}

