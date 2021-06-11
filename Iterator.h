#include <iterator>

#pragma once

template <class T>
class Iterator
{
    T* pos;

public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = int;
    using pointer = T*;
    using reference = T&;

    Iterator(T* position) : pos(position) { };

    bool operator==(const Iterator<T>& other) const { return pos == other.pos; };
    bool operator!=(const Iterator<T>& other) const { return pos != other.pos; };
    bool operator>(const  Iterator<T>& other) const { return pos > other.pos; };
    bool operator<(const  Iterator<T>& other) const { return pos < other.pos; };
    bool operator>=(const Iterator<T>& other) const { return pos >= other.pos; };
    bool operator<=(const Iterator<T>& other) const { return pos <= other.pos; };

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

    reference operator[](size_t index) const { return pos[index]; };

    Iterator operator+(const difference_type& diff) const { return Iterator<T>(pos + diff); };
    friend inline Iterator operator+(const difference_type& diff, const Iterator<T>& other)
    {
        return Iterator<T>(other.pos + diff);
    };

    Iterator<T> operator-(const difference_type& diff) const { return Iterator<T>(pos - diff); };
    difference_type operator-(const Iterator<T>& other) const { return std::distance(other.pos, pos); };

    Iterator<T> operator+=(const difference_type& diff)
    {
        pos += diff;
        return *this;
    };

    Iterator<T> operator-=(const difference_type& diff)
    {
        pos -= diff;
        return *this;
    };
};