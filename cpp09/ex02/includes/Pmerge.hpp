/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:25:49 by lkrief            #+#    #+#             */
/*   Updated: 2023/09/06 11:57:11 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_HPP
# define PMERGE_HPP

#include <iostream>
#include <deque>
#include <vector>


 /********/
/* COLORS */
 /********/
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDWHITE   "\033[1m\033[37m"

#define DEBUG_TEXT_COLOR      MAGENTA
#define DEBUG_OBJECTS_COLOR   BOLDCYAN


 /********/
/* CLASS  */
 /********/
class Pmerge
{
    public:
        Pmerge( std::string& str );
        Pmerge( const Pmerge& src );
        ~Pmerge();

        std::vector<int> vectorSort();
        std::deque<int> dequeSort() const;

        std::string getInput() const;
        int getNbElements() const;
        std::vector<int> getSorted() const;

        void setDebug( const bool& debug );
        void setSorted( const std::vector<int>& sorted );

    private:
        std::string _input;
        int _nbElements;
        bool _debug;
        std::vector<int> _sorted;

        Pmerge( void );
        Pmerge& operator= ( const Pmerge& src );

        // general methods
        static bool comparePairs( const std::pair<int, int>& a, const std::pair<int, int>& b );
        static int checkNbElements( const std::string& str );

        // vector related methods
        std::vector< std::pair<int,int> > getPairsVector() const;
        std::vector<int> orderPairsVector( std::vector< std::pair<int,int> >& pairs ) const;
        void mergeVectors(std::vector<int>& sorted, const std::vector<int>& arr);
        
        // deque related methods
        std::deque< std::pair<int,int> > getPairsDeque() const;
        std::deque<int> orderPairsDeque( std::deque< std::pair<int,int> >& pairs ) const;
        void mergeDeques(std::deque<int>& sorted, const std::deque<int>& arr) const;
};

template <class T1, class T2>
std::ostream& operator<<(std::ostream& oss, const std::pair<T1, T2>& p) {
    oss << "{" << p.first << ", " << p.second << "}";
    return oss;
}

template <class T1>
std::ostream& operator<<(std::ostream& oss, const std::vector<T1>& v) {
    std::cout << "[";
    for (typename std::vector<T1>::const_iterator it = v.begin(); it != v.end();it++)
    {
        oss << " " << *it;
    }
    std::cout << " ]";
    return oss;
}

template <class T1>
std::ostream& operator<<(std::ostream& oss, const std::deque<T1>& v) {
    std::cout << "[";
    for (typename std::deque<T1>::const_iterator it = v.begin(); it != v.end();it++)
    {
        oss << " " << *it;
    }
    std::cout << " ]";
    return oss;
}

#endif
