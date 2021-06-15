#include "Set.h"

template <class T, class Comp>
Set<T, Comp>::Set(const Set<T, Comp>& other) : _size(other._size)
{
	_elements = new T[_size + 2];
	for (size_t i = 1; i < _size + 1; i++)
		_elements[i] = other._elements[i];
}

template <class T, class Comp> 
Set<T, Comp>& Set<T, Comp>::operator=(const Set<T, Comp>& other)
{
	if (this != &other)
	{
		if (_size != 0)
		{
			delete[] _elements;
			_size = other._size;
		}

		_elements = new T[_size + 2];
		for (size_t i = 1; i < _size + 1; ++i)
			_elements[i] = other._elements[i];
	}
	return *this;
}

template <class T, class Comp>
void Set<T, Comp>::insert(const T& elem)
{
	for (size_t i = 0; i < _size; i++)      /*проверка элемента на уникальность*/
		if (_elements[i] == elem)
			return;

	_size++;

	if (_size == 1)                         /*если у нас пустое множество, то просто создаем его на новом элементе*/
	{
		if (_elements != nullptr)
			delete[] _elements;
		_elements = new T[3];
		_elements[1] = elem;
	}
	else if (_size == 2)                    /*если есть 1 элемент, нужно понять, на какое место его ставить*/
	{
		T* temp = new T[4];
		if (Comp()(_elements[1], elem))
		{
			temp[1] = _elements[1];
			temp[2] = elem;
		}
		else
		{
			temp[1] = elem;
			temp[2] = _elements[1];
		}
		delete[] _elements;
		_elements = temp;
	}
	else
	{
		bool check = false;
		T* temp = new T[_size + 2];
		for (size_t i = 1; i < _size + 1; i++)
		{
			if (Comp()(elem, _elements[i]))
			{
				temp[i] = elem;
				check = 1;
			}
			else
				temp[i] = _elements[i];

			if (check)
			{
				i++;
				for (size_t j = i; j < _size + 1; j++)
					temp[j] = _elements[j - 1];
				break;
			}
		}

		if (!check)
			temp[_size] = elem;

		delete[] _elements;
		_elements = temp;
	}
}

template <class T, class Comp>
void Set<T, Comp>::clear()
{
	if (_size != 0)
	{
		delete[] _elements;
		_size = 0;
	}
}

template <class T, class Comp> 
size_t Set<T, Comp>::erase(const T& elem)
{
	bool check = 0;
	int pos = -1;
	for (size_t i = 1; i < _size + 1; ++i)
		if (_elements[i] == elem)
		{
			check = 1;
			pos = i;
			break;
		}


	if (check)
	{
		for (int i = pos; i < _size; i++)
			_elements[i] = _elements[i + 1];
		_size--;
		return 1;
	}
	else
		return 0;
}

template <class T, class Comp>
void Set<T, Comp>::erase(const Iterator<T>& iter)
{
	int pos = std::distance(begin(), iter) + 1;

	for (int i = pos; i < _size; i++)
		_elements[i] = _elements[i + 1];

	_size--;
}

template <class T, class Comp>
void Set<T, Comp>::erase(const Iterator<T>& l_iter, const Iterator<T>& r_iter)
{
	size_t beg_diff = std::distance(begin(), l_iter) + 1;
	size_t diff = std::distance(l_iter, r_iter);
	
	if (diff >= _size)
		_size = 0;
	else
	{
		for (int i = beg_diff; i < _size; ++i)
			_elements[i] = _elements[i + diff];
		_size -= diff;
	}
}

template <class T, class Comp>
void Set<T, Comp>::swap(Set<T, Comp>& other)
{
	Set<T, Comp> temp = other;
	other = *this;
	*this = temp;
}

template <class T, class Comp>
T Set<T, Comp>::extract(const Iterator<T>& iter)
{
	T node = *iter;
	int pos = std::distance(begin(), iter) + 1;

	for (int i = pos; i < _size; i++)
		_elements[i] = _elements[i + 1];

	_size--;

	return node;
}

template <class T, class Comp>
T Set<T, Comp>::extract(const T& elem)
{
	T node = elem;

	bool check = 0;
	int pos = -1;
	for (size_t i = 1; i < _size + 1; ++i)
		if (_elements[i] == elem)
		{
			check = 1;
			pos = i;
			break;
		}


	if (check)
	{
		for (int i = pos; i < _size; i++)
			_elements[i] = _elements[i + 1];
		_size--;
		return node;
	}

	return node;
}

template <class T, class Comp>
size_t Set<T, Comp>::count(const T& key) const
{
	for (size_t i = 0; i < _size; ++i)
		if (_elements[i] == key)
			return 1;
	return 0;
}

template <class T, class Comp>
Iterator<T> Set<T, Comp>::find(const T& key)
{
	Iterator<T> result = begin();
	
	for (size_t i = 1; i < _size + 1; ++i)
	{
		++result;
		if (_elements[i] == key)
			return result;
	}
	return end();
}

template <class T, class Comp>
void Set<T, Comp>::merge(Set<T, Comp>& other)
{
	T* temp = new T[_size + other._size + 2];

	size_t first_c = 1;
	size_t second_c = 1;
	size_t main_c = 1;
	size_t same_c = 0;

	while ((first_c < _size + 1) && (second_c < other._size + 1))
	{
		if (Comp()(_elements[first_c], other._elements[second_c]))
		{
			temp[main_c] = _elements[first_c];
			main_c++;
			first_c++;
		}
		else if (_elements[first_c] != other._elements[second_c])
		{
			temp[main_c] = other._elements[second_c];
			main_c++;
			second_c++;
		}
		else
		{
			temp[main_c] = _elements[first_c];
			second_c++;
			first_c++;
			main_c++;
		}
	}

	while (first_c < _size + 1)
	{
		temp[main_c] = _elements[first_c];
		main_c++;
		first_c++;
	}

	while (second_c < other._size + 1)
	{
		temp[main_c] = other._elements[second_c];
		main_c++;
		second_c++;
	}

	for (size_t i = 1; i < _size + 1; ++i)
		for (size_t j = 1; j < _size + 1; ++j)
			if (_elements[i] == other._elements[j])
				same_c++;

	T* same_el = new T[same_c];
	size_t ii = 1;

	if (same_c != 0)
		for (size_t i = 1; i < _size + 1; ++i)
			for (size_t j = 1; j < _size + 1; ++j)
				if (_elements[i] == other._elements[j])
				{
					same_el[ii] = _elements[i];
					ii++;
				}

	delete[] _elements;
	_size = _size + other._size - same_c;
	_elements = temp;

	delete[] other._elements;
	other._size = same_c;
	other._elements = same_el;
}
