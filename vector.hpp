#include <iostream>
#include <exception>
#include "vector.h"

template <typename T>
Vector<T>::Vector()
{
    m_size = 0;
    m_cap = 0;
    m_array = new T[m_cap];
}

template <typename T>
Vector<T>::~Vector()
{
    if(m_array != nullptr)
    {
        delete[] m_array;
        m_array = nullptr;
    }
}

template <typename T>
Vector<T>::Vector(const Vector<T>& oth)
{
    m_size = oth.m_size;
    m_cap = oth.m_cap;
    delete[] m_array;
    m_array = nullptr;
    for(int i = 0; i < m_size; ++i)
    {
        m_array[i] = oth.m_array[i];
    }
}

template <typename T>
Vector<T>::Vector(const std::initializer_list<T>& oth)
{
    m_size = oth.size();
    m_array = new T[m_cap];
    for(int i = 0; i < m_size; ++i)
    {
        m_array[i] = oth.begin()[i];
    }
}

template <typename T>
Vector<T>::Vector(Vector<T>&& oth)
{
    m_size = oth.m_size;
    m_cap = oth.m_cap;
    m_array = nullptr;
    m_array = oth.m_array;
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &oth)
{
    if(this == &oth)
    {
        return *this;
    }
    m_size = oth.m_size;
    m_cap = oth.m_cap;
    delete[] m_array;
    for(int i = 0; i < m_size; ++i)
    {
        m_array[i] = oth.m_array[i];
    }
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T>&& oth)
{
    if (this == &oth)
    {
        return *this;
    }
    m_size = oth.m_size;
    m_cap = oth.m_cap;
    m_array = oth.m_array;
    return *this;
}

template <typename T>
const T& Vector<T>::operator[](unsigned pos) const
{
    return m_array[pos];
}

template <typename T>
T& Vector<T>::operator[](unsigned pos)
{
    return m_array[pos];
}

template <typename T>
void Vector<T>::push_back(T elem)
{
    if(m_size == m_cap)
    {
        m_cap = m_cap == 0 ? 2 : m_cap * 2;
        T *tmp = new T[m_cap];
        for(int i = 0; i < m_size; ++i)
        {
            tmp[i] = m_array[i];
        }
        tmp[m_size] = elem;
        delete[] m_array;
        m_array = nullptr;
        m_array = tmp;
        ++m_size;
    }
    else
    {
        m_array[m_size] = elem;
        ++m_size;
    }
}

template <typename T>
void Vector<T>::pop_back()
{
    --m_size;
}

template <typename T>
void Vector<T>::push_front(T elem)
{
    if(m_size == m_cap)
    {
        m_cap = m_cap == 0 ? 2 : m_cap * 2;
        T *tmp = new T[m_cap];
        for(int i = 0; i < m_size; ++i)
        {
            tmp[0] = elem;
            i++;
        }
        delete[] m_array;
        m_array = tmp;
        ++m_size;
    }
    else
    {
        for(int i = 0; i < m_size; ++i)
        {
            m_array[0] = elem;
            i++;
        }
        ++m_size;
    }
}

template <typename T>
void Vector<T>::pop_front()
{
    for(int i = 0 ; i < m_size; ++i)
    {
        m_array[i] = m_array[i+1];
    }
    --m_size;
}

template <typename T>
void Vector<T>::clear()
{
    if(m_array != nullptr)
    {
        delete[] m_array;
    }
    m_size = 0;
    m_cap = 0;
}

template <typename T>
bool Vector<T>::empety() const
{
    return !m_size;
}

template <typename T>
unsigned Vector<T>::size()
{
    return m_size;
}

template <typename T>
unsigned Vector<T>::capacity()
{
    return m_cap;
}

template <typename T>
T& Vector<T>::at(T pos)
{
    try
    {
        return m_array[pos];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

template <typename T>
bool Vector<T>::iterator::operator==(Vector<T>::iterator oth)
{
    return m_ptr == oth.m_ptr;
}

template <typename T>
bool Vector<T>::iterator::operator!=(Vector<T>::iterator oth)
{
    return m_ptr != oth.m_ptr;
}

template <typename T>
bool Vector<T>::iterator::operator>=(Vector<T>::iterator oth)
{
    return m_ptr >= oth.m_ptr;
}

template <typename T>
bool Vector<T>::iterator::operator>(Vector<T>::iterator oth)
{
    return m_ptr > oth.m_ptr;
}

template <typename T>
bool Vector<T>::iterator::operator<=(Vector<T>::iterator oth)
{
    return m_ptr <= oth.m_ptr;
}

template <typename T>
bool Vector<T>::iterator::operator<(Vector<T>::iterator oth)
{
    return m_ptr < oth.m_ptr;
}

template <typename T>
typename Vector<T>::iterator &Vector<T>::iterator::operator++()
{
    m_ptr += 1;
    return *this;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::iterator::operator++(int)
{
    auto tmp = m_ptr;
    tmp += 1;
    return tmp;
}

template <typename T>
typename Vector<T>::iterator &Vector<T>::iterator::operator--()
{
    m_ptr -= 1;
    return *this;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::iterator::operator--(int)
{
    auto tmp = m_ptr;
    tmp -= 1;
    return tmp;
}

template <typename T>
T& Vector<T>::iterator::operator*()
{
    return *m_ptr;
}

template <typename T>
const T &Vector<T>::iterator::operator*() const
{
    return *m_ptr;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return m_array;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end()
{
    return m_array + m_size;
}
