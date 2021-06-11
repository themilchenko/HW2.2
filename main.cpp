#include <iostream>

#include "Set.h"
#include "MyTemplate.cpp"

int main()
{
	Set<int> mySet;
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
	for (ConstReverseIterator<int> it = mySet.crbegin() + 1; it != mySet.crend() + 1; ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
	for (ReverseIterator<int> it = mySet.rbegin() + 1; it != mySet.rend() + 1; ++it)
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
	mySet.erase(mySet.begin() + 1);

	for (const int& i : mySet)
		std::cout << i << ' ';
	std::cout << std::endl;

	for (size_t i = 0; i < 10; ++i)
		mySet.insert(std::rand() % 100);

	for (const int& i : mySet)
		std::cout << i << ' ';
	std::cout << std::endl;

	mySet.erase(mySet.begin() + 2, mySet.begin() + 6);

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
	std::cout << std::endl << "Size of mySet: " << otherSet.size();

	/*==============Extract==============*/
	std::cout << "DEMONSTRATING OF FUNCTION 'EXTRACT':\n";

    //Node<int> ex_it = mySet.extract(mySet.begin());
	//Node<int> ex_elem = mySet.extract(*(mySet.begin()));

	return 0;
}