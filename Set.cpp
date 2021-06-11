#include "Set.h"

template <class T>
Set<T>::Set(const Set<T>& other) : _size(other._size)
{
	_elements = new T[_size];
	for (size_t i = 0; i < _size; i++)
		_elements[i] = other._elements[i];
}

template <class T> 
Set<T>& Set<T>::operator=(const Set<T>& other)
{
	if (this != &other)
	{
		if (_size != 0)
		{
			delete[] _elements;
			_size = other._size;
		}

		_elements = new T[_size];
		for (size_t i = 0; i < _size; ++i)
			_elements[i] = other._elements[i];
	}
	return *this;
}

template <class T>
void Set<T>::insert(const T& elem)
{
	if (_size == 0)
	{
		_elements = new T[1];
		_elements[0] = elem;
		++_size;
	}
	else
	{
		for (size_t i = 0; i < _size; ++i)
			if (_elements[i] == elem)
				return;

		T* temp = new T[_size];
		for (size_t i = 0; i < _size; ++i)
			temp[i] = _elements[i];

		++_size;
		_elements = new T[_size];
		for (size_t i = 0; i < _size - 1; ++i)
			_elements[i] = temp[i];

		delete[] temp;
		_elements[_size - 1] = elem;

		std::sort(begin(), end());
	}
}

template <class T>
void Set<T>::clear()
{
	if (_size != 0)
	{
		delete[] _elements;
		_size = 0;
	}
}

template <class T> 
size_t Set<T>::erase(const T& elem)
{
	bool check = 0;
	for (size_t i = 0; i < _size; ++i)
		if (_elements[i] == elem)
		{
			check = 1;
			break;
		}


	if (check)
	{
		T* temp = new T[_size - 1];

		size_t counter = 0;
		for (size_t i = 0; i < _size; ++i)
			if (_elements[i] != elem)
			{
				temp[counter] = _elements[i];
				++counter;
			}

		delete[] _elements;
		_size--;
		_elements = new T[_size];

		for (size_t i = 0; i < _size; ++i)
			_elements[i] = temp[i];

		delete[] temp;
		return 1;
	}
	else
		return 0;
}

template <class T>
void Set<T>::erase(const Iterator<T>& iter)
{
	T* temp = new T[_size - 1];

	size_t counter = 0;
	for (size_t i = 0; i < _size; ++i)
		if (_elements[i] != *iter)
		{
			temp[counter] = _elements[i];
			++counter;
		}

	delete[] _elements;
	_size--;
	_elements = new T[_size];

	for (size_t i = 0; i < _size; ++i)
		_elements[i] = temp[i];

	delete[] temp;
}

template <class T>
void Set<T>::erase(const Iterator<T>& l_iter, const Iterator<T>& r_iter)
{
	size_t diff = std::distance(l_iter, r_iter);
	T* temp = new T[_size - diff];
	size_t temp_counter = 0;

	for (size_t i = 0; i < std::distance(begin(), l_iter); ++i)
	{
		temp[temp_counter] = _elements[i];
		temp_counter++;
	}

	for (size_t i = std::distance(begin(), r_iter); i < _size; ++i)
	{
		temp[temp_counter] = _elements[i];
		temp_counter++;
	}

	delete[] _elements;
	_size -= diff;
	_elements = new T[_size];

	for (size_t i = 0; i < _size; ++i)
		_elements[i] = temp[i];

	delete[] temp;
}

template <class T>
void Set<T>::swap(Set<T>& other)
{
	Set<T> temp = other;

	other.clear();
	other._size = _size;
	for (size_t i = 0; i < other._size; ++i)
		other._elements[i] = _elements[i];

	clear();
	_size = temp._size;
	for (size_t i = 0; i < _size; ++i)
		_elements[i] = temp._elements[i];
}

template <class T>
Node<T> Set<T>::extract(const Iterator<T>& iter)
{
	T node;
	T* temp = new T[_size - 1];

	size_t counter = 0;
	for (size_t i = 0; i < _size; ++i)
	{
		if (_elements[i] != *iter)
		{
			temp[counter] = _elements[i];
			++counter;
		}
		else
			node.element = _elements[i];
	}

	_size--;
	delete _elements;
	_elements = new T[_size];

	for (size_t i = 0; i < _size; ++i)
		_elements[i] = temp[i];

	delete[] temp;

	return node;
}

template <class T>
T Set<T>::extract(const T& elem)
{
	Node<T> node;

	bool check = 0;
	for (size_t i = 0; i < _size; ++i)
		if (_elements[i] == elem)
		{
			check = 1;
			element = elem;
			break;
		}


	if (check)
	{
		T* temp = new T[_size - 1];

		size_t counter = 0;
		for (size_t i = 0; i < _size; ++i)
			if (_elements[i] != elem)
			{
				temp[counter] = _elements[i];
				++counter;
			}

		delete[] _elements;
		_size--;
		_elements = new T[_size];

		for (size_t i = 0; i < _size; ++i)
			_elements[i] = temp[i];

		delete[] temp;
	}
	return node;
}

template <class T>
size_t Set<T>::count(const T& key) const
{
	for (size_t i = 0; i < _size; ++i)
		if (_elements[i] == key)
			return 1;
}

template <class T>
Iterator<T> Set<T>::find(const T& key) const
{
    for (size_t i = 0; i < _size; i++)
        if (_elements[i] == key)
            return begin() + i;

    return end();
}
