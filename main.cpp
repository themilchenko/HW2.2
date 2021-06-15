#include <algorithm>
#include <iostream>
#include <set>

#include "MyTemplate.cpp"
#include "Set.h"

template <class T>
void print(T a)
{
	std::cout << a << ' ';
}

int main()
{
	std::set<int> ss = { 1,2,4,5,6,7,8 };
	ss.erase(ss.begin(), ++ss.begin());
	std::for_each(ss.begin(), ss.end(), print<int>);

	Set<int, MyComparator<int>> set_test;
	set_test.insert(45);
	set_test.insert(35);
	set_test.insert(100);
	set_test.insert(55);
	for (int i : set_test)
		std::cout << i << ' ';
	
	std::cout << std::endl;


	Set<int> mySet;
	mySet.insert(45);
	mySet.insert(35);
	mySet.insert(100);
	mySet.insert(55);

	for (int i : mySet)
		std::cout << i << ' ';

	std::cout << std::endl;



	Set<int> otherSet;
	for (int i = 0; i < 5; i++)
		mySet.insert(i);
	for (size_t i = 0; i < 12; i++)
		otherSet.insert(std::rand() % 200);
	for (const int& i : mySet)
		std::cout << i << ' ';

	std::cout << std::endl;

	/*==============Iterator==============*/
	std::cout << "WORK OF ITERATOR AND CONST_ITERATOR:\n";

	for (ConstIterator<int> it = mySet.cbegin(); it != mySet.cend(); ++it)
		std::cout << *it << ' ';

	std::cout << std::endl;

	for (Iterator<int> it = mySet.begin(); it != mySet.end(); ++it)
	{
		*it = *it + 1;
		std::cout << *it << ' ';
	}

	/*==============ReverseIterator==============*/
	std::cout << "\nWORK OF REVERSE_ITERATOR AND REVERSE_CONST_ITERATOR:\n";
	for (ConstReverseIterator<int> it = mySet.crbegin(); it != mySet.crend(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
	for (ReverseIterator<int> it = mySet.rbegin(); it != mySet.rend(); ++it)
	{
		*it = *it + 1;
		std::cout << *it << ' ';
	}

	/*==============Erase==============*/
	std::cout << std::endl;

	for (const auto& i : mySet)
		std::cout << i << ' ';
	std::cout << std::endl;

	mySet.erase(5);

	for (const int& i : mySet)
		std::cout << i << ' ';
	std::cout << std::endl;

	mySet.erase(mySet.begin());
	mySet.erase(mySet.begin());

	for (const int& i : mySet)
		std::cout << i << ' ';
	std::cout << std::endl;

	for (size_t i = 0; i < 10; ++i)
		mySet.insert(std::rand() % 100);

	for (const int& i : mySet)
		std::cout << i << ' ';
	std::cout << std::endl;

	mySet.erase(mySet.begin(), ++mySet.begin());

	for (const int& i : mySet)
		std::cout << i << ' ';
	std::cout << std::endl;

	/*==============Swap==============*/
	std::cout << "DEMONSTRATING OF FUNCTION 'SWAP':\n";

	std::cout << "mySet: ";
	for (const int& i : mySet)
		std::cout << i << ' ';
	std::cout << std::endl << "Size of mySet: " << mySet.size();

	std::cout << "\notherSet: ";
	for (const int& i : otherSet)
		std::cout << i << ' ';
	std::cout << std::endl << "Size of mySet: " << otherSet.size() << std::endl << std::endl;


	mySet.swap(otherSet);

	std::cout << "mySet: ";
	for (const int& i : mySet)
		std::cout << i << ' ';
	std::cout << std::endl << "Size of mySet: " << mySet.size();

	std::cout << "\notherSet: ";
	for (const int& i : otherSet)
		std::cout << i << ' ';
	std::cout << std::endl << "Size of mySet: " << otherSet.size() << std::endl;

	/*==============Extract==============*/
	std::cout << "DEMONSTRATING OF FUNCTION 'EXTRACT':\n";

    int ex_it = mySet.extract(mySet.begin());
	int ex_elem = mySet.extract(*(mySet.begin()));

	mySet.find(91);

	Set<int> set1;
	set1.insert(1);
	set1.insert(2);
	set1.insert(3);
	for (auto i : set1)
		std::cout << i << ' ';
	std::cout << std::endl;

	Set<int> set2;
	set2.insert(5);
	set2.insert(4);
	set2.insert(3);
	for (auto i : set2)
		std::cout << i << ' ';
	std::cout << std::endl;

	set1.merge(set2);

	for (auto i : set1)
		std::cout << i << ' ';
	std::cout << std::endl;
	for (auto i : set2)
		std::cout << i << ' ';
	std::cout << std::endl;

	Set<MyDataType> user_set;
	user_set.insert(MyDataType("Ivan", 19, "Chess"));
	user_set.insert(MyDataType("Vasya", 25, "Cars"));
	user_set.insert(MyDataType("Ilya", 15, "Hockey"));
	user_set.insert(MyDataType("Maria", 30, "Skateboarding"));

	std::for_each(user_set.begin(), user_set.end(), print<MyDataType>);

	return 0;
}
