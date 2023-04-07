/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:25:49 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/08 00:57:38 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <iomanip>
#include <functional>

template<typename T> class Array
{
    public:
        Array() : _size(0), _array(new T[_size])
        {
            if (Array::_print_log_)
                std::cout << "[" << (void *)this
                    << "] Array default constructor called" << std::endl;
        }

        Array( unsigned int n ) : _size(n), _array(new T[_size])
        {
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = T();
            if (Array::_print_log_)
                std::cout << "[" << (void *)this
                    << "] Array size constructor called" << std::endl;
        }

        Array( const Array& elem )
        {
            *this = elem;
            if (Array::_print_log_)
                std::cout << "[" << (void *)this
                    << "] Array copy constructor called" << std::endl;
        }

        ~Array()
        {
            delete[] _array;
            if (Array::_print_log_)
                std::cout << "[" << (void *)this
                    << "] Array destructor called" << std::endl;
        }

        Array& operator=( const Array& elem )
        {
            if (this != &elem)
            {
                _size = elem._size;
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    (*this)[i] = elem[i];
            }
            return *this;
        }

        T& operator[]( unsigned int i ) const
        {
            if (i + 1 > _size)
                throw std::out_of_range("Range: out of bounds");
            return _array[i];
        }

        unsigned int size() const
        {
            return _size;
        }


    private:
        unsigned int _size;
        T* _array;

        static const bool _print_log_ = false;
};


template<typename T>
std::ostream& operator<<( std::ostream& os, const Array<T>& elem )
{
    os << "{";
    for (unsigned int i = 0; i < elem.size(); i++)
    {
        if (i + 1 < elem.size())
            os << std::setw(2) << std::left << elem[i] << "  ";
        else
            os << elem[i];

    }
    os << "}";
    return os;
}


#endif