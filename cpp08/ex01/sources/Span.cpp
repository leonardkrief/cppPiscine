/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:25:49 by lkrief            #+#    #+#             */
/*   Updated: 2023/07/22 11:47:56 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstdlib>
#include "Span.hpp"

Span& Span::operator= (const Span& src)
{
    if (this != &src)
    {
        if (_max_size != src._max_size)
        {
            throw std::invalid_argument("Cannot copy Spans of different sizes.");
        }
        _vector = src._vector;
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (_vector.size() >= _max_size)
    {
        throw Span::SpanFullException();
    }
    _vector.push_back(n);
}

void Span::addRandoms(int n, int min, int max)
{
    if (min > max) std::swap(min, max);
    for (int i = 0; i < n; i++)
    {
        addNumber(min + rand() % (max - min));
    }
}


unsigned int Span::shortestSpan(bool debug) const
{
    if (_vector.size() <= 1) throw Span::NoSpanFoundException();

    long long int span = std::numeric_limits<unsigned int>::max();
    std::vector<int> copy = _vector;
    std::sort(copy.begin(), copy.end());
    if (debug) std::cout << "\n";

    for (std::vector<int>::const_iterator it = copy.cbegin(); it < copy.cend() - 1 && span; it++)
    {
        long long int diff = static_cast<long long int>(*it) - static_cast<long long int>(*(it + 1));
        diff = std::abs(diff);
        if (span > diff && debug) std::cout << *(it + 1) << " - " << *it << " = " << diff << "\n";
        span = std::min(span, diff);
    }

    return static_cast<unsigned int> (span);
}

unsigned int Span::longestSpan(bool debug) const
{
    if (_vector.size() <= 1) throw Span::NoSpanFoundException();
    std::vector<int>::const_iterator min = std::min_element(_vector.cbegin(), _vector.cend());
    std::vector<int>::const_iterator max = std::max_element(_vector.cbegin(), _vector.cend());
    if (debug) std::cout << *max << " - " << *min << " = ";
    return static_cast<unsigned int> (static_cast<long long int>(*max) - static_cast<long long int>(*min));
}

std::ostream& operator << (std::ostream& os, const Span& s)
{
    std::vector<int> v = s.getVect();
    std::vector<int>::const_iterator it = v.cbegin();
    os << "{";
    while (it != v.cend()) { os << " " << *it++; }
    os << " }";
    return os;
}

const char* Span::SpanFullException::what() const throw()
{
    return "Span object is full. Could not add more elements.";
}

const char* Span::NoSpanFoundException::what() const throw()
{
    return "Span object's size is less than 2. Span cannot be computed.";
}
