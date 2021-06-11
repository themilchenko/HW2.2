#include <iterator>

#pragma once

template <class T>
class ConstIterator
{
    T* pos;

public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = const T;
    using difference_type = int;
    using pointer = const T*;
    using reference = const T&;

    ConstIterator(T* position) : pos(position) { };

    bool operator==(const ConstIterator<T>& other) const { return pos == other.pos; };
    bool operator!=(const ConstIterator<T>& other) const { return pos != other.pos; };
    bool operator>(const  ConstIterator<T>& other) const { return pos > other.pos; };
    bool operator<(const  ConstIterator<T>& other) const { return pos < other.pos; };
    bool operator>=(const ConstIterator<T>& other) const { return pos >= other.pos; };
    bool operator<=(const ConstIterator<T>& other) const { return pos <= other.pos; };

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

    reference operator[](size_t index) const { return pos[index]; };

    ConstIterator operator+(const difference_type& diff) const { return ConstIterator<T>(pos + diff); };
    friend inline ConstIterator operator+(const difference_type& diff, const ConstIterator<T>& other)
    {
        return ConstIterator<T>(other.pos + diff);
    };

    ConstIterator<T> operator-(const difference_type& diff) const { return ConstIterator<T>(pos - diff); };
    difference_type operator-(const ConstIterator<T>& other) const { return std::distance(other.pos, pos); };

    ConstIterator<T> operator+=(const difference_type& diff)
    {
        pos += diff;
        return *this;
    };

    ConstIterator<T> operator-=(const difference_type& diff)
    {
        pos -= diff;
        return *this;
    };
};