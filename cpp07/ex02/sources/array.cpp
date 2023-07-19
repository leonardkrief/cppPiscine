// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   array.cpp                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/04/07 12:25:49 by lkrief            #+#    #+#             */
// /*   Updated: 2023/04/07 23:41:43 by lkrief           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "array.hpp"
#include <iostream>
#include <iomanip>

// template<typename T>
// Array<T>::Array() : _size(0), _array(new T[_size])
// {
//     if (Array::_print_log_)
//         std::cout << "[" << (void *)this
//             << "] Array default constructor called" << std::endl;
// }

// template<typename T>
// Array<T>::Array( unsigned int n ) : _size(n), _array(new T[_size])
// {
//     if (Array::_print_log_)
//         std::cout << "[" << (void *)this
//             << "] Array size constructor called" << std::endl;
// }

// template<typename T>
// Array<T>::Array( const Array& elem )
// {
//     *this = elem;
//     if (Array::_print_log_)
//         std::cout << "[" << (void *)this
//             << "] Array copy constructor called" << std::endl;
// }

// template<typename T>
// Array<T>::~Array()
// {
//     delete[] _array;
//     if (Array::_print_log_)
//         std::cout << "[" << (void *)this
//             << "] Array destructor called" << std::endl;
// }

// template<typename T>
// Array<T>& Array<T>::operator=( const Array& elem )
// {
//     if (this != &elem)
//     {
//         _size = elem._size;
//         _array = new T[_size];
//         for (unsigned int i = 0; i < _size; i++)
//             _array[i] = elem._array[i];
//     }
//     return *this;
// }

// template<typename T>
// T& Array<T>::operator[]( unsigned int i ) const
// {
//     if (i + 1 > _size)
//         throw std::out_of_range("Range: out of bounds");
//     return _array[i];
// }

// template<typename T>
// unsigned int Array<T>::size() const
// {
//     return _size;
// }

template<typename T>
std::ostream& operator<<( std::ostream& os, const Array<T>& elem )
{
    os << "{";
    for (unsigned int i = 0; i < elem.size(); i++)
    {
        os << std::setw(3) << std::left << elem[i];
        if (i + 1 < elem.size())
            os << ", ";
    }
    os << "}";
    return os;
}