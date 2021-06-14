#include <iterator>

#pragma once

template <class T>
class ConstReverseIterator
{
    T* pos;

public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = const T;
    using difference_type = int;
    using pointer = const T*;
    using reference = const T&;

    ConstReverseIterator(T* position) : pos(position) { };

    bool operator==(const ConstReverseIterator<T>& other) const { return pos == other.pos; };
    bool operator!=(const ConstReverseIterator<T>& other) const { return pos != other.pos; };

    reference operator*() const { return *pos; };
    pointer operator->() const { return pos; };

    ConstReverseIterator& operator++()
    {
        --pos;
        return *this;
    };

    ConstReverseIterator& operator++(int)
    {
        ConstReverseIterator<T> temp = *this;
        --pos;
        return temp;
    };

    ConstReverseIterator& operator--()
    {
        ++pos;
        return *this;
    };

    ConstReverseIterator& operator--(int)
    {
        ConstReverseIterator<T> temp = *this;
        ++pos;
        return temp;
    };
};
