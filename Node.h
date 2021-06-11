#pragma once

template <class T>
class Node
{
private:
	T element;
	bool is_empty;

public:
	Node() : is_empty(1) { };

	Node(const T& el) 
	{ 
		element = el;
		is_empty = 0;
	};

	Node<T>& operator=(const T& el)
	{
		element = el;
		is_empty = 0;
		return *this;
	};

	bool empty() { return is_empty; };

	T value() const { return element; };
};