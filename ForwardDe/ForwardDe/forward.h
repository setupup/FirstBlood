#include <iostream>
using namespace std;

class B;             // 这是前置声明(Forward declaration)

class A
{
private:
	B* b;
public:
	A(B* b) :b(b)
	{
	}

	void someMethod();

};
class B
{
private:
public:
	void someMethod()
	{
		cout << "something happened..." << endl;
	}
};
