/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:29:14 by lkrief            #+#    #+#             */
/*   Updated: 2023/09/06 11:58:03 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <utility>

Pmerge::Pmerge( void ) {};

Pmerge::Pmerge( std::string& str ) : _input(str), _nbElements(checkNbElements(str)), _debug(false) {};

Pmerge::~Pmerge() {};

Pmerge::Pmerge( const Pmerge& src ) : _input(src._input), _nbElements(src._nbElements), _debug(src._debug) {};

Pmerge& Pmerge::operator= ( const Pmerge& src )
{
    if (this != &src)
    {
        _input = src._input;
        _nbElements = src._nbElements;
        _debug = src._debug;
    }
    return *this;
};

std::string Pmerge::getInput() const
{
    return _input;
}

int Pmerge::getNbElements() const
{
    return _nbElements;
}

std::vector<int> Pmerge::getSorted() const
{
    return _sorted;
}

void Pmerge::setDebug( const bool& debug )
{
    _debug = debug;
}

void Pmerge::setSorted( const std::vector<int>& sorted )
{
    _sorted = sorted;
}


// performs 2 things at the same time:
// checks if input is valid and throws an exception if not.
// returns true or false based on even or odd number of ints
// only used to initialize a Pmerge object
int Pmerge::checkNbElements( const std::string& str )
{
    std::istringstream iss(str);
    int a, nbElems = 0;

    while (iss >> a)
    {
        nbElems++;
        if (a < 0) throw std::runtime_error("negative integers");
    }
    if (iss.fail() && !iss.eof()) throw std::runtime_error("invalid input");
    return nbElems;
}

bool Pmerge::comparePairs( const std::pair<int, int>& a, const std::pair<int, int>& b )
{
    return a.second <= b.second;
}

// builds a vector of pairs by taking the ints in the order of the input
// the pairs are ALWAYS sorted
// the vector is ALWAYS sorted according to the second element of the pairs
// if there is an odd number of ints, one pair will contain -1
std::vector< std::pair<int,int> > Pmerge::getPairsVector() const
{
    std::istringstream iss(_input);
    int a;
    int b;
    std::vector< std::pair<int,int> > pairs;

    if (_debug) std::cout << BOLDYELLOW << "VECTOR DEBUG\n" << RESET << DEBUG_TEXT_COLOR << "input: '" << DEBUG_OBJECTS_COLOR << _input << RESET << DEBUG_TEXT_COLOR << "'" << std::endl << RESET;

    while (iss >> a && iss >> b)
    {
        if (a > b) std::swap (a,b);
        std::pair<int,int> p (a,b);
        pairs.insert(std::upper_bound(pairs.begin(), pairs.end(), p, comparePairs), p);
        a = -1, b = -1;
    }
    if (_nbElements % 2)
    {
        std::pair<int,int> p (-1,a);
        pairs.insert(std::upper_bound(pairs.begin(), pairs.end(), p, comparePairs), p);
    }
    if (iss.fail() && !iss.eof()) throw std::runtime_error("unexpected error while parsing");
    if (_debug) std::cout << DEBUG_TEXT_COLOR << "initial pairs: " << DEBUG_OBJECTS_COLOR << pairs << std::endl << RESET;
    return pairs;
}

// orders the pairs array according to the Johnson-Ford method:
// { 4 3 | 6 5 | 12 11 10 9 8 7 | 22 21 ... }
// you make groups of sizes such as the sum of two consecutives is a power of 2:
// 2 2 6 10 22 42 ...
std::vector<int> Pmerge::orderPairsVector( std::vector< std::pair<int,int> >& pairs ) const
{
    int g_size = 2, pow = 4;
    std::vector<int> v;
    std::vector< std::pair<int,int> >::const_iterator border;

    for (std::vector< std::pair<int,int> >::const_iterator it = pairs.begin(); it < pairs.end(); )
    {
        border = it;
        it = border + g_size;
        if (it >= pairs.end()) it = pairs.end();
        while (--it >= border) v.push_back((*it).first);
        it = border + g_size;
        g_size = pow - g_size;
        pow *= 2;
    }
    if (_debug) std::cout << DEBUG_TEXT_COLOR << "Johnson-Ford ordered elements: " << DEBUG_OBJECTS_COLOR << v << std::endl << std::endl << RESET;
    return v;
}

std::vector<int> Pmerge::vectorSort()
{
    std::vector<int> sorted, ordered;
    std::vector< std::pair<int,int> > pairs(getPairsVector());

    if (pairs.size() == 0) return sorted;

    // creates the array of second elements + first pair's first element
    // deletes then the first pair from the pairs array because it is dealt with
    sorted.push_back(pairs[0].first);
    for (std::vector< std::pair<int,int> >::const_iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        sorted.push_back((*it).second);
    }
    pairs.erase(pairs.begin());

    if (_debug) std::cout << DEBUG_TEXT_COLOR << "new pairs: " << DEBUG_OBJECTS_COLOR << pairs << std::endl << RESET
        << DEBUG_TEXT_COLOR << "first-step sorted: " << DEBUG_OBJECTS_COLOR << sorted << std::endl << RESET;

    ordered = orderPairsVector(pairs);

    mergeVectors(sorted, ordered);

    if (sorted[0] == -1) sorted.erase(sorted.begin());
    
    setSorted(sorted);
    return sorted;
}

void Pmerge::mergeVectors(std::vector<int>& sorted, const std::vector<int>& ordered)
{
    int g_size = 2, pow = 4, q = 0;
    std::vector<int>::iterator bound;
    for (std::vector<int>::const_iterator it = ordered.begin(); it < ordered.end(); it++)
    {
        bound = std::min(sorted.begin() + pow, sorted.end());
        sorted.insert(std::lower_bound(sorted.begin(), bound, *it), *it);
        if (++q == g_size)
        {
            g_size = pow - g_size;
            pow *= 2;
            q = 0;
        }
        if (_debug) std::cout << DEBUG_TEXT_COLOR "inserted " << *it << ": " << DEBUG_OBJECTS_COLOR << sorted << std::endl << std::endl << RESET;
    }
}


std::deque< std::pair<int,int> > Pmerge::getPairsDeque() const
{
    std::istringstream iss(_input);
    int a;
    int b;
    std::deque< std::pair<int,int> > pairs;

    if (_debug) std::cout << BOLDYELLOW << "DEQUE DEBUG\n" << RESET << DEBUG_TEXT_COLOR << "input: '" << DEBUG_OBJECTS_COLOR << _input << RESET << DEBUG_TEXT_COLOR << "'" << std::endl << RESET;

    while (iss >> a && iss >> b)
    {
        if (a > b) std::swap (a,b);
        std::pair<int,int> p (a,b);
        std::deque< std::pair<int,int> >::iterator it = std::upper_bound(pairs.begin(), pairs.end(), p, comparePairs);
        pairs.insert(it, p);
        a = -1, b = -1;
    }
    if (_nbElements % 2)
    {
        std::pair<int,int> p (-1,a);
        std::deque< std::pair<int,int> >::iterator it = std::upper_bound(pairs.begin(), pairs.end(), p, comparePairs);
        pairs.insert(it, p);
    }
    if (iss.fail() && !iss.eof()) throw std::runtime_error("unexpected error while parsing");
    if (_debug) std::cout << DEBUG_TEXT_COLOR << "initial pairs: " << DEBUG_OBJECTS_COLOR << pairs << std::endl << RESET;
    return pairs;
}

std::deque<int> Pmerge::orderPairsDeque( std::deque< std::pair<int,int> >& pairs ) const
{
    int g_size = 2, pow = 4;
    std::deque<int> v;
    std::deque< std::pair<int,int> >::const_iterator border;

    for (std::deque< std::pair<int,int> >::const_iterator it = pairs.begin(); it < pairs.end(); )
    {
        border = it;
        it += g_size;
        if (it > pairs.end()) it = pairs.end();

        std::deque<int> temp;
        for(std::deque< std::pair<int,int> >::const_iterator i = border; i < it; ++i) temp.push_front(i->first);
        v.insert(v.end(), temp.begin(), temp.end());
        
        g_size = pow - g_size;
        pow *= 2;
    }
    if (_debug) std::cout << DEBUG_TEXT_COLOR << "Johnson-Ford ordered elements: " << DEBUG_OBJECTS_COLOR << v << std::endl << RESET;
    return v;
}

void Pmerge::mergeDeques(std::deque<int>& sorted, const std::deque<int>& arr) const
{
    int g_size = 2, pow = 4, q = 0;
    std::deque<int>::iterator bound;
    for (std::deque<int>::const_iterator it = arr.begin(); it != arr.end(); it++)
    {
        bound = std::min(sorted.begin() + pow, sorted.end());
        sorted.insert(std::lower_bound(sorted.begin(), bound, *it), *it);
        if (++q == g_size)
        {
            g_size = pow - g_size;
            pow *= 2;
            q = 0;
        }
        if (_debug) std::cout << DEBUG_TEXT_COLOR "inserted " << *it << ": " << DEBUG_OBJECTS_COLOR << sorted << std::endl << std::endl << RESET;
    }
}

std::deque<int> Pmerge::dequeSort() const
{
    std::deque<int> sorted, ordered;
    std::deque< std::pair<int,int> > pairs(getPairsDeque());

    if (pairs.size() == 0) return sorted;

    // creates the array of second elements + first pair's first element
    // deletes then the first pair from the pairs array because it is dealt with
    sorted.push_back(pairs[0].first);
    for (std::deque< std::pair<int,int> >::const_iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        sorted.push_back((*it).second);
    }
    pairs.erase(pairs.begin());

    if (_debug) std::cout << DEBUG_TEXT_COLOR << "new pairs: " << DEBUG_OBJECTS_COLOR << pairs << std::endl << RESET
        << DEBUG_TEXT_COLOR << "first-step sorted: " << DEBUG_OBJECTS_COLOR << sorted << std::endl << RESET;

    ordered = orderPairsDeque(pairs);

    mergeDeques(sorted, ordered);

    if (sorted[0] == -1) sorted.erase(sorted.begin());
    return sorted;
}