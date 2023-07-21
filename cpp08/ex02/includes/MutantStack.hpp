/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:25:49 by lkrief            #+#    #+#             */
/*   Updated: 2023/07/21 16:38:35 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack( void ) {} ;
        MutantStack(const MutantStack& src) { *this = src; } ;
        virtual ~MutantStack() {} ;
        MutantStack& operator= (const MutantStack& src);

    // iterators
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator begin( void ) { return this->c.begin(); }
        iterator end( void ) { return this->c.end(); }
        const_iterator cbegin( void ){ return this->c.begin(); }
        const_iterator cend( void ){ return this->c.end(); }
};



template <typename T>
MutantStack<T>& MutantStack<T>::operator= (const MutantStack<T>& src)
{
    if (this != &src)
    {
        static_cast< std::stack<T> >(*this) = static_cast< std::stack<T> >(src);
    }
    return *this;
}

#endif
