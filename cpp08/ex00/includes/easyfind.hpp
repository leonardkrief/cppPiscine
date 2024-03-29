/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:25:49 by lkrief            #+#    #+#             */
/*   Updated: 2023/07/22 11:05:52 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <algorithm>

// Important to store _message variable. Otherwise
// the pointer returned by c_str() will be invalid after the
// what() function returns.
class ElementNotFound : public std::exception
{
    private:
        std::string _message;

    public:
        // The 'explicit' keyword is not mandatory here but I
        // put it for educational purpose. It is used to prevent
        // implicit conversions from int to ElementNotFound. 
        // Without 'explicit', functions accepting an 
        // ElementNotFound object could be called with an int, 
        // leading to unintended behavior. 
        //
        // By declaring the constructor as 'explicit', we 
        // ensure that ElementNotFound objects can only be 
        // created intentionally. 
        //
        // However, such a conversion is unlikely to happen 
        // inadvertently in this context. Therefore, 'explicit' 
        // is not mandatory and is included for educational purposes.
        explicit ElementNotFound(int value)
        {
            std::ostringstream oss;
            oss << value << " not found";
            _message = oss.str();
        }

        virtual ~ElementNotFound() throw() {}

        const char* what() const throw() 
        {
            return _message.c_str();
        }
};


template <typename T>
typename T::difference_type easyfind ( T& A, int value )
{
    typename T::const_iterator sol = std::find(A.begin(), A.end(), value);
    if (sol == A.end())
    {
        throw ElementNotFound(value);
    }
    typename T::difference_type index = std::distance(A.cbegin(), sol);
    std::cout << value << " found at position "
              << index << std::endl;
    return index;
}

// For more info on this template, see:
// https://stackoverflow.com/questions/1154212/how-could-i-print-the-contents-of-any-container-in-a-generic-way
template
  < template <typename Elem, typename Alloc=std::allocator<Elem> > class Container >
std::ostream& operator<< ( std::ostream& o, const Container<int>& container )
{
    typename Container<int>::const_iterator beg = container.begin();
    o << "[";
    while (beg != container.end()) { o << " " << *beg++; }
    o << " ]";
    return o;
}

// For more info on this template, see:
// https://stackoverflow.com/questions/1154212/how-could-i-print-the-contents-of-any-container-in-a-generic-way
template
  < template <typename Elem, typename Alloc=std::allocator<Elem> > class Container >
Container<int> randomContainerOfInts ( size_t n = 10, int min = 0, int max = 20 )
{
    Container<int> obj;

    if (min > max) std::swap (min, max);
    for (size_t i = 0; i < n; i++)
    {
        obj.push_back(min + (rand() % (max - min)));
    }
    return obj;
}

#endif
