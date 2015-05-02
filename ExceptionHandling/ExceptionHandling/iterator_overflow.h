#include<exception>
using namespace std;
class iterator_overflow :public exception{
public:
	iterator_overflow(int index, int max) :_index(index), _max(max)
	{}
	int index(){ return _index; }
	int max(){ return _max; }

	//override
	const char* what() const;
private:
	int _index;
	int _max;
};