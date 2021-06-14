#include <iterator>

#pragma once

template <class T>
class ConstIterator
{
    T* pos;

public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = const T;
    using difference_type = int;
    using pointer = const T*;
    using reference = const T&;

    ConstIterator(T* position) : pos(position) { };

    bool operator==(const ConstIterator<T>& other) const { return pos == other.pos; };
    bool operator!=(const ConstIterator<T>& other) const { return pos != other.pos; };

    reference operator*() const { return *pos; };
    pointer operator->() const { return pos; };

    ConstIterator& operator++()
    {
        ++pos;
        return *this;
    };

    ConstIterator& operator++(int)
    {
        ConstIterator<T> temp = *this;
        ++pos;
        return temp;
    };

    ConstIterator& operator--()
    {
        --pos;
        return *this;
    };

    ConstIterator& operator--(int)
    {
        ConstIterator<T> temp = *this;
        --pos;
        return temp;
    };
};
