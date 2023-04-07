/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:25:49 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/07 19:28:26 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <iomanip>
#include <functional>

template<typename T>
void iter( T* addr, unsigned int N, void f( T& arg ) )
{
    for (unsigned int i = 0; i < N; i++)
        f(addr[i]);
}

template<typename T, unsigned N>
void printTab( T (&addr)[N] )
{
    std::cout << "{";
    for (unsigned int i = 0; i < N; i++)
    {
        std::cout << std::setw(3) << std::left << addr[i];
        if (i + 1 < N)
            std::cout << ", ";
    }
    std::cout << "}" << std::endl;
}

#endif