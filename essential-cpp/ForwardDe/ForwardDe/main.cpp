#include "forward.h"

int main(int argc, char** argv)
{
	B* b = new B();
	A* a = new A(b);

	a->someMethod();

	delete a;
	delete b;

	return 0;
}