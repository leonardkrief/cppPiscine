/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMerge.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:25:49 by lkrief            #+#    #+#             */
/*   Updated: 2023/07/24 11:04:36 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_HPP
# define PMERGE_HPP

#include <iostream>
#include <deque>
#include <vector>

class Pmerge
{
    public:
        Pmerge( std::string& str ) : _input(str) {};
        ~Pmerge() {};

    // I will perform the algorithm on std::vector (probably best)
    // and std::deque
    private:
        std::string _input;
        
        Pmerge( void ) {};
        Pmerge(const Pmerge& src) : _input(src._input) {};
        Pmerge& operator= (const Pmerge& src)
        {
            if (this != &src) _input = src._input;
            return *this;
        };
};

#endif
