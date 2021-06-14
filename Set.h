#include <iostream>
#include <algorithm>

#include "Iterator.h"
#include "ConstIterator.h"
#include "ReverseIterator.h"
#include "ConstReverseIterator.h"

#include "MyComparator.h"

#pragma once

template <class T, class Comp = std::less<T>>
class Set
{
private:
	T* _elements;
	size_t _size;

public:
	Set() :  _size(0), _elements(nullptr) 
	{
		_elements = new T[2];
	};
	Set(const Set<T, Comp>& other);

	~Set()
	{
		if (_elements != nullptr)
			delete[] _elements;
		_size = 0;
	}

	Set& operator=(const Set<T>& other);

	Iterator<T> begin()               noexcept          { return Iterator<T>(&_elements[1]);                        };
	ConstIterator<T> cbegin()         const noexcept    { return ConstIterator<T>(&_elements[1]);                   };
	ReverseIterator<T> rbegin()       noexcept		    { return ReverseIterator<T>(&_elements[_size - 1]); };
	ConstReverseIterator<T> crbegin() const noexcept    { return ConstReverseIterator<T>(&_elements[_size - 1]);    };

	Iterator<T> end()                 noexcept          { return Iterator<T>(&_elements[_size + 1]);                };
	ConstIterator<T> cend()	          const noexcept    { return ConstIterator<T>(&_elements[_size + 1]);		};
	ReverseIterator<T> rend()         noexcept	    { return ReverseIterator<T>(&_elements[0]);		        };
	ConstReverseIterator<T> crend()   const noexcept    { return ConstReverseIterator<T>(&_elements[0]);		};

	void insert(const T& elem);

	bool empty() { return _size == 0; };
	int size()   { return _size;      };

	void clear();

	size_t erase(const T& elem);
	void erase(const Iterator<T>& iter);
	void erase(const Iterator<T>& l_iter, const Iterator<T>& r_iter);

	void swap(Set<T>& other);

	T extract(const Iterator<T>& iter);
	T extract(const T& element);

	size_t count(const T& key) const;
	Iterator<T> find(const T& key) const;
	void merge(Set<T, Comp>& other);
};
