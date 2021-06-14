#include <iterator>

#pragma once

template <class T>
class Iterator
{
    T* pos;

public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = int;
    using pointer = T*;
    using reference = T&;

    Iterator(T* position) : pos(position) { };

    bool operator==(const Iterator<T>& other) const { return pos == other.pos; };
    bool operator!=(const Iterator<T>& other) const { return pos != other.pos; };

    reference operator*() const { return *pos; };
    pointer operator->() const { return pos; };

    Iterator& operator++()
    {
        ++pos;
        return *this;
    };

    Iterator& operator++(int)
    {
        Iterator<T> temp = *this;
        ++pos;
        return temp;
    };

    Iterator& operator--()
    {
        --pos;
        return *this;
    };

    Iterator& operator--(int)
    {
        Iterator<T> temp = *this;
        --pos;
        return temp;
    };
};
