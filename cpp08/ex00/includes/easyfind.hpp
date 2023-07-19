/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:25:49 by lkrief            #+#    #+#             */
/*   Updated: 2023/07/15 20:22:23 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <functional>

template <typename T>
void easyfind ( T& A, int n )
{
    auto sol = A.begin();
    for (auto it = A.begin(); it != A.end() && *it != n; it++)
    {
        sol = it;
    }
    if (*sol != n)
    {
        throw std::out_of_range("Element not found");
    }
    std::cout << n << " was found" << std::endl;
}

#endif