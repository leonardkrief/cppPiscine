/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:25:49 by lkrief            #+#    #+#             */
/*   Updated: 2023/07/21 16:20:50 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <sstream>
#include <vector>

class Span
{
    public:
        Span(unsigned int n) : _max_size(n) {} ;
        Span(const Span& src) : _max_size(src._max_size), _vector(src._vector) {} ;
        ~Span() {} ;

        Span& operator= (const Span& src);
        std::vector<int> getVect() const { return _vector; };
        void addNumber(int n);

        template
        <template <typename Elem, typename Alloc=std::allocator<Elem> > class Container>
        void addRange(typename Container<int>::iterator start, typename Container<int>::iterator end)
        {
            for (typename Container<int>::iterator it = start; it != end; it++)
            {
                addNumber(*it);
            }
        };

        void addRandoms(int n = 20, int min = -100, int max = 100);
        unsigned int shortestSpan(bool debug = false) const;
        unsigned int longestSpan(bool debug = false) const;
        
        class SpanFullException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class NoSpanFoundException : public std::exception
        {
            public:
                const char* what() const throw();
        };

    private:
        const unsigned int _max_size;
        std::vector<int> _vector;
};

std::ostream& operator << (std::ostream& os, const Span& s);

#endif
