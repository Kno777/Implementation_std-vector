#ifndef __VECTOR__H__
#define __VECTOR__H__

#include <initializer_list>

template <typename T>
class Vector
{
public:
    class iterator
    {
    public:
        iterator() = default;
        ~iterator() = default;
        iterator(const iterator&) = default;
        iterator(iterator&&) = default;
        iterator &operator=(const iterator&) = default;
        iterator(T* ptr) : m_ptr { ptr }{};
    public:
        bool operator==(iterator);
        bool operator!=(iterator);
        bool operator<(iterator);
        bool operator<=(iterator);
        bool operator>(iterator);
        bool operator>=(iterator);
        iterator &operator++();
        iterator operator++(int);
        iterator &operator--();
        iterator operator--(int);
        T &operator*();
        const T &operator*() const;
    private:
        T * m_ptr;
    };
    Vector();
    Vector(const Vector<T>&);
    Vector(Vector<T>&&);
    Vector(const std::initializer_list<T> &);
    Vector& operator=(const Vector<T>&);
    Vector& operator=(Vector&&);
    ~Vector();
public:
    void push_back(T);
    void pop_back();
    void push_front(T);
    void pop_front();
    void clear();
    T& at(T);
    bool empety() const;
    unsigned size();
    unsigned capacity();
    const T& operator[](unsigned) const;
    T& operator[](unsigned);
public:
    iterator begin();
    iterator end();
private:
    T* m_array;
    unsigned m_size;
    unsigned m_cap;
};

#include "vector.hpp"

#endif // __VECTOR__H__