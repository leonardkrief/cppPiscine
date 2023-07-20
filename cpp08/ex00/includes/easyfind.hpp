/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:25:49 by lkrief            #+#    #+#             */
/*   Updated: 2023/07/20 19:22:19 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <sstream>
#include <algorithm>

class ElementNotFound : public std::exception
{
    public:
        const char* what() const throw() { return "Element not found";};
};

template <typename T>
typename T::difference_type easyfind ( T& A, int value )
{
    typename T::iterator sol = std::find(A.begin(), A.end(), value);
    if (sol == A.end())
    {
        throw ElementNotFound();
    }
    typename T::difference_type index = std::distance(A.begin(), sol);
    std::cout << value << " was found at position "
              << index << std::endl;
    return index;
}

template <template <int>>

template <typename<T>>
void printContainer( T<int> A)
{
    std::cout << "{ ";
    for (std::vector<int>::iterator it = A.begin(); it != A.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "}" << std::endl;
}

#endif
