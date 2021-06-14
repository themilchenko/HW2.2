#include <iterator>

#pragma once

template <class T>
class ReverseIterator
{
    T* pos;

public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = int;
    using pointer = T*;
    using reference = T&;

    ReverseIterator(T* position) : pos(position) { };

    bool operator==(const ReverseIterator<T>& other) const { return pos == other.pos; };
    bool operator!=(const ReverseIterator<T>& other) const { return pos != other.pos; };

    reference operator*() const { return *pos; };
    pointer operator->() const { return pos; };

    ReverseIterator& operator++()
    {
        --pos;
        return *this;
    };

    ReverseIterator& operator++(int)
    {
        ReverseIterator<T> temp = *this;
        --pos;
        return temp;
    };

    ReverseIterator& operator--()
    {
        ++pos;
        return *this;
    };

    ReverseIterator& operator--(int)
    {
        ReverseIterator<T> temp = *this;
        ++pos;
        return temp;
    };

    reference operator[](size_t index) const { return pos[index]; };

    ReverseIterator operator+(const difference_type& diff) const { return ReverseIterator<T>(pos - diff); };
    friend inline ReverseIterator operator+(const difference_type& diff, const ReverseIterator<T>& other)
    {
        return ReverseIterator<T>(other.pos - diff);
    };

    ReverseIterator<T> operator-(const difference_type& diff) const { return ReverseIterator<T>(pos + diff); };
    difference_type operator-(const ReverseIterator<T>& other) const { return std::distance(other.pos, pos); };

    ReverseIterator<T> operator+=(const difference_type& diff)
    {
        pos -= diff;
        return *this;
    };

    ReverseIterator<T> operator-=(const difference_type& diff)
    {
        pos += diff;
        return *this;
    };
};
