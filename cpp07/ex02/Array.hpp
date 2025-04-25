/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 04:41:24 by pscala            #+#    #+#             */
/*   Updated: 2025/04/25 06:07:58 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Array.hpp
#pragma once
#include "Color.hpp"

template <typename T>
class Array
{
private:
    T *_array;
    size_t _size;

public:
    Array();
    Array(const unsigned int n);
    ~Array();
    Array(const Array &cpy);
    Array &operator=(const Array &src);
    T &operator[](size_t index);
    const T &operator[](size_t index) const;
    size_t size() const;
};


template<typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}

template<typename T>
Array<T>::Array(const unsigned int n) : _array(new T[n]()), _size(n)
{
}

template<typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template<typename T>
Array<T>::Array(const Array<T> &cpy)
{
    _size = cpy._size;
    _array = new T[_size]();

    for (size_t i=0; i < _size; ++i)
        _array[i] = cpy._array[i];
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &src)
{
    if (this != &src)
    {
        delete [] _array;
        _size = src._size;
        _array = new T[_size]();

        for (size_t i = 0; i < _size; ++i)
            _array[i] = src._array[i];
    }
    return (*this);
}

template<typename T>
T &Array<T>::operator[](size_t index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return (_array[index]);
}

template<typename T>
const T &Array<T>::operator[](size_t index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return (_array[index]);
}

template<typename T>
size_t Array<T>::size() const
{
    return (_size);
}

