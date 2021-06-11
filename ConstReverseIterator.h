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
    bool operator>(const  ConstReverseIterator<T>& other) const { return pos > other.pos; };
    bool operator<(const  ConstReverseIterator<T>& other) const { return pos < other.pos; };
    bool operator>=(const ConstReverseIterator<T>& other) const { return pos >= other.pos; };
    bool operator<=(const ConstReverseIterator<T>& other) const { return pos <= other.pos; };

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

    reference operator[](size_t index) const { return pos[index]; };

    ConstReverseIterator operator+(const difference_type& diff) const { return ConstReverseIterator<T>(pos - diff); };
    friend inline ConstReverseIterator operator+(const difference_type& diff, const ConstReverseIterator<T>& other)
    {
        return ConstReverseIterator<T>(other.pos - diff);
    };

    ConstReverseIterator<T> operator-(const difference_type& diff) const { return ConstReverseIterator<T>(pos + diff); };
    difference_type operator-(const ConstReverseIterator<T>& other) const { return std::distance(other.pos, pos); };

    ConstReverseIterator<T> operator+=(const difference_type& diff)
    {
        pos -= diff;
        return *this;
    };

    ConstReverseIterator<T> operator-=(const difference_type& diff)
    {
        pos += diff;
        return *this;
    };
};