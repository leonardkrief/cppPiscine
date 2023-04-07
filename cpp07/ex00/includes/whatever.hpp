/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:25:49 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/07 18:33:26 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <functional>

template<typename T>
void swap( T& a, T& b )
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T& min( T& a, T& b )
{
    if (std::less<T>()(a, b)) { return a; }
    return b;
}

template<typename T>
T& max( T& a, T& b )
{
    if (std::less<T>()(b, a)) { return a; }
    return b;
}

template <typename T>
void testSwap( T& a, T& b, bool print_args = true )
{
    if (print_args)
        std::cout << "a = '" << a << "'    b = '" << b << "'" << std::endl;
    swap(a, b);
    std::cout << "  swap:  a = '" << a << "'    b = '" << b << "'" << std::endl;
    swap(a, b);
}

template <typename T>
void testMin( T& a, T& b, bool print_args = true )
{
    if (print_args)
        std::cout << "a = '" << a << "'    b = '" << b << "'" << std::endl;
    std::cout << "  min :      '" << min(a, b) << "'" << std::endl;
}

template <typename T>
void testMax( T& a, T& b, bool print_args = true )
{
    if (print_args)
        std::cout << "a = '" << a << "'    b = '" << b << "'" << std::endl;
    std::cout << "  max :      '" << max(a, b) << "'" << std::endl;
}

template <typename T>
void testFuncsTemplate( T a, T b )
{
    testSwap(a, b);
    testMin(a, b, false);
    testMax(a, b, false);
    std::cout << std::endl;
}

#endif