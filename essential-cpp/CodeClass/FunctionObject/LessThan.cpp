#include"LessThan.h"
inline bool LessThan::
operator()(int value) const { return value < _val; }
