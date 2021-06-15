#include "Set.h"
#include "Set.cpp"
#include "MyDataType.h"

template class Set<char, MyComparator<char>>;
template class Set<double, MyComparator<char>>;
template class Set<int, MyComparator<int>>;
template class Set<MyDataType, MyComparator<MyDataType>>;
